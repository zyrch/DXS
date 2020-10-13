#ifndef AGENT_H
#define AGENT_H
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Screen.h"
#define _WIN32_WINNT 0x0601

using namespace std;

class Agent
{
    public:
        Agent(char name[]);
        void MainMenu();
        void Missions();
        void DisplayMissions(int index);
        void DisplayProfiles();
        void Funds();
        void Navigate(int &index, char &cw, int x);
        void CMission();
        void strdis(string para);

    private:
        string name;
        char *filename;
        int Mission;
        int AliasUsed;
        string MissionNames[5] = {"ARTICHOKE", "OPERATION MOMENTUM", "OPERATION CHAOS", "PROJECT DARK GENE", "JMWAVE"};
        string Messages[3];
        string Alias[5][2];

};

#endif // AGENT_H
