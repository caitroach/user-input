# user-input
This is a small C program exploring X11 input event handling and event loop mechanics on Linux. I did this as a learning exercise to understand how desktop environments can deliver low-level inputs like keystrokes to applications.

# disclaimer 
This is not capable of sending user data anywhere else. This is a very basic (and inefficient) example. The program stops if the user restarts their computer or presses CTRL+C. Keystrokes are saved to a local `.txt` file. This program: 
- Does NOT capture input outside of X11
- Does NOT send data anywhere
- Stops immediately when closed or rebooted
- Is purely educational to understand event loops and X11

This project is for educational use on your OWN SYSTEM because it literally cannot do anything else.

# how to run on Plasma
1. Plasma runs on Wayland (way better security) by default. For the purpose of this demo, run X11 with `sudo dnf install plasma-workspace-x11`.
2. Compile the program with `gcc input.c -lX11 -o input`
3. Reboot your computer with `reboot`.
4. Choose the `Plasma (X11)` option from the dropdown login menu.
5. In the same folder and directory as your `keylog.c` file, create a file named `input.txt`.
6. Run `keylog.c` by navigating to your directory in the terminal and running `./input.`. 
