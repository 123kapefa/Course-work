#pragma once
#include "Card.hpp"
#include "Library.h"

using namespace std;

class User
{
private:
    string login; // ����� ������������
    string key; // ������ ������������
    string name; // ��� �����������
    string surname; // ������� ������������
    vector <Card> card; // ������ ���� ������������
    int countCard; // ���������� ���� ������������
public:
    // ������������
    User(string _name, string _surname, int _countCard) : name(_name), surname(_surname), countCard(_countCard) {} // ����������� � 3 �����������
    User(string _name, string _surname, string _login, string _key, vector <Card> _card, int _countCard) : name(_name), surname(_surname), login(_login), key(_key), card(_card), countCard(_countCard) {} // ����������� � 3 �����������
    User() : User("Unknown", "Unknown", 0) {} // ����������� �� ���������

    // ����������
    /*~User() { delete[] card; }*/

    // ���������
    string getLogin() { return login; }
    string getKey() { return key; }
    string getName() { return name; }
    string getSurname() { return surname; }
    vector <Card> getCard() { return card; }
    int getCountCard() { return countCard; }

    // ��������
    void setLogin(string _login) { login = _login; }
    void setKey(string _key) { key = _key; }
    void setName(string _name) { name = _name; }
    void setSurname(string _surname) { surname = _surname; }
    void setCountCard(int _countCard) { countCard = _countCard; }
    void setCard(vector <Card> _card) { card = _card; }
    //void setCard(Card* _card)
    
    
    // --------------------------- ������ ---------------------------
    
   

    // �����: ���������� ������ ������������ � �����.txt
    friend void inputUsersTXT(const int maxUsers, int& countUsers, int ptrSwitch);

    // �����: �������� ������������� � ������ � �������
    void createUser()
    {
        system("cls");
        cout << "������� ���: ";
        cin >> name;
        cout << "������� �������: ";
        cin >> surname;
        cout << "������� �����: ";
        cin >> login;
        cout << "������� ������: ";
        cin >> key;
        cout << "������� ���������� ����: ";
        cin >> countCard;
        vector <Card> newcard;
        for (int i = 0; i < countCard; i++)
        {
            Card card;
            card.inputDataCard(i + 1);
            newcard.push_back(card);
        }
        card = newcard;
    }

    // �����: ����� ������ ������������ 
    void outputUserDistlay()
    {
        cout << "   ���: " << name << "   �������: " << surname << "   ���-��� ����: " << countCard << endl;

    }

    // �����: ����� ������ � ������ "Card" ��� ����� ������ ���� ������������
    void showInputDataCard()
    {
        for (int i = 0; i < countCard; i++)
            card[i].inputDataCard(i + 1);
    }

    // �����: ����� ������ � ������ "Card" ��� ������ ������ ���� ������������
    void showOutputDataCard()
    {
        for (int i = 0; i < countCard; i++)
            card[i].outputDataCard(i + 1);
    }

    // �����: ��� ����� �������� �������
    void refill(int numCard, double sum)
    {
        card[numCard].setCardSum(sum);
    }

    // �����: ��� ��������� ������ ������������
    void cardSettings(int ptrmenuSwitch5)
    {
        int ptrCard;
        cout << "�������� ����� ��� ���������: ";
        cin >> ptrCard;
        ptrCard--;
        switch (ptrmenuSwitch5)
        {
            case 1:
            {
                string ptrCardNumber;
                cout << "������� ����� ����� �����: ";
                cin >> ptrCardNumber;
                card[ptrCard].setCardNumber(ptrCardNumber);
                break;
            }
            case 2:
            {
                int ptrCardType;
                cout << "�������� ����� ��� �����:" << endl;
                cout << "   1 - ���������" << endl;
                cout << "   2 - ���������" << endl;
                cin >> ptrCardType;
                if (ptrCardType == 1)
                {
                    card[ptrCard].setCardType("���������");
                }
                else if (ptrCardType == 2)
                {
                    card[ptrCard].setCardType("���������");
                }
                
            }
            case 3:
            {
                string ptrCardDate;
                cout << "������� ����� ���� �������� �����: ";
                cin >> ptrCardDate;
                card[ptrCard].setCardDate(ptrCardDate);
            }
            case 4:
            {
                string ptrCardSVSCode;
                cout << "������� ����� ����� SVS: ";
                cin >> ptrCardSVSCode;
                card[ptrCard].setCardSVSCode(ptrCardSVSCode);
            }
            default:
            {

                break;
            }
        }
    }

    void inputSpendingTXTU(int usernumber)
    {
        for (int i = 0; i < card.size(); i++)
        {
            card[i].inputSpendingTXTC(usernumber, i + 1);
        }
    }
};

ostream& operator<<(ostream& os, User& user)
{
    os << user.getName() << user.getSurname() << user.getLogin() << user.getKey() << user.getCountCard();
        return os;
}


//istream& operator>>(istream& is, User& user)
//{
//    is >> user.setName() >> user.setSurname() >> user.setLogin() >> user.setKey() >> user.setCountCard();
//    return is;
//}

void inputUsersTXT(vector<User> &users, int ptrSwitch)
{

    string path = "Users/Users.txt";
    fstream fin;
    fin.open(path, fstream::in | fstream::out | fstream::app);
    if (fin.is_open())
    {
        if (ptrSwitch == 1)
        {

        }
        if (ptrSwitch == 2)
        {
            for (int i = 0; !fin.eof(); i++)
            {
                string ptrName, ptrSurname, ptrLogin, ptrKey, ptrCountCardStr;

                getline(fin, ptrName);
                getline(fin, ptrSurname);
                getline(fin, ptrLogin);
                getline(fin, ptrKey);
                getline(fin, ptrCountCardStr);
                fin.ignore();

                    /*string ptrFolder = "User";
                    string numberFolder = to_string(i);
                    ptrFolder += numberFolder;
                    if (exists(ptrFolder))
                        is_directory(status(ptrFolder));
                    else
                        create_directory(ptrFolder);*/

                int ptrCountCard = stoi(ptrCountCardStr);

                vector<Card> ptrCards;

                inputCardsTXT(ptrCards, ptrCountCard, i + 1, 2);

                User newUser(ptrName, ptrSurname, ptrLogin, ptrKey, ptrCards, ptrCountCard);

                users.push_back(newUser);
            }
        }
    }
    else
    {
        cout << "�� ������� ������� ����!" << endl;
    }
    fin.close();
}

