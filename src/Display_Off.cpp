#include <windows.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

int num_digits(int n) {
    int digits = 0;

    if (n <= 0) {
        n = -n;
        ++digits;
    }

    while (n) {
        n /= 10;
        ++digits;
    }

    return digits;
}

int main(int argc, char* argv[]) {
    // Parse wait time from the first argument. Defaults to 5 seconds if not provided.
    int wait_time = 5;

    if (argc > 1) {
        int value = std::atoi(argv[1]);
        if (value >= 0) { wait_time = value; }
    }

    // Wait the requested number of seconds before turning off the display.
    std::cout << std::left;
    std::cout << "Turning off the display in:" << std::endl;

    int digits = num_digits(wait_time);

    for (int i = wait_time; i > 0; --i) {
        std::cout << "\r" << std::setw(digits) << i << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "\r0!" << std::endl;

    // Turn off the display.
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);

    return 0;
}
