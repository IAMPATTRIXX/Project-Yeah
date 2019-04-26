#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;
struct Date
{
    int month, day, year;
};

struct Bank
{
    float deposit;
    string inf;
    vector<string> recinfor;
    vector<int> m;
    vector<int> d;
    vector<int> y;
    vector<float> depo;
    int input;
    float sum;
    int in;
};
void firstmenu()
{
    cout << "**********************************"
         << "\n";
    cout << "MAIN MENU"
         << "\n";
    cout << "\n";
    cout << "DEPOSIT MENU [1]"
         << "\n";
    cout << "INTEREST MENU [2]"
         << "\n";
    cout << "EXIT [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}

void depositfirstmenu()
{
    cout << "**********************************"
         << "\n";
    cout << "DEPOSIT MENU"
         << "\n"
         << "\n";

    cout << "DEPOSIT,WITHDRAW [1]"
         << "\n";
    cout << "SEARCHING [2]"
         << "\n";
    cout << "BACK [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}
void interestfirstmenu()
{
    cout << "**********************************"
         << "\n";

    cout << "INTEREST MENU"
         << "\n"
         << "\n";
    cout << "ALL MONEY IN YOUR BANK [1]"
         << "\n";
    cout << "INTEREST[2]"
         << "\n";
    cout << "BACK [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}

int findingnemo(string x, vector<string> y)
{
    int t[20];
    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            t[i] = i;
        }

        else
            t[0] = 0;
    }
    return t[0];
}
int findingnemoint(int x, vector<int> y)
{
    int t[20];
    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            t[i] = i;
        }

        else
            t[0] = 0;
    }
    return t[0];
}
int findingnemodeposit(float x, vector<float> y)
{
    int t[20];
    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            t[i] = i;
        }

        else
            t[0] = 0;
    }
    return t[0];
}
int searchingfrominf(vector<string> inf)
{
    string searching;
    cout << "Input information of deposit: ";
    getline(cin, searching);
    for (int i = 0; i < searching.size(); i++)
    {
        searching[i] = toupper(searching[i]);
    }
    return findingnemo(searching, inf);
}
int searchingfromdate(vector<int> day)
{
    int searching;
    cout << "input day of deposit: ";
    cin >> searching;
    return findingnemoint(searching, day);
}
int searchingfromdeposit(vector<float> deposit)
{
    float searching;
    cout << "Input amount of deposit: ";
    cin >> searching;
    return findingnemodeposit(searching, deposit);
}

int menufindingdeposit()
{
    int choice;
    cout << "Do you want to find something";

    cout << "Find from inf ?  [1]"
         << "\n";

    cout << "Find from date ? [2]"
         << "\n";

    cout << "Find from deposit ? [3]"
         << "\n";

    cout << "INPUT : ";
    cin >> choice;
    cin.ignore();
    return choice;
}
int menufidingwithdraw()
{
    int choice;
    cout << "Do you want to find something";

    cout << "Find from inf ?  [1]"
         << "\n";

    cout << "Find from date ? [2]"
         << "\n";

    cout << "Find from deposit ? [3]"
         << "\n";

    cout << "INPUT : ";
    cin >> choice;
    cin.ignore();
    return choice;
}
void allmoneywithinterested(float x)
{
    float interest;
    cout << "You interest rate is : ";
    cin >> interest;
    cout << "Your interest is : " << (interest * x) / 100 << "\n";
    cout << "Your all money is : " << x + (interest * x) / 100 << "\n";
}

int main()
{
    int finding;
    float sum = 0;
    int tariff;
    int dom;
    Date rec;
    Bank information;
    Bank searching;
    Bank menu;
    Bank withdraw;
    Bank create;
    Bank use;
    firstmenu();
    cin >> create.input;
    while (create.input != 0)
    {
        if (create.input == 1)
        {
            depositfirstmenu();
            cin >> use.input;
            if (use.input == 1)
            {
                cout << "INPUT 00 00 0000 in date to stop"
                     << "\n";
                while (true)
                {

                    cout << "Date of Record mm dd yyyy: ";
                    cin >> rec.month;
                    if (rec.month == 00 or rec.day == 00 or rec.year == 0000)
                    {
                        break;
                    }
                    cin >> rec.day >> rec.year;
                    cin.ignore();
                    cout << "\n"
                         << "information : ";
                    getline(cin, information.inf);

                    for (int i = 0; i < information.inf.size(); i++)
                    {
                        information.inf[i] = toupper(information.inf[i]);
                    }

                    cout
                        << "Amount of deposit (Baht): ";
                    cin >> information.deposit;
                    cin.ignore();
                    cout << "****************************"
                         << "\n"
                         << "Deposit[1] or Withdraw[2]"
                         << "\n"
                         << "****************************"
                         << "\n";
                    cin >> menu.input;
                    cin.ignore();

                    if (menu.input == 1)
                    {

                        cout << "\n";
                        information.recinfor.push_back(information.inf);
                        information.m.push_back(rec.month);
                        information.d.push_back(rec.day);
                        information.y.push_back(rec.year);
                        information.depo.push_back(information.deposit);
                        cout << "You deposit  " << information.deposit << " baht"
                             << "\n";
                        sum += information.deposit;
                    }
                    if (menu.input == 2)
                    {
                        cout << "\n";
                        withdraw.recinfor.push_back(information.inf);
                        withdraw.m.push_back(rec.month);
                        withdraw.d.push_back(rec.day);
                        withdraw.y.push_back(rec.year);
                        withdraw.depo.push_back(information.deposit);
                        sum -= information.deposit;
                        cout << "You withdraw  " << information.deposit << " baht"
                             << "\n";
                    }
                }
            }
            else if (use.input == 2)
            {
                int choice;

                cout << "Are you want to find the information"
                     << "\n"
                     << " [Yes input 0][No input 1]"
                     << "\n";
                cin >> information.input;
                if (information.input == 0)
                {

                    cout << " Find deposit  information [1]"
                         << "\n";
                    cout << " Find Withdraw information [2]"
                         << "\n";

                    cout << "INPUT : ";
                    cin >> finding;
                }
                else if (information.input == 1)
                {
                    firstmenu();
                }

                if (finding == 1)
                {
                    choice = menufindingdeposit();

                    if (choice == 1)
                    {

                        tariff = searchingfrominf(withdraw.recinfor);
                       /*  if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                        
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht"<<"\n";
                    }

                    else if (choice == 2)
                    {
                        tariff = searchingfromdate(information.d);
                        /* if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht"<<"\n";
                    }
                    else if (choice == 3)
                    {
                        tariff = searchingfromdeposit(information.depo);
                       /*  if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht"<<"\n";
                    }
                }
                if (finding == 2)
                {
                    choice = menufidingwithdraw();

                    if (choice == 1)
                    {
                        tariff = searchingfrominf(withdraw.recinfor);
                       /*  if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                     
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht"<<"\n";
                    }

                    else if (choice == 2)
                    {
                        tariff = searchingfromdate(withdraw.d);
                      /*   if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                    
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht"<<"\n";
                    }
                    else if (choice == 3)
                    {
            
                        tariff = searchingfromdeposit(withdraw.depo);
                        /* if (tariff == 0)
                        {
                            cout << "Not found !";
                        } */
                     
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht"<<"\n";
                    }
                }
            }
        }
        else if (create.input == 2)
        {
            interestfirstmenu();
            cin >> menu.in;
            if (menu.in == 1)
            {
                cout << "Your all money in bank now is : " << sum << "\n";
            }
            else if (menu.in == 2)
            {
                allmoneywithinterested(sum);
            }
        }
        cin.ignore();
        firstmenu();
        cin >> create.input;
    }

    return 0;
}
