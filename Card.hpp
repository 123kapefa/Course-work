#pragma once
#include "Spending.h"
#include "Library.h"

using namespace std;

class Card
{
private:
    string cardNumber; // ����� �����
    string cardType; // ��� �����
    string cardDate; // ���� �������� �����
    string cardSVSCode; // ��� SVS
    double cardSum; // ����� �� �����
    vector <Spending> cardSpending;
public:
    // ������������
    Card(string _cardNumber, string _cardType, string _cardDate, string _cardSVSCode, double _cardSum) : cardNumber(_cardNumber), cardType(_cardType), cardDate(_cardDate), cardSVSCode(_cardSVSCode), cardSum(_cardSum) {}

    Card() : Card("0000 0000 0000 0000", "01.1970", "debit", "000", 0.0) {} // ����������� �� ���������

    // ���������
    string getCardNumber() { return cardNumber; }
    string getCardType() { return cardType; }
    string getCardDate() { return cardDate; }
    string getCardSVSCode() { return cardSVSCode; }
    double getCardSum() { return cardSum; }
    vector <Spending> getCardSpending() { return cardSpending; }

    // ��������
    void setCardNumber(string _cardNumber) { cardNumber = _cardNumber; }
    void setCardType(string _cardType) { cardType = _cardType; }
    void setCardDate(string _cardDate) { cardDate = _cardDate; }
    void setCardSVSCode(string _cardSVSCode) { cardSVSCode = _cardSVSCode; }
    void setCardSum(double _cardSum) { cardSum += _cardSum; }
    void setCardSpending(vector <Card> _card, Spending _cardSpending, int num) 
    {
        _card[num].cardSpending.push_back(_cardSpending);
         
    }

    Card(const Card& other)
    {
        cardNumber = other.cardNumber;
        cardType = other.cardType;
        cardDate = other.cardDate;
        cardSVSCode = other.cardSVSCode;
        cardSum = other.cardSum;
    }

    Card& operator= (const Card& other) 
    {
        if (this == &other) { return *this; }

        cardNumber = other.cardNumber;
        cardType = other.cardType;
        cardDate = other.cardDate;
        cardSVSCode = other.cardSVSCode;
        cardSum = other.cardSum;

        return *this;
    }

    // --------------------------- ������ ---------------------------

    // �����: ��� ����� ������ ����� ������������
    void inputDataCard(int ptr)
    {
        system("cls");
        int typeCard;
        cout << "���� ������ ��� �" << ptr << " �����:" << endl;
        cout << "�������� ��� �����:" << endl;
        cout << "   1 - ���������" << endl;
        cout << "   2 - ���������" << endl;
        cin >> typeCard;
        switch (typeCard)
        {
        case 1:
            setCardType("���������");
            break;
        case 2:
            setCardType("���������");
            break;
        default:
            break;
        }
        cout << "������� ����� �����: ";
        cin.ignore();
        getline(cin, cardNumber);
        //cin >> cardNumber;
        cout << "������� ���� �������� �����: ";
        cin >> cardDate;
        cout << "������� ����� SVS: ";
        cin >> cardSVSCode;
    }

    // �����: ��� ������ ������ ����� ������������
    void outputDataCard(int ptr)
    {
        cout << ptr << " �����: " << endl;
        cout << "\t����� �����: " << cardNumber << endl;
        cout << "\t��� �����: " << cardType << endl;
        cout << "\t���� �������� �����: " << cardDate << endl;
        cout << "\t����� SVS: " << cardSVSCode << endl;
        cout << "\t������: " << cardSum << endl;
    }

    void outputSpenddingC()
    {
        cout << setw(5) << "|"
            << setw(17) << " �������� ������ "
            << setw(1) << "|"
            << setw(6) << "  ID  "
            << setw(1) << "|"
            << setw(14) << " ���� ������� "
            << setw(1) << "|"
            << setw(10) << "   ����   "
            << setw(1) << " |"
            << endl;
        cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
        for (int i = 0; i < cardSpending.size(); i++)
        {
            cardSpending[i].outputSpenddingS();
        }
        system("pause");
    }

    friend void inputCardsTXT(vector<Card> &cards, int ptrCountCards, int usersnumber, int ptrSwitch)
    {
        string ptrusernumber = to_string(usersnumber);
        ptrusernumber += "/input_cards";
        string path = "Users/User.txt";
        path.insert(10, ptrusernumber);

        fstream fin;
        fin.open(path, fstream::in | fstream::out | fstream::app);
        if (fin.is_open())
        {
            if (ptrSwitch == 1)
            {

            }
            if (ptrSwitch == 2)
            {
                for (int i = 0; i < ptrCountCards; i++)
                {
                    string ptrCardType, ptrCardNumber, ptrCardDate, ptrCardSVSCode, ptrCardSumStr;
                    int ptrCardSum;
                    // ���������� ������ ���� � �������� �������� Card
                    getline(fin, ptrCardNumber);
                    getline(fin, ptrCardType);
                    getline(fin, ptrCardDate);
                    getline(fin, ptrCardSVSCode);
                    getline(fin, ptrCardSumStr);
                    fin.ignore();

                    ptrCardSum = stod(ptrCardSumStr);

                    Card new_card(ptrCardNumber, ptrCardType, ptrCardDate, ptrCardSVSCode, ptrCardSum);
                    
                    cards.push_back(new_card);
                }
            }
        }
        else
        {
            cout << "�� ������� ������� ����!" << endl;
        }
        fin.close();
    }

    void inputSpendingTXTC(int usernumber, int cardnumber)
    {
        inputSpendingTXT(cardSpending, usernumber, cardnumber, 2);
    }
};
