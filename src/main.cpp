#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

char numere[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char taste_orig[29] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\n', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\n', ' ' ,'z', 'x', 'c', 'v', 'b', 'n', 'm' };
char taste[29] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\n', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\n', ' ' ,'z', 'x', 'c', 'v', 'b', 'n', 'm' };

int points = 0;

char selected_keys[100];

void reset_keys(){
    for(int i = 0; i<=29; i++) taste[i] = taste_orig[i];
    for(int i = 0; i<=29; i++) selected_keys[i] = ' ';
}

void random_keys(){
    for(int i = 0; i<=29; i++) selected_keys[i] = ' ';
    int b = 0;
    int a = rand() % 9 + 1;
    taste[a] = toupper(taste[a]);
    selected_keys[b++] = toupper(taste[a]);
}

void draw_keyboard(char numere[], char taste[]) {
    system("cls");
    for (int i = 0; i < 10; i++) {
        cout << numere[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < 29; i++) {
        cout << taste[i] << " ";
    }
    cout << endl << endl << "Points : " << points << endl;
}

void game(){
    char input;
    while(true){
        reset_keys();
        random_keys();
        draw_keyboard(numere, taste);
        chrono::steady_clock::time_point limit = chrono::steady_clock::now() + chrono::seconds(3);
        while(chrono::steady_clock::now() < limit){
            cout << "Input : ";
            cin >> input;
            if(chrono::steady_clock::now() > limit){
                cout << "Time limit exceeded!" << endl;
                _sleep(300);
                points--;
                break;
            }
            if(find(taste, taste + 29, toupper(input)) != taste + 29){
                cout << "Right! Added 2 points!" << endl;
                _sleep(300);
                points += 2;
                break;
            }
            else {
                cout << "Wrong answer! Removed 1 point!" << endl;
                _sleep(300);
                points--;
                break;
            }
        }
    }
}


int main(){
    game();
    return 0;
}