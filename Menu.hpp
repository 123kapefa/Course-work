#pragma once
#include "User.hpp"
#include "Library.h"

void menu1();
void menu2();
void menu3(vector <User> &users);
void globalMenu(vector <User> &users, int& ptr);


void loginMenu(int &ptr)
{   
    vector <User> users;
    inputUsersTXT(users, 2);
    for (int i = 0; i < users.size(); i++)
    {
        users[i].inputSpendingTXTU(i + 1);
    }

    while (ptr != 0)
    {
        system("cls");
        int menuSwitch1 = 3;
        int menuSwitch2 = 1;
        menu1();
        //void menu1()
        //{
        //    cout << "=============== ���� ===============\n";
        //    cout << "1 - ����\n";
        //    cout << "2 - ������� �������������\n";
        //    cout << "0 - �����\n";
        //}
        cin >> menuSwitch1;
        User ptruser;
        switch (menuSwitch1)
        {
            case 1:
                globalMenu(users, menuSwitch2);
                break;
            case 2:
                
                ptruser.createUser();
                users.push_back(ptruser);
                break;
            case 0:
                ptr = 0;
                break;
        }
    }
}


void globalMenu(vector <User> &users, int &ptr)
{
    while (ptr != 0)
    {   
        string ptrLogin;
        string ptrKey;
        bool pL = false;
        bool pK = false;
        system("cls");
        cout << "������� ������: ";
        cin >> ptrLogin;
        cout << "������� ������: ";
        cin >> ptrKey;
        for (int i = 0; i <= users.size(); i++)
        {
            if (users[i].getLogin() == ptrLogin)
            {
                if (users[i].getKey() == ptrKey)
                {
                    int menuSwitch3 = 7;
                    while (menuSwitch3 != 0)
                    {
                        system("cls");
                        cout << "=============== ���� ������ ===============\n";
                        users[i].outputUserDistlay();
                        int menuSwitch4 = 7;
                        menu2();
                        //void menu2()
                        //{
                        //    cout << "===========================================\n";
                        //    cout << "\t1 - ���������� ��� �����\n";
                        //    cout << "\t2 - ��������� �����\n";
                        //    cout << "\t3 - ������ �������\n";
                        //    cout << "\t4 - ������� �����\n";
                        //    cout << "\t5 - ������� �������\n";
                        //    cout << "\t6 - ���������\n";
                        //    cout << "\t0 - �����\n";
                        //    cout << "===========================================\n";
                        //}
                        cin >> menuSwitch4;
                        switch (menuSwitch4)
                        {
                        case 1:
                        {
                            system("cls");
                            users[i].showOutputDataCard();
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            int ptrCard = 0;
                            cout << "=============== ���� ����� ===============\n";
                            users[i].showOutputDataCard();
                            cout << "�������� ����� ��� ����������: ";
                            cin >> ptrCard;
                            ptrCard--;
                            if (ptrCard > users[i].getCountCard())
                            {
                                cout << "\n������������ �����!\n";
                                cout << "��������� �������!\n";
                                system("pause");
                            }
                            else
                            {
                                double sum;
                                cout << "������� ����� ����������: ";
                                cin >> sum;
                                users[i].refill(ptrCard, sum);
                            }
                            break;
                        }
                        case 3:
                        {
                            break;
                        }
                        case 4:
                        {
                            break;
                        }
                        case 5:
                        {
                            break;
                        }
                        case 6:
                        {
                            menu3(users);
                            break;
                        }
                        case 0:
                        {
                            menuSwitch3 = 0;
                            ptr = 0;
                            break;
                        }
                        }
                    }
                }
                else
                {
                    pK = true;
                }
            }
            else
            {
                pL = true;
            }
        }
        if (pL)
        {
            cout << "\n������������ �����.\n";
            cout << "��������� �������!\n";
            system("pause");
        }
        else if (pK)
        {
            cout << "\n������������ ������.\n";
            cout << "��������� �������!\n";
            system("pause");
        }

    }
}

void menu1()
{
    cout << "=============== ���� ===============\n";
    cout << "1 - ����\n";
    cout << "2 - ������� �������������\n";
    cout << "0 - �����\n";
}

void menu2()
{
    cout << "===========================================\n";
    cout << "\t1 - ���������� ��� �����\n";
    cout << "\t2 - ��������� �����\n";
    cout << "\t3 - ������ �������\n";
    cout << "\t4 - ������� �����\n";
    cout << "\t5 - ������� �������\n";
    cout << "\t6 - ���������\n";
    cout << "\t0 - �����\n";
    cout << "===========================================\n";
}

void menu3(vector <User> &users)
{
    int menuSwitch5 = 0;
    system("cls");
    cout << "===========================================\n";
    cout << "\t1 - ������� ����� �����\n";
    cout << "\t2 - ������� ��� �����\n";
    cout << "\t3 - ������� ���� �������� �����\n";
    cout << "\t4 - ������� CVC ���\n";
    cout << "\t0 - �����\n";
    cout << "===========================================\n";
    cin >> menuSwitch5;
    users[users.size()].cardSettings(menuSwitch5);
}
