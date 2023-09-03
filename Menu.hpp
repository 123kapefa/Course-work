#pragma once
#include "User.hpp"
#include "Library.h"

void menu1();
void menu2();
void menu3(vector <User>& users);
void globalMenu(vector <User>& users, int i, int& ptr);


void loginMenu(int& ptr)
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
		{
			bool userentryb = false;
			while (!userentryb)
			{
				string ptrLogin;
				string ptrKey;
				system("cls");
				cout << "������� ������: ";
				cin >> ptrLogin;
				cout << "������� ������: ";
				cin >> ptrKey;
				int userentry;
				for (int i = 0; i < users.size(); i++)
				{
					if (users[i].getLogin() == ptrLogin)
					{
						if (users[i].getKey() == ptrKey)
						{
							userentry = i;
							userentryb = true;
						}
						else
						{
							if (i + 1 == users.size())
							{
								cout << "\n������ ������������ �� ����������.\n";
								cout << "��������� �������!\n";
								system("pause");
							}
						}
					}
					else
					{
						if (i + 1 == users.size())
						{
							cout << "\n������ ������������ �� ����������.\n";
							cout << "��������� �������!\n";
							system("pause");
						}
					}
				}
				if (userentryb)
				{
					globalMenu(users, userentry, menuSwitch2);
				}
			}
			break;
		}
		case 2:

			ptruser.createUser(users.size());
			users.push_back(ptruser);
			break;
		case 0:
			ptr = 0;
			break;
		}
	}
}


void globalMenu(vector <User>& users, int i, int& ptr)
{
	while (ptr != 0)
	{
		int menuSwitch3 = 1;
		while (menuSwitch3 != 0)
		{
			system("cls");
			cout << "=============== ���� ������ ===============\n";
			users[i].outputUserDistlay();
			int menuSwitch4;
			menu2();
			/*cout << "===========================================\n";
			cout << "\t1 - ���������� ��� �����\n";
			cout << "\t2 - ��������� �����\n";
			cout << "\t3 - �������� �����\n";
			cout << "\t4 - ������ �������\n";
			cout << "\t5 - ���������� �������\n";
			cout << "\t6 - ������� �����\n";
			cout << "\t7 - ������� �������\n";
			cout << "\t8 - ���������\n";
			cout << "\t0 - �����\n";
			cout << "===========================================\n";*/
			cin >> menuSwitch4;
			switch (menuSwitch4)
			{
			case 1: // 1 - ���������� ��� �����
			{
				system("cls");
				users[i].showOutputDataCard();
				system("pause");
				break;
			}
			case 2: // 2 - ��������� �����
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
			case 3: // 3 - �������� �����
			{
				Card card;
				int k = users[i].getCountCard() + 1;
				card.inputDataCard(k);
				users[i].setCardOne(card);

				string num1 = to_string(k);
				string path1 = "Users/User";
				path1 += num1;
				int n = users[i].getCountCard();
				string num2 = to_string(n);
				string path2 = path1;
				path2 += "/Card";
				path2 += num2;
				create_directory(path2);
				break;
			}
			case 4: // 4 - ���������� �������
			{
				users[i].outputSpendingU();
				break;
			}
			case 5: // 5 - ������ �������
			{
				users[i].inputSpendingU();
				break;
			}
			case 6: // 6 - ������� �����
			{
				int reporttype;
				cout << "������������ �������\n";
				cout << "1 - �� ��������\n";
				cout << "2 - �� ����������\n";
				cin >> reporttype;
				system("cls");
				cout << "�������� �����: \n";
				int ptr;
				for (int i = 0; i < users[i].getCountCard(); i++)
				{
					cout << i + 1 << " - �����\n";
				}
				cin >> ptr;
				users[i].outputReportU(ptr - 1, reporttype);
				break;
			}
			case 7: // 7 - ������� �������
			{
				int reporttype;
				cout << "������������ �����\n";
				cout << "1 - �� ��������\n";
				cout << "2 - �� ����������\n";
				cin >> reporttype;
				system("cls");
				cout << "�������� �����: \n";
				int ptr;
				for (int i = 0; i < users[i].getCountCard(); i++)
				{
					cout << i + 1 << " - �����\n";
				}
				cin >> ptr;
				users[i].outputTopU(ptr - 1, reporttype);
				break;
			}
			case 8: // 8 - ���������
			{
				menu3(users);
				break;
			}
			case 0: // 0 - �����
			{
				menuSwitch3 = 0;
				ptr = 0;
				break;
			}
			}
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
	cout << "\t3 - �������� �����\n";
	cout << "\t4 - ���������� �������\n";
	cout << "\t5 - ������ �������\n";
	cout << "\t6 - ������� �����\n";
	cout << "\t7 - ������� �������\n";
	cout << "\t8 - ���������\n";
	cout << "\t0 - �����\n";
	cout << "===========================================\n";
}

void menu3(vector <User>& users)
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

