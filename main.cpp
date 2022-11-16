#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
int k = 1, l = 1;
int a_pos = 0;
int a_neg = 0;
int b_pos = 0;
int b_neg = 0;
int o_pos = 0;
int o_neg = 0;
int ab_pos = 0;
int ab_neg = 0;
class blood_bank
{
protected:
    string username;
    string password;
    string usn;
    long long int choice, p_age = 0, p_don = 0, p_num;
    char p_name[20];
    int DNR, ctr = 0;
    char r;       // r-rhesius
    char p_blood; // t-type
    char slash_dummy;
    int d;
    int m;
    int y;
    int tm;
    char don[100];

public:
    void menu();
    void admin();
    void admin_password();
    void admin_loggedin();

    void user();

    void addDonor();
    void delDonor();
    void seeList();

    void donate();
    void request();
    void admin_display_bloodpackets();
    void user_display_bloodpackets();
};

/*************************************************************************************************/
/******************************************** MAIN MENU ********************************************/
/*************************************************************************************************/

void blood_bank::menu()
{
    system("cls");
    int choice;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    std::cout << R"(
                                           ___
_______________ |\/|  /\  | |\ |     |\/| |__  |\ | |  | _______________
                |  | /~~\ | | \|     |  | |___ | \| \__/

)" << '\n';

    cout << "\n\n\t\t\t 1. ADMIN";
    cout << "\n\t\t\t 2. USER";
    cout << "\n\t\t\t 3. EXIT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        admin();
        break;
    case 2:
        user();
        break;
    case 3:
        system("cls");
        Sleep(5);
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice :(";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        menu();
    }
}

/*************************************************************************************************/
/******************************************** ADMIN MENU ********************************************/
/*************************************************************************************************/

void blood_bank::admin_password()
{
    system("cls");
    char a_name[20];
    char a_password[20];
    int ch, i = 0;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    std::cout << R"(
                     __                        __   __                        
_______________ /\  |  \  |\/| | |\ |    |    /  \ / _` | |\ | _______________
               /~~\ |__/  |  | | | \|    |___ \__/ \__> | | \|                
                                                

)" << '\n';
    cout << "\n\n\t\t\tEnter Your Name: ";
    cin >> a_name;
    cout << "\n\t\t\tEnter Your Password: ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        a_password[i] = ch;
        i++;
    }
    a_password[i] = '\0';
    srand(time(0));
    if ((strcmp(a_name, "kaustub") == 0) && (strcmp(a_password, "1234") == 0))
    {
        cout << "\n\n\n\n";
        cout << "\t\t\tVerfiying ADMIN :";
        char x = 219;
        for (int i = 0; i < 50; i++)
        {
            cout << x;
            Sleep(10);
        }
        cout << "\n\nAccess Granted..\n\n";
        system("PAUSE");
        system("cls");
    }
    else
    {
        cout << "\n\n\n\n";
        cout << "Verfiying ADMIN :";
        char x = 219;
        for (int i = 0; i < 50; i++)
        {
            cout << x;
            Sleep(10);
        }
        cout << "\n\nAccess Aborted...\n\n";
        system("PAUSE");
        system("cls");
        menu();
    }
}

void blood_bank::admin()
{

    admin_password();
C:
    system("cls");
    int admin_choice;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';
    // MAIN MENU
    std::cout << R"(
                      __                         ___
_______________  /\  |  \  |\/| | |\ |     |\/| |__  |\ | |  | _______________
                /~~\ |__/  |  | | | \|     |  | |___ | \| \__/

)" << '\n';

    cout << "\n\n\t\t\t 1. ADD DONOR";
    cout << "\n\t\t\t 2. DELETE DONOR";
    cout << "\n\t\t\t 3. DISPLAY DONOR LIST";
    cout << "\n\t\t\t 4. DISPLAY AVAILABLE BLOOD-PACKETS";
    cout << "\n\t\t\t 5. LOG OUT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> admin_choice;
    switch (admin_choice)
    {
    case 1:
        addDonor();
        break;
    case 2:
        delDonor();
        break;
    case 3:
        seeList();
        break;
    case 4:
        admin_display_bloodpackets();
        break;
    case 5:
        menu();
        break;
    default:
        goto C;
        break;
    }
}
void blood_bank::admin_loggedin()
{
    system("cls");
    int admin_choice;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';
    // MAIN MENU
    std::cout << R"(
                      __                         ___
_______________  /\  |  \  |\/| | |\ |     |\/| |__  |\ | |  | _______________
                /~~\ |__/  |  | | | \|     |  | |___ | \| \__/

)" << '\n';

    cout << "\n\n\t\t\t 1. ADD DONOR";
    cout << "\n\t\t\t 2. DELETE DONOR";
    cout << "\n\t\t\t 3. DISPLAY DONOR LIST";
    cout << "\n\t\t\t 4. DISPLAY AVAILABLE BLOOD-PACKETS";
    cout << "\n\t\t\t 5. LOG OUT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> admin_choice;
    switch (admin_choice)
    {
    case 1:
        addDonor();
        break;
    case 2:
        delDonor();
        break;
    case 3:
        seeList();
        break;
    case 4:
        admin_display_bloodpackets();
        break;
    case 5:
        menu();
    default:
        admin_loggedin();
        break;
    }
}

void blood_bank::addDonor()
{
R:
    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    char str[2];
    int ch;

    cout << "\n\n\t\t\t 1. ADD DONOR";
    cout << "\n\t\t\t 2. EXIT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter Your Name :";
        cin.ignore();
        cin.getline(p_name, 20);

        cout << "Enter Your Age :";
        cin >> p_age;

        if (p_age >= 18)
        {

            while (1)
            {
                cout << "Enter type:";
                cin >> str;
                if (strcmp(str, "AB") == 0 || strcmp(str, "ab") == 0)
                {
                    p_blood = 'x';
                    break;
                }
                else if (strcmp(str, "A") == 0 || strcmp(str, "B") == 0 || strcmp(str, "O") == 0 || strcmp(str, "a") == 0 || strcmp(str, "b") == 0 || strcmp(str, "o") == 0)
                {
                    p_blood = str[0];
                    break;
                }
                else
                {
                    cout << "\nInvalid Type!";
                }
            }
            while (1)
            {
                cout << "Enter Rhesus(+/-):";
                cin >> r;
                if (r == '+' || r == '-')
                    break;
                else
                {
                    cout << "\nInvalid rhesus(+/-)\n";
                }
            }

            cout << "Enter Your No. of Blood Donation Until Now :";
            cin >> p_don;
            if (p_don != 0)
            {
                cout << "Enter Last Date you Donated :";
                cin.ignore();
                cin >> d >> slash_dummy >> m >> slash_dummy >> y;
                // time_t ttime = time(0);
                // tm *local_time = localtime(&ttime);
                // if (((1 + local_time->tm_mon) - m) < 3)
                //     cout << "You are not allowed to donate if already donated in last 3 months";
                // else
                // {
                cout << "Enter Phone Number :";
                cin >> p_num;

                DNR = l;
                cout << "Your DNR is: " << DNR << endl;
                ofstream out("data.txt", ios::app);
                out << DNR << " ";
                out << p_name << " ";
                out << p_age << " ";
                out << p_blood << " ";
                out << r << " ";
                out << p_num << " ";
                out << p_don << endl;
                out.close();
                // }
            }
            else if (p_don == 0)
            {
                cout << "Enter Phone Number :";
                cin >> p_num;

                DNR = l;
                cout << "Your DNR is: " << DNR << endl;
                ofstream out("data.txt", ios::app);
                out << DNR << " ";
                out << p_name << " ";
                out << p_age << " ";
                out << p_blood << " ";
                out << r << " ";
                out << p_num << " ";
                out << "0" << endl;
                out.close();
            }
            l = l + 1;
        }
        else
            cout << "\nIneligible\n";
        system("PAUSE");
        system("cls");
        addDonor();
        break;
    case 2:
        admin_loggedin();
        break;
    default:
        cout << "Enter valid input";
        addDonor();
    }
}

void blood_bank::delDonor()
{
    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    fstream read_file;
    vector<string> lines;
    string line;
    ofstream write_file;

    cout << "\n\n\t\t\t 1. DELTETE DONOR";
    cout << "\n\t\t\t 2. EXIT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:

        int line_number;

        cout << "Enter Donor Id to be deleted: ";
        cin >> line_number;

        read_file.open("data.txt");

        if (read_file.fail())
        {
            cout << "Error opening file." << endl;
            break;
        }

        while (getline(read_file, line))
            lines.push_back(line);

        read_file.close();

        if (line_number > lines.size())
        {
            cout << "Line " << line_number;
            cout << " not in file." << endl;

            cout << "File has " << lines.size();
            cout << " lines." << endl;
            delDonor();
            break;
        }

        write_file.open("data.txt");

        if (write_file.fail())
        {
            cout << "Error opening file." << endl;
            break;
        }
        line_number--;

        for (int i = 0; i < lines.size(); i++)
            if (i != line_number)
                write_file << lines[i] << endl;

        write_file.close();

        delDonor();
        break;
    case 2:
        admin_loggedin();
        break;
    default:
        cout << "Enter valid input";
        delDonor();
    }
}

void blood_bank::seeList()
{
    system("cls");
    int choice;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';
    ifstream myfile;
    string line;

    myfile.open("data.txt");

    while (!myfile.eof())
    {
        getline(myfile, line);
        cout << line << endl;
    }
    myfile.close();
    Sleep(1000);
    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
    getch();
    menu();
}
/*************************************************************************************************/
/******************************************* USER MENU *******************************************/
/*************************************************************************************************/

void blood_bank::user()
{
D:
    system("cls");
    int user_choice;
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';
    // MAIN MENU
    std::cout << R"(
                      __   ___  __            ___                           
_______________ |  | /__` |__  |__)     |\/| |__  |\ | |  | _______________ 
                \__/ .__/ |___ |  \     |  | |___ | \| \__/                 
                                            

)" << '\n';

    cout << "\n\n\t\t\t 1. DONATE";
    cout << "\n\t\t\t 2. REQUEST";
    cout << "\n\t\t\t 3. DISPLAY DONOR LIST";
    cout << "\n\t\t\t 4. DISPLAY AVAILABLE BLOOD-PACKETS";
    cout << "\n\t\t\t 5. LOG OUT";
    cout << "\n\n\t\t\tEnter Choice: ";
    cin >> user_choice;
    switch (user_choice)
    {
    case 1:
        donate();
        break;
    case 2:
        request();
        break;
    case 3:
        seeList();
        break;
    case 4:
        user_display_bloodpackets();
        break;
    case 5:
        menu();
        break;
    default:
        goto D;
        break;
    }
}

void blood_bank::donate()
{

    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    char str[2];
    char str2[2];
    cout << "Enter Your ID :";
    cin >> DNR;
    while (1)
    {
        cout << "Enter type:";
        cin >> str;
        if (strcmp(str, "AB") == 0 || strcmp(str, "ab") == 0)
        {
            p_blood = 'x';
            break;
        }
        else if (strcmp(str, "A") == 0 || strcmp(str, "B") == 0 || strcmp(str, "O") == 0 || strcmp(str, "a") == 0 || strcmp(str, "b") == 0 || strcmp(str, "o") == 0)
        {
            p_blood = str[0];
            break;
        }
        else
        {
            cout << "\nInvalid Type!";
        }
    }
    while (1)
    {
        cout << "Enter Rhesus(+/-):";
        cin >> str2;
        if (strcmp(str2, "+") == 0 || strcmp(str2, "-") == 0)
            break;
        else
        {
            cout << "\nInvalid rhesus(+/-)\n";
        }
    }

    if ((strcmp(str, "A") == 0) || (strcmp(str, "a") == 0))
    {
        if (strcmp(str2, "+") == 0)
            a_pos++;
        else
            a_neg++;
    }
    else if ((strcmp(str, "B") == 0) || (strcmp(str, "b") == 0))
    {
        if (strcmp(str2, "+") == 0)
            b_pos++;
        else
            b_neg++;
    }
    else if ((strcmp(str, "O") == 0) || (strcmp(str, "o") == 0))
    {
        if (strcmp(str2, "+") == 0)
            o_pos++;
        else
            o_neg++;
    }
    else if ((strcmp(str, "AB") == 0) || (strcmp(str, "ab") == 0))
    {
        if (strcmp(str2, "+") == 0)
            ab_pos++;
        else
            ab_neg++;
    }
    else
        cout << "Error";

    Sleep(1000);
    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
    getch();
    user();
}

void blood_bank::request()
{
    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';
Z:
    char str[2];
    char str2[2];

    cout << "Enter Your Name :";
    cin.ignore();
    cin.getline(p_name, 20);
    cout << "Enter Phone Number :";
    cin >> p_num;
    while (1)
    {
        cout << "Enter type:";
        cin >> str;
        if (strcmp(str, "AB") == 0 || strcmp(str, "ab") == 0)
        {
            p_blood = 'x';
            break;
        }
        else if (strcmp(str, "A") == 0 || strcmp(str, "B") == 0 || strcmp(str, "O") == 0 || strcmp(str, "a") == 0 || strcmp(str, "b") == 0 || strcmp(str, "o") == 0)
        {
            p_blood = str[0];
            break;
        }
        else
        {
            cout << "\nInvalid Type!";
        }
    }
    while (1)
    {
        cout << "Enter Rhesus(+/-):";
        cin >> str2;
        if (strcmp(str2, "+") == 0 || strcmp(str2, "-") == 0)
            break;
        else
        {
            cout << "\nInvalid rhesus(+/-)\n";
        }
    }

    if ((strcmp(str, "A") == 0) || (strcmp(str, "a") == 0))
    {
        if (strcmp(str2, "+") == 0)
            if(a_pos>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
        else
            if(a_neg>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
    }
    else if ((strcmp(str, "B") == 0) || (strcmp(str, "b") == 0))
    {
        if (strcmp(str2, "+") == 0)
            if(b_pos>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
        else
            if(b_neg>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
    }
    else if ((strcmp(str, "O") == 0) || (strcmp(str, "o") == 0))
    {
        if (strcmp(str2, "+") == 0)
            if(o_pos>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
        else
            if(o_neg>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
    }
    else if ((strcmp(str, "AB") == 0) || (strcmp(str, "ab") == 0))
    {
        if (strcmp(str2, "+") == 0)
            if(ab_pos>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
        else
            if(ab_neg>=1)
            std::cout << R"(
,-----.  ,--.                 ,--.      ,---.                  ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |     /  O  \,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  .-.  |\  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    |  | |  | \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'     `--' `--'  `--'   `--`--'`--'`--' `--`--' `---' `--' `----' 
)" << '\n';
            else
            std::cout << R"(
,-----.  ,--.                 ,--.    ,--. ,--.                                 ,--.,--.        ,--.   ,--.        
|  |) /_ |  | ,---.  ,---.  ,-|  |    |  | |  |,--,--,  ,--,--.,--.  ,--.,--,--.`--'|  | ,--,--.|  |-. |  | ,---.  
|  .-.  \|  || .-. || .-. |' .-. |    |  | |  ||      \' ,-.  | \  `'  /' ,-.  |,--.|  |' ,-.  || .-. '|  || .-. : 
|  '--' /|  |' '-' '' '-' '\ `-' |    '  '-'  '|  ||  |\ '-'  |  \    / \ '-'  ||  ||  |\ '-'  || `-' ||  |\   --. 
`------' `--' `---'  `---'  `---'      `-----' `--''--' `--`--'   `--'   `--`--'`--'`--' `--`--' `---' `--' `----'                                                                                                                
)" << '\n';
    }
    else
        cout << "Error";

    ofstream out("request.txt", ios::app);
    out << p_name << " ";
    out << str << " ";
    out << str2 << " ";
    out << p_num << " ";
    out.close();
    Sleep(1000);
    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
    getch();
    user();
}

void blood_bank::admin_display_bloodpackets()
{
    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    cout << "A+  :" << a_pos << endl;
    cout << "A-  :" << a_neg << endl;
    cout << "B+  :" << b_pos << endl;
    cout << "B-  :" << b_neg << endl;
    cout << "O+  :" << o_pos << endl;
    cout << "O-  :" << o_neg << endl;
    cout << "AB+ :" << ab_pos << endl;
    cout << "AB- :" << ab_neg << endl;
    Sleep(1000);
    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
    getch();
    admin_loggedin();
}

void blood_bank::user_display_bloodpackets()
{
    system("cls");
    std::cout << R"(
'||'''|,  '||`                   ||`    '||'''|,                   '||
 ||   ||   ||                    ||      ||   ||                    ||
 ||;;;;    ||  .|''|, .|''|, .|''||      ||;;;;    '''|.  `||''|,   || //`
 ||   ||   ||  ||  || ||  || ||  ||      ||   ||  .|''||   ||  ||   ||<<
.||...|'  .||. `|..|' `|..|' `|..||.    .||...|'  `|..||. .||  ||. .|| \\.
)" << '\n';

    cout << "A+  :" << a_pos << endl;
    cout << "A-  :" << a_neg << endl;
    cout << "B+  :" << b_pos << endl;
    cout << "B-  :" << b_neg << endl;
    cout << "O+  :" << o_pos << endl;
    cout << "O-  :" << o_neg << endl;
    cout << "AB+ :" << ab_pos << endl;
    cout << "AB- :" << ab_neg << endl;
    Sleep(1000);
    cout << "\n\n\t\t\tPRESS ANY KEY TO CONTINUE";
    getch();
    user();
}

int main()
{
    system("cls");
    system("color C");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\tLoading :";
    char x = 219;
    for (int i = 0; i < 50; i++)
    {
        cout << x;
        Sleep(10);
    }
    remove("data.txt");
    remove("request.txt");
    ofstream MyFile("data.txt");
    ofstream File("request.txt");
    blood_bank system;
    system.menu();
}
