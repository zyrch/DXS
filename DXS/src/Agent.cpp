#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <ctype.h>
#include "Screen.h"
#include <string.h>
#define _WIN32_WINNT 0x0601
#include "Agent.h"
using namespace std;

Agent::Agent(char name[])
{
    for (int i = 0; i < strlen(name); ++i) {
        this->name.push_back(name[i]);                            //copy char to name
    }

    char txt[] = ".txt";
    strcat(name, txt);                                            //add ".txt" to name
    ifstream fin;
    fin.open(name, ios::in);

    filename = name;
    fin >> Mission;
    fin >> AliasUsed;

    fin.close();
}

void Agent::MainMenu() {

    char c = 0; int index = 0; string menu[5] = {"MISSIONS", "CURRENT MISSION DETAILS", "PROFILES", "FUNDS", "LOGOUT"};

    while(c != '\r') {

        system("CLS");

        cout << endl << endl;

        cout << "                ";

        for (int i = 0; i < 66; ++i) {cout <<  char(206) << flush;}

        cout << endl;
        cout << "                " << char (206);
        cout << "                                                                " << char(206) << endl;
        cout << "                " << char (206) << " Name : " << name << flush;

        int spaces = 41 - name.length();

        for (int i = 0; i < spaces; ++i) {
            cout << " ";
        }

        cout << " MISSIONS : " << Mission << " " << char(206) << endl;
        cout << "                " << char (206);
        cout << "                                                                " << char(206) << endl;
        cout << "                " << char(206) << " IDENTITIES :" << AliasUsed;
        cout << "                                                 " << char(206) << endl;

        cout << "                " << char (206);
        cout << "                                                                " << char(206) << endl;

        cout << "                " ;
        for (int i = 0; i < 66; ++i) {cout <<  char(206) << flush;}


        cout << endl << endl;
        cout << "                 MAIN MENU:"  << endl << endl;


        //loop that changes bullets according to the value of index
        for (int i = 0; i < 5; ++i) {
            if (i == index) {cout << "                " << char(254) << " " << menu[i] << endl;}
            else cout << "                " << char(175) << " " << menu[i] << endl;
        }

        //controls the value of index
        Navigate(index,c, 5);
    }

    Screen screen;

    if (index == 0) {
        screen.Processing("Loading");
        Missions();
    }else if (index == 1) {
        screen.Processing("Loading");
        CMission();
    }else if(index == 2) {
        screen.Processing("Loading");
        DisplayProfiles();
    }else if(index == 3) {
        screen.Processing("Loading");
        Funds();
    }else if (index == 4) {
        Screen screen;
        screen.Processing("Logging Out");
    }
}


void Agent::Missions() {

    int index = 0;
    char c;

    while(c != '\r'){

        system("ClS");

        Screen screen;
        screen.ChangeFont(12);


        cout << endl << endl << endl << endl << endl << endl << "                 " ;
        for (int i = 0; i < 38; ++i) {cout <<  char(206) << flush;}

        cout << endl  << endl;
        cout << "                 MISSIONS :" << endl;


        //loop that changes bullets according to the value of index
        for (int i = 0; i < 5; ++i) {

            if (i == index) {
                    cout << "                 " << char(254) << " " << MissionNames[i] << endl;
            }

            else cout << "                 " << char(175) << " " << MissionNames[i] << endl;
        }

        cout << endl;
        cout << "                 " ;
        for (int i = 0; i < 38; ++i) {cout <<  char(206) << flush;}

        //controls the value of index
        Navigate(index, c, 5);
    }

    DisplayMissions(index);
}

void Agent::Navigate(int &index, char &c, int x) {
    x:
        c = _getch();

        // increase value of index according to up(w) and down(s) key
        if (c == 'W' || c == 'w') {
            index--;
        }else if (c == 'S' || c == 's') {
            index++;
        }

        if (index < 0) {
            index = 0;
            goto x;
        }else if (index > x - 1) {
            index = x - 1;
            goto x;
        }

}


void Agent::DisplayMissions(int index) {


    system("CLS");

    Screen screen;
    screen.ChangeFont(6);

    cout << endl << endl << endl << endl << endl << endl << "              " ;
    for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}

    cout << endl  << endl;
    cout << "              " << MissionNames[index] << " :" << endl;

    cout << endl;
    if (index == 0) {

        cout << "              " << "ARTICHOKE was a mind control program that gathered information "    << endl;
        cout << "              " << "together with the intelligence divisions of the Army, Navy, Air"    << endl;
        cout << "              " << "Force, and FBI. In addition, the scope of the project was outlined" << endl;
        cout << "              " << "in a memo dated January 1952 that stated, \"Can we get control"     << endl;
        cout << "              " << "of an individual to the point where he will do our bidding against" << endl;
        cout << "              " << "his will and even against fundamental laws of nature, such as "     << endl;
        cout << "              " << "self-preservation? \". Project Artichoke was the Department of External" << endl;
        cout << "              " << "Security's secret code name for carrying out in-house and overseas"   << endl;
        cout << "              " << "experiments using LSD, hypnosis, and total isolation as a form of"  << endl;
        cout << "              " << "physiological harassment for special interrogations on human "      << endl;
        cout << "              " << "subjects. The subjects who left this project were fogged with "     << endl;
        cout << "              " << "amnesia, resulting in faulty and vague memories of the experience." << endl;

    }else if (index == 1) {

        cout << "              " << "Operation Momentum was a guerrilla training program during the "      << endl;
        cout << "              " << "Laotian Civil War. This Department of External Security operation"    << endl;
        cout << "              " << "raising a guerrilla force of Hmong hill-tribesmen in northeastern"    << endl;
        cout << "              " << "Laos was planned by James William Lair and carried out by the Thai"   << endl;
        cout << "              " << "Police Aerial Reinforcement Unit. Begun on 17 January 1961, the"      << endl;
        cout << "              " << "three-day Auto Defense Choc (Self Defense Shock) course graduated a"  << endl;
        cout << "              " << "clandestine guerrilla army of 5,000 warriors by 1 May, and of 9,000"  << endl;
        cout << "              " << " by August. It scored its first success the day after the first ADC"  << endl;
        cout << "              " << "company graduated, on 21 January 1961, when 20 ADC troopers ambushed" << endl;
        cout << "              " << "killed 15 Pathet Lao."      << endl;
    }else if (index == 2){

        cout << "              " << "Operation CHAOS or Operation MHCHAOS was the code name (DXS cryptonym) "       << endl;
        cout << "              " << "of a United States Deparment of External Security domestic espionage project"      << endl;
        cout << "              " << "targeting the American people from 1967 to 1974, established by President"     << endl;
        cout << "              " << "Johnson and expanded under President Nixon, whose mission was to uncover"      << endl;
        cout << "              " << "possible foreign influence on domestic race, anti-war and other protest"       << endl;
        cout << "              " << "movements. The operation was launched under Director of Deparment of External" << endl;
        cout << "              " << "Security Richard Helms by chief of counter-intelligence James Jesus Angleton," << endl;
        cout << "              " << "and headed by Richard Ober. The \"MH\" designation is to signify the program"  << endl;
        cout << "              " << "had a worldwide area of operations"                                            << endl;

    }else if(index == 3) {

        cout << "              " << "Project Dark Gene was an aerial reconnaissance program run by the Department"    << endl;
        cout << "              " << "of External Security and Imperial Iranian Air Forcefrom bases inside Iran"        << endl;
        cout << "              " << "against the Soviet Union. The program was run in conjunction with Project"       << endl;
        cout << "              " << "Ibex, which was a more traditional ELINT mission. The first operations"          << endl;
        cout << "              " << "were during the 1960s with support of Iran's former Shah. Dedicated aircraft,"   << endl;
        cout << "              " << "air-bases, and U.S. personnel were stationed at numerous sites in Iran"          << endl;
        cout << "              " << "and would regularly fly across the border into the USSR through potential"       << endl;
        cout << "              " << "holes in their radar coverage. The intention of the program was to test"         << endl;
        cout << "              " << "the effectiveness of Soviet air defence and interception and resulted in"        << endl;
        cout << "              " << "one confirmed and possibly more combat losses in engagements with Soviet"        << endl;
        cout << "              " << "aircraft"                                                                        << endl;


    }else if (index == 4) {

        cout << "              " << "JMWAVE or JM/WAVE or JM WAVE was the codename for a major secret United"  << endl;
        cout << "              " << "States covert operations and intelligence gathering station operated by"  << endl;
        cout << "              " << "the DXS from 1961 until 1968. It was headquartered in Building"           << endl;
        cout << "              " << "25 25.6202"<< char(167) <<" N 80.3990"<< char(167) <<" W on the South Campus of the University of Miami in" << endl;
        cout << "              " << "Miami, Florida. (This location was formerly the site of Richmond Naval"   << endl;
        cout << "              " << "Air Station, an airship base about 12 miles south of the main campus"     << endl;
        cout << "              " << "after the airship base closed, it has been used by the University of"     << endl;
        cout << "              " << "Miami since 1948.) The intelligence facility was also referred to as"     << endl;
        cout << "              " << "the DXS's \"Miami Station\" or \"Wave Station\"."                         << endl;

    }
        cout << endl;
        cout << "              " << "PRESS ANY KEY TO GO TO MAIN MENU" << endl << endl;
        cout << "              " ;

    for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}

    getch();                                                      // waits for any input

    MainMenu();                                                   // Again lead to main menu

}


void Agent::DisplayProfiles() {

    system("CLS");

    Screen screen;
    screen.ChangeFont(6);

    cout << endl << endl << endl << endl << endl << endl << "              ";
    for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}

                                                                                                      cout << endl << endl;
    cout << "              " << "TERRORIST PROFILES:"                                                      << endl << endl;
    cout << "              " << "1. Abdul Rahman Yasin"                                                    << endl;
    cout << "              " << "   ->1993: World Trade Center bombing"                                    << endl;
    cout << "              " << "   ->Aliff was allegedly a prisoner of Saddam Hussein in 2003"            << endl;
    cout << "              " << "   ->Gone missing from Iraq."                                     << endl << endl;

    cout << "              " << "2. Ibrahim Salih Mohammed Al-Yacoub"                                      << endl;
    cout << "              " << "   ->Khobar Towers bombing"                                               << endl;
    cout << "              " << "   ->At large Wanted for Conspiracy to Kill U.S. Nationals"               << endl;
    cout << "              " << "   ->Conspiracy to Murder U.S. Employees"                         << endl << endl;


    cout << "              " << "3. Ayman al-Zawahiri"                                             << endl;
    cout << "              " << "   ->1998 United States embassy bombings"                                 << endl;
    cout << "              " << "   ->1998	At large Osama bin-Laden's successor as Al-Qaeda's cheftain"   << endl;
    cout << "              " << "   ->1998 U.S. embassy bombings in Dar es Salaam, Tanzania, and Nairobi," << endl;
    cout << "              " << "     Kenya"                                                       << endl << endl;

    cout << "              " << "PRESS ANY KEY TO GO TO MAIN MENU" << endl << endl;

    cout << "              " ;
    for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}
    getch();

    MainMenu();
}


void Agent::Funds() {

    system("CLS");

    Screen screen;
    screen.ChangeFont(6);

    fstream file;
    file.open(filename, ios::in);
    int balance;

    file.seekg(6, ios::beg);

    file >> balance;

    int index = 0; char ch;
    string menu[3] = {"WITHDRAW MONEY","ADD MONEY", "MAIN MENU"};

    while(ch != '\r') {

    x:
        system("ClS");
        screen.ChangeFont(6);

        cout << endl << endl << endl << endl << endl << endl << "              ";
        for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}
        cout << endl << endl;


        cout << "              " << "BALANCE : " << balance << endl;

        cout << endl << "              ";
        for (int i = 0; i < 67; ++i) {cout <<"-"<< flush;}

        cout << endl << endl;

        for (int i = 0; i < 3; ++i) {

            if (i == index) {
                    cout << "                 " << char(254) << " " << menu[i] << endl;
            }

            else cout << "                 " << char(175) << " " << menu[i] << endl;
        }

            cout << endl << endl << "              ";
        for (int i = 0; i < 67; ++i) {cout <<  char(206) << flush;}

        Navigate(index, ch, 3);

    }

    file.close();



    if (index == 0) {

        system("CLS");
        Screen screen;
        screen.ChangeFont(20);
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "    " << "Enter Amount : ";
        int amount;
        cin >> amount;

        if (amount > balance) {
            system("cls");
             screen.ChangeFont(20);
             cout << endl << endl << endl << endl << endl << endl << endl << endl;
             cout << "     Not Enough Money";
             getch();
             goto x;
        }

        balance -= amount;
        file.open(filename, ios::out);
        file << Mission << " " << AliasUsed << " ";
        file << balance;
        file.close();
        goto x;

    }else if (index == 1){

        system("CLS");
        Screen screen;
        screen.ChangeFont(20);
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "    " << "Enter Amount : ";
        int amount;
        cin >> amount;

        balance += amount;
        file.open(filename, ios::out);
        file << Mission << " " << AliasUsed << " ";
        file << balance;
        file.close();
        goto x;

    }else if (index == 2) {
        MainMenu();
    }

}

void Agent::CMission(){

    string para = "\tHello agent, this mission is issued\n"
                  "\tdirectly by the Director of Department\n"
                  "\tof External Affairs.\n";

    strdis(para);

           para = "\tA few weeks ago, a radio transmission from\n"
                  "\tIsrael to Afganisthan was intercepted. The\n"
                  "\tinterception revealed information about a";
    strdis(para);

           para = "\thuge undercover drug cartel network. The\n"
                  "\tname Mohammed Allahabeebi came up frequently\n"
                  "\tin this transmission. Our background check";

    strdis(para);

           para = "\tdid not come up with any conformation on \n"
                  "\tthe ID but we suspect that he is the handler \n"
                  "\tof this cartel.\n";

    strdis(para);

           para = "\tYour mission, should you choose to accept it";

    strdis(para);

           para = "\tis to infiltrate Mohammed Allahabeebi's head\n"
                  "\tquarters in Israel and bring him back alive\n";

    strdis(para);

           para = "\tThe location of your supplies will be given\n"
                  "\tto you later along with the required\n"
                  "\tcoordinates.\n";

    strdis(para);

           para = "\tYou may gather an extraction team of any 5\n"
                  "\tmembers of your choice.\n";

    strdis(para);

           para = "\tAs always, if any member of your team is\n"
                  "\tcaught or killed\n";

    strdis(para);

           para = "\tthe secretary will disavow any knowledge\n"
                  "\tof your actions";

    strdis(para);

           para = "\tGood luck.";

    strdis(para);

    getch();
}

void Agent::strdis(string para) {

    Screen screen;
    screen.ChangeFont(15);

    for (int i = 0; i < para.length(); ++i) {


        cout << endl << endl << endl << endl << endl << endl << endl;

        for (int j = 0; j < i; ++j) {
            cout << para[j];
        }
        screen.Delay(10000);
        system("cLs");
    }

}
