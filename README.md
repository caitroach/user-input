# user-input
A small C program demonstrating basic X11 event handling on Linux. It records input events inside an X11 session (not Fedora's default), and only to a local text file. 

# disclaimer 
This is not an actual keylogger and it is not capable of sending user data anywhere else. This is a very basic (and inefficient) example used to demonstrate the basic idea of keylogging. The program stops if the user restarts their computer or presses CTRL+C. Keystrokes are saved to a local `.txt` file. This program: 
- Does not capture input outside of X11
- Does not send data anywhere
- Stops immediately when closed or rebooted
- Is purely educational to understand event loops and X11

# how to run on Plasma
1. Plasma runs on Wayland (way better security) by default. For the purpose of this demo, run X11 with `sudo dnf install plasma-workspace-x11`.
2. Compile the program with `gcc keylog.c -lX11 -o keylog`
3. Reboot your computer with `reboot`.
4. Choose the `Plasma (X11)` option from the dropdown login menu.
5. In the same folder and directory as your `keylog.c` file, create a file named `key_log.txt`.
6. Run `keylog.c` by navigating to your directory in the terminal and running `./keylog.`. 
