#ifndef SCREEN_H
#define SCREEN_H
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define _WIN32_WINNT 0x0601

using namespace std;

class Screen
{
    public:
        void ScreenColour();                                //changes the Color of screen to green
        void Processing(string text);                       //display loading text
        void Delay(int x);
        void ChangeFont(int x);                             //Change Font Size
        void GetPassword();                                 //To take input in the form of xxxxx
        void PrintLogo();                                   //Print DXS logo
        bool LoginPage();
        bool CheckLogin();                                  //Check if login credentials are correct
        void AutoDestruct();                                //In case of wrong login
        string username, password;

};

#endif // SCREEN_H
