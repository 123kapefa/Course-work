#pragma once
#include "Card.hpp"
#include "Library.h"

using namespace std;

class User
{
private:
    string login; // Логин пользователя
    string key; // Пароль польхователя
    string name; // Имя ползователя
    string surname; // Фамилия пользователя
    vector <Card> card; // Массив карт пользователя
    int countCard; // Количество карт пользователя
public:
    // Конструкторы
    User(string _name, string _surname, int _countCard) : name(_name), surname(_surname), countCard(_countCard) {} // Конструктор с 3 параметрами
    User(string _name, string _surname, string _login, string _key, vector <Card> _card, int _countCard) : name(_name), surname(_surname), login(_login), key(_key), card(_card), countCard(_countCard) {} // Конструктор с 3 параметрами
    User() : User("Unknown", "Unknown", 0) {} // Конструктор по умолчанию

    // Деструктор
    /*~User() { delete[] card; }*/

    // Аксессоры
    string getLogin() { return login; }
    string getKey() { return key; }
    string getName() { return name; }
    string getSurname() { return surname; }
    vector <Card> getCard() { return card; }
    int getCountCard() { return countCard; }

    // Мутаторы
    void setLogin(string _login) { login = _login; }
    void setKey(string _key) { key = _key; }
    void setName(string _name) { name = _name; }
    void setSurname(string _surname) { surname = _surname; }
    void setCountCard(int _countCard) { countCard = _countCard; }
    void setCard(vector <Card> _card) { card = _card; }
    //void setCard(Card* _card)
    
    
    // --------------------------- МЕТОДЫ ---------------------------
    
   

    // Метод: считывание данных пользователя с файла.txt
    friend void inputUsersTXT(const int maxUsers, int& countUsers, int ptrSwitch);

    // Метод: создание пользователся в ручную с консоли
    void createUser()
    {
        system("cls");
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "Введите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> key;
        cout << "Введите количество карт: ";
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

    // Метод: вывод данных пользователя 
    void outputUserDistlay()
    {
        cout << "   Имя: " << name << "   Фамилия: " << surname << "   Кол-тво карт: " << countCard << endl;

    }

    // Метод: вызов метода с класса "Card" для ввода данных карт пользователя
    void showInputDataCard()
    {
        for (int i = 0; i < countCard; i++)
            card[i].inputDataCard(i + 1);
    }

    // Метод: вызов метода с класса "Card" для вывода данных карт пользователя
    void showOutputDataCard()
    {
        for (int i = 0; i < countCard; i++)
            card[i].outputDataCard(i + 1);
    }

    // Метод: для ввода денежных средств
    void refill(int numCard, double sum)
    {
        card[numCard].setCardSum(sum);
    }

    // Метод: для изменения данных пользователя
    void cardSettings(int ptrmenuSwitch5)
    {
        int ptrCard;
        cout << "Выберите карту для изменения: ";
        cin >> ptrCard;
        ptrCard--;
        switch (ptrmenuSwitch5)
        {
            case 1:
            {
                string ptrCardNumber;
                cout << "Введите новый номер карты: ";
                cin >> ptrCardNumber;
                card[ptrCard].setCardNumber(ptrCardNumber);
                break;
            }
            case 2:
            {
                int ptrCardType;
                cout << "Выберите новый тип карты:" << endl;
                cout << "   1 - Дебютовая" << endl;
                cout << "   2 - Кредитная" << endl;
                cin >> ptrCardType;
                if (ptrCardType == 1)
                {
                    card[ptrCard].setCardType("Дебютовая");
                }
                else if (ptrCardType == 2)
                {
                    card[ptrCard].setCardType("Кредитная");
                }
                
            }
            case 3:
            {
                string ptrCardDate;
                cout << "Введите новый срок действия карты: ";
                cin >> ptrCardDate;
                card[ptrCard].setCardDate(ptrCardDate);
            }
            case 4:
            {
                string ptrCardSVSCode;
                cout << "Введите новый номер SVS: ";
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
        cout << "Не удалось открыть файл!" << endl;
    }
    fin.close();
}

