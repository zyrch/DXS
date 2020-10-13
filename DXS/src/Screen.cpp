#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Screen.h"
#include <cwchar>
#define _WIN32_WINNT 0x0601

typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
//the function declaration ends

using namespace std;


void Screen::Delay(int x) {

    for(int i = 0; i < 1000; ++i) {
        for (int j = 0; j < x; ++j);
    }

}
void Screen::Processing(string text){

    /*
    the changing of sign from \ to | to / give the effect that the cursor is moving
    */

    system("CLS");

    ChangeFont(10);

    int i = 0;


    while (i < 5) {

        Delay(10000);
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t" << text << flush;

        cout << "/" << flush;

        Delay(10000);
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t" << text << flush;

        cout << "|" << flush;

        Delay(10000);
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t" << text << flush;

        cout << "\\" << flush;

        ++i;
    }

    system("CLS");
    ChangeFont(0);

}
void Screen::ChangeFont(int x) {     //change font of console


    int
    newWidth=8+x,
    newHeight=16+x;
    CONSOLE_FONT_INFOEX fontStructure={0};
    fontStructure.cbSize=sizeof(fontStructure);
    fontStructure.dwFontSize.X=newWidth;
    fontStructure.dwFontSize.Y=newHeight;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, true, &fontStructure);

}

void Screen::GetPassword(){

    char ch;

    while ((ch = _getch()) != '\r') {                           // using _getch does not display the input character

    // put it onto the back of the password
    password.push_back(ch);
    // output a '*' character
    _putch('x');

    }

}

void Screen::ScreenColour(){

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);          // system give green color to window's handle

}

void Screen::PrintLogo(){

    ChangeFont(5);                                              // increase the width and length of font by 5

    cout << endl << endl << endl << endl << endl << endl;
    cout << "                        " << flush;
    for (int i = 0; i < 27; ++i) {cout <<  char(254) << " " << flush;}
    cout << endl ;
    cout << "                        " <<  char(254)   <<   "                                                   " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||||||||                 |||||||||||||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||     |||             ||||||               " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||       |||         ||| ||||               " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||        ||||     |||   ||||               " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||         ||||| |||     ||||               " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||         ||| |||       |||||||||||||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||         ||||| |||                ||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||        ||||     |||              ||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||       |||         |||            ||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||     |||             |||          ||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "     ||||||||||                 |||||||||||||||    " << char(254) << endl;
    cout << "                        " <<  char(254)   <<   "                                                   " << char(254) << endl;
    cout << "                        " << flush;
    for (int i = 0; i < 27; ++i) {cout <<  char(254) << " " << flush;}

}

bool Screen::LoginPage() {

    cout << endl << endl;
    cout << "                        " << "ENTER EXIT TO EXIT" << endl;

    cout << endl << "\n                               " << flush;

    cout << "USERNAME : " << flush;

    cin >> username;

    if (username == "exit" || username == "EXIT" || username == "Exit")
        return false;

    system("CLS");                                                         // clear the screen

    PrintLogo();

    cout << endl << "\n                               " << flush;

    cout << "PASSWORD : " << flush;

    GetPassword();                                                        //masks the password in form of xxxxxxxx

    system("CLS");

    if (!CheckLogin()) {
        AutoDestruct();
    }else {
        Processing("Signing In");                                         // display loading sign
    }

    return true;
}

bool Screen::CheckLogin(){

    ifstream fin;
    fin.open("login credentials.txt");                                   // A file containing Login Credentials

    char ch;
    string usr, pass;

    while(!fin.eof()) {


        fin >> ch;
        while (ch != '-') {
            usr.push_back(ch);                                           //
            fin >> ch;
        }

        fin >> ch;

        while (ch != '-') {
            pass.push_back(ch);
            fin >> ch;

        }

       if (usr == username && pass == password) return true;

       usr.clear();
       pass.clear();


    }

    fin.close();

    return false;

};

void Screen::AutoDestruct() {

    ChangeFont(30);
    cout << endl << endl << endl << endl << endl << endl << endl << "       Incorrect attempt   " << flush;
    Delay(400200);
    system("CLS");

    cout << endl << endl << endl << endl << endl << endl << endl << "      Auto Self Destruct   " << flush;
    Delay(400200);
    system("CLS");
    ChangeFont(50);

    for (int i = 5; i > 0; --i) {
        system("CLS");
        cout << endl << endl << endl << endl << endl << "        T - " << i << "\a";
        Delay(200200);                                             // Delay one Second
    }

    system("CLS");
    ChangeFont(0);

    exit(0);
};
