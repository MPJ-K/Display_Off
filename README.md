# Display Off

## Description

Display Off is a simple tool for Windows that allows users to manually turn off the display without putting the computer to sleep. Running the executable will start a five-second countdown, after which the display will turn off. Pressing any key or moving the mouse will turn the display back on.

The countdown time can be adjusted by passing an integer to the executable as the first argument. For example:

```
> Display_Off.exe 10
```

will result in a ten-second countdown. If the provided value is negative or not a number, the countdown will default to five seconds.

## Background

This tool was created to avoid an issue where my monitor disconnects when powered off, causing all my windows to move around. Rather than powering off my monitor, I use Display Off to manually turn off the display, allowing the monitor to enter power-saving mode without disconnecting.

I am uploading Display Off here in hopes that others may find it useful. Please keep in mind that I am by no means an experienced C++ developer. Display Off was created with the help of AI and compiled using MSVC (`cl.exe`).
