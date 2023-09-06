#pragma once
#include "Spending.h"
#include "Library.h"

using namespace std;

class Card
{
private:
	string cardNumber; // Номер карты
	string cardType; // Тип карты
	string cardDate; // Срок действия карты
	string cardSVSCode; // Код SVS
	double cardSum; // Сумма на карте
	vector <Spending> cardSpending;
public:
	// Конструкторы
	Card(string _cardNumber, string _cardType, string _cardDate, string _cardSVSCode, double _cardSum) : cardNumber(_cardNumber), cardType(_cardType), cardDate(_cardDate), cardSVSCode(_cardSVSCode), cardSum(_cardSum) {}

	Card() : Card("0000 0000 0000 0000", "01.1970", "debit", "000", 0.0) {} // Конструктор по умолчанию

	// Аксессоры
	string getCardNumber() { return cardNumber; }
	string getCardType() { return cardType; }
	string getCardDate() { return cardDate; }
	string getCardSVSCode() { return cardSVSCode; }
	double getCardSum() { return cardSum; }
	vector <Spending> getCardSpending() { return cardSpending; }

	// Мутаторы
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
		cardSpending = other.cardSpending;
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

	// --------------------------- МЕТОДЫ ---------------------------

	// Метод: для ввода данных карты пользователя
	void inputDataCard(int ptr)
	{
		system("cls");
		int typeCard;
		bool ptrsw = true;
		while(ptrsw)
		{
			system("cls");
			cout << "Ввод данных для №" << ptr << " карты:" << endl;
			cout << "Выберите тип карты:" << endl;
			cout << "   1 - Дебетовая" << endl;
			cout << "   2 - Кредитная" << endl;
			cin >> typeCard;
			if (typeCard == 1 || typeCard == 2)
			{
				ptrsw = false;
			}
		}
		
		switch (typeCard)
		{
		case 1:
			setCardType("Дебютовая");
			break;
		case 2:
			setCardType("Кредитная");
			break;
		default:
			break;
		}
		cout << "Введите номер карты: ";
		cin.ignore();
		getline(cin, cardNumber);
		//cin >> cardNumber;
		cout << "Введите срок действия карты: ";
		cin >> cardDate;
		cout << "Введите номер SVS: ";
		cin >> cardSVSCode;
	}

	// Метод: для вывода данных карты пользователя
	void outputDataCard(int ptr)
	{
		cout << ptr << " Карта: " << endl;
		cout << "\tНомер карты: " << cardNumber << endl;
		cout << "\tТип карты: " << cardType << endl;
		cout << "\tСрок действия карты: " << cardDate << endl;
		cout << "\tНомер SVS: " << cardSVSCode << endl;
		cout << "\tБаланс: " << fixed << setprecision(2) << cardSum << endl;
	}

	void outputSpendingC()
	{
		if (!cardSpending.empty())
		{
			cout << setw(5) << "|"
				<< setw(17) << " Название услуги "
				<< setw(1) << "|"
				<< setw(6) << "  ID  "
				<< setw(1) << "|"
				<< setw(14) << " Дата покупки "
				<< setw(1) << "|"
				<< setw(10) << "   Цена   "
				<< setw(1) << " |"
				<< endl;
			cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
			for (int i = 0; i < cardSpending.size(); i++)
			{
				cardSpending[i].outputSpendingS();
			}
		}
		else
		{
			cout << "Нет расходов!" << endl;
		}
		system("pause");
	}

	void inputSpendingC()
	{
		Spending ptrspending;
		ptrspending.inputSpendingS(ptrspending);
		cardSpending.push_back(ptrspending);
		system("pause");
	}

	friend void inputCardsTXT(vector<Card>& cards, int ptrCountCards, int usersnumber, int ptrSwitch)
	{
		
			if (ptrSwitch == 1)
			{
				string ptrusernumber = to_string(usersnumber);
				ptrusernumber += "/input_cards";
				string path = "Users/User.txt";
				path.insert(10, ptrusernumber);

				fstream fin;
				fin.open(path, fstream::out);
				if (fin.is_open())
				{
					for (int i = 0; i < ptrCountCards; i++)
					{
						fin << cards[i].getCardNumber() << endl << cards[i].getCardType() << endl << cards[i].getCardDate() << endl << cards[i].getCardSVSCode() << endl << cards[i].getCardSum();
						if (i != cards.size() - 1)
						{
							fin << endl;
						}
					}
				}
				else
				{
					cout << "Не удалось открыть файл!" << endl;
				}
				fin.close();
			}
			if (ptrSwitch == 2)
			{
				string ptrusernumber = to_string(usersnumber);
				ptrusernumber += "/input_cards";
				string path = "Users/User.txt";
				path.insert(10, ptrusernumber);

				fstream fin;
				fin.open(path, fstream::in);
				if (fin.is_open())
				{
					for (int i = 0; i < ptrCountCards; i++)
					{
						string ptrCardType, ptrCardNumber, ptrCardDate, ptrCardSVSCode, ptrCardSumStr;
						int ptrCardSum;
						// Считывание данных карт и создание объектов Card
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
				else
				{
					cout << "Не удалось открыть файл!" << endl;
				}
				fin.close();
			}
		
	}

	void inputSpendingTXTC(int usernumber, int cardnumber, int ptrsw)
	{
		inputSpendingTXT(cardSpending, usernumber, cardnumber, ptrsw);
	}

	void outputReportC(int reporttype)
	{
		bool switchwhile1 = true;
		while (switchwhile1)
		{
			system("cls");
			int reporttime;
			cout << "Выберите в каком формате сформировать отчет\n";
			cout << "1 - день\n";
			cout << "2 - неделя\n";
			cout << "3 - месяц\n";
			cin >> reporttime;
			bool switchwhile2 = true;
			switch (reporttype)
			{
			case 1:
			{
				while (switchwhile2)
				{
					system("cls");

					tm localDate = { 0 };

					time_t currentTime = time(nullptr);
					localtime_s(&localDate, &currentTime);
					localDate.tm_hour = 0;
					localDate.tm_min = 0;
					localDate.tm_sec = 0;

					vector <Spending> s;

					switch (reporttime)
					{
					case 1:
					{
						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCostS(localDate, ptr);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile2 = false;
						switchwhile1 = false;
						break;
					}
					case 2:
					{
						tm weekDate = localDate;
						weekDate.tm_hour = 0;
						weekDate.tm_min = 0;
						weekDate.tm_sec = 0;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 7 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCostS(localTime, weekTime, ptr);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 3:
					{
						tm monDate = localDate;
						monDate.tm_hour = 0;
						monDate.tm_min = 0;
						monDate.tm_sec = 0;
						time_t monTime = mktime(&monDate);
						monTime -= 30 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCostS(localTime, monTime, ptr);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					}
					if (!s.empty())
					{
						system("cls");
						cout << setw(5) << "|"
							<< setw(17) << " Название услуги "
							<< setw(1) << "|"
							<< setw(6) << "  ID  "
							<< setw(1) << "|"
							<< setw(14) << " Дата покупки "
							<< setw(1) << "|"
							<< setw(10) << "   Цена   "
							<< setw(1) << " |"
							<< endl;
						cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
						for (int i = 0; i < s.size(); i++)
						{
							s[i].outputSpendingS();
						}
					}
					else
					{
						cout << "Нет расходов!" << endl;
					}
					system("pause");
				}
				break;
			}
			case 2:
			{
				while (switchwhile2)
				{
					int spendingrtype;
					cout << "Выберите категорию:\n";
					cout << "1 - Продукты\n";
					cout << "2 - Такси\n";
					cout << "3 - Медицина\n";
					cout << "4 - Товары и услуги\n";
					cout << "5 - Рестораны\n";
					cout << "6 - Топливо\n";
					cin >> spendingrtype;

					tm localDate = { 0 };

					time_t currentTime = time(nullptr);
					localtime_s(&localDate, &currentTime);
					localDate.tm_hour = 0;
					localDate.tm_min = 0;
					localDate.tm_sec = 0;

					vector <Spending> s;

					switch (reporttime)
					{
					case 1:
					{
						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCategoryS(localDate, ptr, spendingrtype);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 2:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 7 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCategoryS(localTime, weekTime, ptr, spendingrtype);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 3:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 30 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputReportCategoryS(localTime, weekTime, ptr, spendingrtype);
							if (ptr)
								s.push_back(cardSpending[i]);
						}
						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					}
					if (!s.empty())
					{
						system("cls");
						cout << setw(5) << "|"
							<< setw(17) << " Название услуги "
							<< setw(1) << "|"
							<< setw(6) << "  ID  "
							<< setw(1) << "|"
							<< setw(14) << " Дата покупки "
							<< setw(1) << "|"
							<< setw(10) << "   Цена   "
							<< setw(1) << " |"
							<< endl;
						cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
						for (int i = 0; i < s.size(); i++)
						{
							s[i].outputSpendingS();
						}
					}
					else
					{
						cout << "Нет расходов!" << endl;
					}
					system("pause");
				}
				break;
			}
			}

		}
	}

	void outputTopC(int reporttype)
	{
		bool switchwhile1 = true;
		while (switchwhile1)
		{
			system("cls");
			int reporttime;
			cout << "Выберите в каком формате сформировать отчет\n";
			cout << "1 - день\n";
			cout << "2 - неделя\n";
			cout << "3 - месяц\n";
			cin >> reporttime;
			bool switchwhile2 = true;

			double top1 = -1;
			double top2 = -1;
			double top3 = -1;

			switch (reporttype)
			{
			case 1:
			{
				while (switchwhile2)
				{
					system("cls");

					tm localDate = { 0 };

					time_t currentTime = time(nullptr);
					localtime_s(&localDate, &currentTime);
					localDate.tm_hour = 0;
					localDate.tm_min = 0;
					localDate.tm_sec = 0;

					vector <Spending> s;

					

					switch (reporttime)
					{
					case 1:
					{
						for (int i = 0; i < cardSpending.size(); i++)
						{
							cardSpending[i].outputTopCostS(localDate, top1, top2, top3);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = -1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{
							
							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
							}
							if (c2b)
							{
								c2i = i;
							}
							if (c3b)
							{
								c3i = i;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);
						
						switchwhile2 = false;
						switchwhile1 = false;
						break;
					}
					case 2:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 7 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							cardSpending[i].outputTopCostS(localTime, weekTime, top1, top2, top3);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = -1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{

							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
								c1b = false;
							}
							if (c2b)
							{
								c2i = i;
								c2b = false;
							}
							if (c3b)
							{
								c3i = i;
								c3b = false;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);

						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 3:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 30 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							cardSpending[i].outputTopCostS(localTime, weekTime, top1, top2, top3);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = -1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{

							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
								c1b = false;
							}
							if (c2b)
							{
								c2i = i;
								c2b = false;
							}
							if (c3b)
							{
								c3i = i;
								c3b = false;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);

						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					}
					if (!s.empty())
					{
						system("cls");
						cout << setw(5) << "|"
							<< setw(17) << " Название услуги "
							<< setw(1) << "|"
							<< setw(6) << "  ID  "
							<< setw(1) << "|"
							<< setw(14) << " Дата покупки "
							<< setw(1) << "|"
							<< setw(10) << "   Цена   "
							<< setw(1) << " |"
							<< endl;
						cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
						for (int i = 0; i < s.size(); i++)
						{
							s[i].outputSpendingS();
						}
					}
					else
					{
						cout << "Нет расходов!" << endl;
					}
					system("pause");
				}
				break;
			}
			case 2:
			{
				while (switchwhile2)
				{
					int spendingrtype;
					cout << "Выберите категорию:\n";
					cout << "1 - Продукты\n";
					cout << "2 - Такси\n";
					cout << "3 - Медицина\n";
					cout << "4 - Товары и услуги\n";
					cout << "5 - Рестораны\n";
					cout << "6 - Топливо\n";
					cin >> spendingrtype;

					tm localDate = { 0 };

					time_t currentTime = time(nullptr);
					localtime_s(&localDate, &currentTime);
					localDate.tm_hour = 0;
					localDate.tm_min = 0;
					localDate.tm_sec = 0;

					vector <Spending> s;

					switch (reporttime)
					{
					case 1:
					{
						for (int i = 0; i < cardSpending.size(); i++)
						{
							cardSpending[i].outputTopCategoryS(localDate, spendingrtype, top1, top2, top3);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = - 1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{

							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
								c1b = false;
							}
							if (c2b)
							{
								c2i = i;
								c2b = false;
							}
							if (c3b)
							{
								c3i = i;
								c3b = false;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);

						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 2:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 7 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							bool ptr = false;
							cardSpending[i].outputTopCategoryS(localTime, weekTime, spendingrtype, top1, top2, top3);
							if (ptr)
								s.push_back(cardSpending[i]);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = -1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{

							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
								c1b = false;
							}
							if (c2b)
							{
								c2i = i;
								c2b = false;
							}
							if (c3b)
							{
								c3i = i;
								c3b = false;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);

						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					case 3:
					{
						tm weekDate = localDate;
						time_t weekTime = mktime(&weekDate);
						weekTime -= 30 * 24 * 3600;
						time_t localTime = mktime(&localDate);

						for (int i = 0; i < cardSpending.size(); i++)
						{
							cardSpending[i].outputTopCategoryS(localTime, weekTime, spendingrtype, top1, top2, top3);
						}

						bool c1b = false, c2b = false, c3b = false;
						int c1i = -1, c2i = -1, c3i = -1;

						for (int i = 0; i < cardSpending.size(); i++)
						{

							cardSpending[i].topReport(top1, top2, top3, c1b, c2b, c3b);
							if (c1b)
							{
								c1i = i;
								c1b = false;
							}
							if (c2b)
							{
								c2i = i;
								c2b = false;
							}
							if (c3b)
							{
								c3i = i;
								c3b = false;
							}
						}

						if (c1i >= 0)
							s.push_back(cardSpending[c1i]);
						if (c2i >= 0)
							s.push_back(cardSpending[c2i]);
						if (c3i >= 0)
							s.push_back(cardSpending[c3i]);

						switchwhile1 = false;
						switchwhile2 = false;
						break;
					}
					}
					if (!s.empty())
					{
						system("cls");
						cout << setw(5) << "|"
							<< setw(17) << " Название услуги "
							<< setw(1) << "|"
							<< setw(6) << "  ID  "
							<< setw(1) << "|"
							<< setw(14) << " Дата покупки "
							<< setw(1) << "|"
							<< setw(10) << "   Цена   "
							<< setw(1) << " |"
							<< endl;
						cout << setw(55) << "    +-----------------+------+--------------+-----------+" << endl;
						for (int i = 0; i < s.size(); i++)
						{
							s[i].outputSpendingS();
						}
					}
					else
					{
						cout << "Нет расходов!" << endl;
					}
					system("pause");
				}
				break;
			}
			}

		}
	}
};
