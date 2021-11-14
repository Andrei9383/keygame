#include <iostream>
#include <stdlib.h>
#include <conio.h>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif // Windows/Linux

#include <thread>

using namespace std;

char numere[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char taste[29] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\n', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\n', ' ' ,'z', 'x', 'c', 'v', 'b', 'n', 'm' };
char pressed;


void draw_keyboard(char numere[], char taste[]) {
    system("cls");
    for (int i = 0; i < 10; i++) {
        cout << numere[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < 29; i++) {
        cout << taste[i] << " ";
    }
}

void get_console_size(int& width, int& height) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    height = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
#elif defined(__linux__)
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int)(w.ws_col);
    height = (int)(w.ws_row);
#endif // Windows/Linux
}

void print_main_menu() {
    int w, h;
    get_console_size(w, h);
    cout << R"(
 _    _   _____   _       _____   _____   __  __   _____ 
| |  | | |  ___| | |     /  __ \ |  _  | |  \/  | |  ___|
| |  | | | |__   | |     | /  \/ | | | | | .  . | | |__  
| |/\| | |  __|  | |     | |     | | | | | |\/| | |  __| 
\  /\  / | |___  | |____ | \__/\ \ \_/ / | |  | | | |___ 
 \/  \/  \____/  \_____/  \____/  \___/  \_|  |_/ \____/)" << '\n';
    cout << R"(
 _____   _____
|_   _| |  _  |
  | |   | | | |
  | |   | | | |
  | |   \ \_/ /
  \_/    \___/

    )" << '\n';
    system("Color E0");
    cout << R"(
 _   __  _____  __   __  _____    ___    __  __   _____
| | / / |  ___| \ \ / / |  __ \  / _ \  |  \/  | |  ___|
| |/ /  | |__    \ V /  | |  \/ / /_\ \ | .  . | | |__
|    \  |  __|    \ /   | | __  |  _  | | |\/| | |  __|
| |\  \ | |___    | |   | |_\ \ | | | | | |  | | | |___
\_| \_/ \____/    \_/    \____/ \_| |_/ \_|  |_/ \____/  

    )" << '\n';
    system("Color 0A");
    cout << "Press Up to continue..." << endl << "Press Left to show the tutorial..." << endl << "Press Right to begin..." << endl << "Press Down to exit...";
}

void get_key_press() {
    char key = 127;
    while (true) {
        key = _getch();
        pressed = key;
        if (key == 0 || key == -32) {
            //get a special key
            key = _getch();
            if (key == 72) {
                pressed = 'u';
                //up arrow
            }
            else if (key == 75) {
                pressed = 'l';
                //left arrow
            }
            else if (key == 77) {
                pressed = 'r';
                //right
            }
            else if (key == 80) {
                pressed = 'd';
                //down
            }
        }
    }
}

void main_menu() {
    switch (pressed) {
    case 'u':
        system("cls");
        cout << "up";
        pressed = ' ';
        break;
    case 'd':
        system("cls");
        cout << "down";
        pressed = ' ';
        break;
    case 'l':
        system("cls");
        cout << "Left";
        pressed = ' ';
        break;
    case 'r':
        system("cls");
        cout << "right";
        pressed = ' ';
        break;
    case 'f':
        system("cls");
        cout << "f";
        break;
    }
}

//TODO : implement the game lol
//TODO : implement a high score method
//TODO : implement a first time start up menu
//TODO : implemnt different themes
//TODO : implement menu options

int main() {
    thread handle_keys(get_key_press);
    print_main_menu();
    while (true) {
        main_menu();
    }
    return 0;
}