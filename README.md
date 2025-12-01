# user-input
A program that universally tracks user keyboard input on Linux Fedora PlasmaX11 and records it to a local .txt file; part of broader research on cybersecurity. 
concept from https://github.com/proxydom/keylogger/blob/main/keylogger_linux.c

# disclaimer 
This is not an actual keylogger and it is not capable of sending user data anywhere else. This is a very basic (and inefficient) example used to demonstrate the basic idea of keylogging. The program stops if the user restarts their computer or presses CTRL+C. Keystrokes are saved to a local `.txt` file. 

# how to run on Plasma
1. Plasma runs on Wayland (way better security) by default. For the purpose of this demo, run X11 with `sudo dnf install plasma-workspace-x11`. 
2. Reboot your computer with `reboot`.
3. Choose the `Plasma (X11)` option from the dropdown login menu.
4. In the same folder and directory as your `keylog.c` file, create a file named `key_log.txt`.
5. Run `keylog.c` by navigating to your directory in the terminal and running `.\keylog.c`. 
