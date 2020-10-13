#include <iostream>
#include "include/Screen.h"
#include "include/Agent.h"
#define _WIN32_WINNT 0x0601


using namespace std;

int main()
{
    Screen screen;
    screen.ScreenColour();                                    //give green color to the text

    while(true) {

        screen.PrintLogo();

        if (!screen.LoginPage()) {                            // Game loop : Run till user enter exit
            screen.Processing("Exiting");
            break;
        }

        char name[50];int i;
        for (i = 0; i < screen.username.length(); ++i) {      // copy string to char
            name[i] = screen.username[i];
        }
        name[i] = '\0';


        Agent agent(name);
        screen.ChangeFont(5);                                 // change font to 5
        agent.MainMenu();                                     // open main menu for the agent

        system("CLS");


    }
    return 1;
}
