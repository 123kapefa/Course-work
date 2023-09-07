#pragma once
#include "Card.hpp"
#include "Library.hpp"

using namespace std;

class User
{
private:
    string login; // ����� ������������
    string key; // ������ ������������
    string name; // ��� �����������
    string surname; // ������� ������������
    vector <Card> card; // ������ ���� ������������
public:
    // ������������
    User(string _name, string _surname) : name(_name), surname(_surname) {} // ����������� � 3 �����������
    User(string _name, string _surname, string _login, string _key, vector <Card> _card) : name(_name), surname(_surname), login(_login), key(_key), card(_card) {} // ����������� � 3 �����������
    User() : User("Unknown", "Unknown") {} // ����������� �� ���������

    // ����������
    /*~User() { delete[] card; }*/

    // ���������
    string getLogin() { return login; }
    string getKey() { return key; }
    string getName() { return name; }
    string getSurname() { return surname; }
    int getCountCard() { return card.size(); }
    vector <Card> getCard() { return card; }

    // ��������
    void setLogin(string _login) { login = _login; }
    void setKey(string _key) { key = _key; }
    void setName(string _name) { name = _name; }
    void setSurname(string _surname) { surname = _surname; }
    void setCardAll(vector <Card> _card) { card = _card; }
    void setCardOne(Card _card) { card.push_back(_card); }
    //void setCard(Card* _card)
    
    
    // --------------------------- ������ ---------------------------
    
   

    // �����: ���������� ������ ������������ � �����.txt
    friend void inputUsersTXT(const int maxUsers, int& countUsers, int ptrSwitch);

    // �����: �������� ������������� � ������ � �������
    void createUser(int ptrfolder)
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
        int countCard;
        cin >> countCard;
        vector <Card> newcard;
        string num1 = to_string(ptrfolder + 1);
        string path1 = "Users/User";
        path1 += num1;

        create_directory(path1);
        for (int i = 0; i < countCard; i++)
        {
            Card card;
            card.inputDataCard(i + 1);
            newcard.push_back(card);

            string num2 = to_string(i + 1);
            string path2 = path1;
            path2 += "/Card";
            path2 += num2;
            create_directory(path2);
        }
        card = newcard;

        
    }

    // �����: ����� ������ ������������ 
    void outputUserDistlay()
    {
        cout << "   ���: " << name << "   �������: " << surname << "   ���-��� ����: " << card.size() << endl;

    }

    void outputReportU(int i, int reporttype)
    {
        card[i].outputReportC(reporttype);
    }

    void outputTopU(int i, int reporttype)
    {
        card[i].outputTopC(reporttype);
    }

    


    void outputSpendingU()
    {
        system("cls");
        int ptrcard;
        bool ptrsw = true;
        while (ptrsw)
        {
        system("cls");
            cout << "�������� �����:\n";
            for (int i = 0; i < card.size(); i++)
            {
                cout << "  " << i + 1 << " - �����\n";
            }
            cin >> ptrcard;
            ptrcard -= 1;
            if (ptrcard >= 0 && ptrcard < card.size())
                ptrsw = false;
        }
        system("cls");
        card[ptrcard].outputSpendingC();
    }

    void inputSpendingU()
    {
        system("cls");
        bool ptrsw1 = true;
        int ptrcard;
        while (ptrsw1)
        {
            cout << "�������� �����\n";
            for (int i = 0; i < card.size(); i++)
            {
                cout << "  " << i + 1 << " - �����\n";
            }
            cin >> ptrcard;
            ptrcard -= 1;
            if (ptrcard >= 0 && ptrcard < card.size())
                ptrsw1 = false;
        }
            system("cls");
            card[ptrcard].inputSpendingC();
    }

    // �����: ����� ������ � ������ "Card" ��� ����� ������ ���� ������������
    void showInputDataCard()
    {
        for (int i = 0; i < card.size(); i++)
            card[i].inputDataCard(i + 1);
    }

    // �����: ����� ������ � ������ "Card" ��� ������ ������ ���� ������������
    void showOutputDataCard()
    {
        for (int i = 0; i < card.size(); i++)
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

    void inputSpendingTXTU(int usernumber, int ptrsw)
    {
        for (int i = 0; i < card.size(); i++)
        {
            card[i].inputSpendingTXTC(usernumber, i + 1, ptrsw);
        }
    }
};

ostream& operator<<(ostream& os, User& user)
{
    os << user.getName() << user.getSurname() << user.getLogin() << user.getKey() << user.getCountCard();
        return os;
}

void inputUsersTXT(vector<User> &users, int ptrSwitch)
{

        if (ptrSwitch == 1)
        {
            string path = "Users/Users.txt";
            fstream fin;
            fin.open(path, fstream::out);
            if (fin.is_open())
            {
                for (int i = 0; i < users.size(); i++)
                {
                    fin << users[i].getName() << endl << users[i].getSurname() << endl << users[i].getLogin() << endl << users[i].getKey() << endl << users[i].getCountCard();
                    if (i != users.size() - 1)
                    {
                        fin << endl;
                    }

                    vector <Card> cards = users[i].getCard();

                    inputCardsTXT(cards, users[i].getCountCard(), i + 1, 1);
                }
            }
            else
            {
                cout << "�� ������� ������� ����!" << endl;
            }
            fin.close();
        }
        if (ptrSwitch == 2)
        {
            string path = "Users/Users.txt";
            fstream fin;
            fin.open(path, fstream::in);
            if (fin.is_open())
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



                    int ptrCountCard = stoi(ptrCountCardStr);

                    vector<Card> ptrCards;

                    inputCardsTXT(ptrCards, ptrCountCard, i + 1, 2);

                    User newUser(ptrName, ptrSurname, ptrLogin, ptrKey, ptrCards);

                    users.push_back(newUser);
                }
            }
            else
            {
                cout << "�� ������� ������� ����!" << endl;
            }
            fin.close();
        }
}
    


