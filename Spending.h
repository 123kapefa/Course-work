#pragma once
#include "Library.h"

using namespace std;

class Spending
{
private:
    Category category;
    tm date;
    double price;
    
public:

    Spending(int _category_id, int _date_year, int _date_mon, int _date_mday, double _price)
        : price(_price)
    {
        switch (_category_id)
        {
        case 1:
            category.id = _category_id;
            category.name = "Продукты";
            break;
        case 2:
            category.id = _category_id;
            category.name = "Такси";
            break;
        case 3:
            category.id = _category_id;
            category.name = "Медицина";
            break;
        case 4:
            category.id = _category_id;
            category.name = "Товары и услуги";
            break;
        case 5:
            category.id = _category_id;
            category.name = "Рестораны";
            break;
        case 6:
            category.id = _category_id;
            category.name = "Топливо";
            break;
        }

        date.tm_year = _date_year;
        date.tm_mon = _date_mon;
        date.tm_mday = _date_mday;
    }

    Spending(int _category_id, tm _date, double _price)
        : price(_price)
    {
        switch (_category_id)
        {
        case 1:
            category.id = _category_id;
            category.name = "Продукты";
            break;
        case 2:
            category.id = _category_id;
            category.name = "Такси";
            break;
        case 3:
            category.id = _category_id;
            category.name = "Медицина";
            break;
        case 4:
            category.id = _category_id;
            category.name = "Товары и услуги";
            break;
        case 5:
            category.id = _category_id;
            category.name = "Рестораны";
            break;
        case 6:
            category.id = _category_id;
            category.name = "Топливо";
            break;
        }

        date = _date;
    }

    Spending() : Spending(0, 1970, 1, 1, 0.0) {}

    // Аксессоры
    double getPrice() { return price; }

    // Мутаторы
    void setCategory(Category c)
    {
        category.id = c.id;
        category.name = c.name;
    }
    void setCategory(int id)
    {
        switch (id)
        {
        case 1:
            category.id = id;
            category.name = "Продукты";
            break;
        case 2:
            category.id = id;
            category.name = "Такси";
            break;
        case 3:
            category.id = id;
            category.name = "Медицина";
            break;
        case 4:
            category.id = id;
            category.name = "Товары и услуги";
            break;
        case 5:
            category.id = id;
            category.name = "Рестораны";
            break;
        case 6:
            category.id = id;
            category.name = "Топливо";
            break;
        }
    }
    void setDate(int year, int mon, int mday)
    {
        date.tm_mday = mday;
        date.tm_mon = mon;
        date.tm_year = year;
    }
    void setDate(tm _date)
    {
        date = _date;
    }
    void setDateDay(tm _date) { date.tm_mday = _date.tm_mday; }
    void setDateMon(tm _date) { date.tm_mon = _date.tm_mon; }
    void setDateYear(tm _date) { date.tm_year = _date.tm_year; }
    void setPrice(double _price) { price = _price; }

    void outputSpendingS()
    {
        cout << setw(5) << "|"
            << setw(16) << category.name
            << setw(3) << " | "
            << setw(3) << category.id
            << setw(4) << "  |  "
            << put_time(&date, "%Y.%m.%d")
            << setw(4) << "  | ";
        cout << setw(9) << fixed << setprecision(2) << price
            << setw(2) << " |"
            << endl;
    }

    void inputSpendingS(Spending &s)
    {
        int ptrid;
        tm inputdate = { 0 };
        string ptr_date_str;
        double ptr_price;
        bool ptrsw = true;
        while (ptrsw)
        {
            system("cls");
            cout << "Выберите категорию затрат\n";
            cout << "1 - Продукты\n2 - Такси\n3 - Медицина\n4 - Товары и услуги\n5 - Рестораны\n6 - Топливо\n";
            cin >> ptrid;
            if (ptrid > 0 && ptrid < 7)
                ptrsw = false;
        }
        cout << "Введите дату (ГГГГ ММ ДД): ";
        cin.ignore();
        getline(cin, ptr_date_str);
        cout << "Введите сумму: ";
        cin >> ptr_price;
        
        istringstream dateStream(ptr_date_str);

        dateStream >> inputdate.tm_year >> inputdate.tm_mon >> inputdate.tm_mday;
        inputdate.tm_year -= 1900;
        inputdate.tm_mon--;

        time_t dateTime = mktime(&inputdate);

        localtime_s(&inputdate, &dateTime);

        s.setCategory(ptrid);
        s.setDate(inputdate);
        s.setPrice(ptr_price);
    }

    friend void inputSpendingTXT(vector <Spending> &s, int usernumber, int cardnumber, int ptrSwitch)
    {
        string ptrusernumber = to_string(usernumber);
        string ptrcardnumber = to_string(cardnumber);
        string ptr = "/input_spending.txt";
        string path = "Users/User#1/Card#2";
        int p1, p2;
        p1 = path.find("#1");
        path.replace(p1, 2, ptrusernumber);
        p2 = path.find("#2");
        path.replace(p2, 2, ptrcardnumber);

        path += ptr;
        fstream fin;
        fin.open(path, fstream::in | fstream::app);
        if (fin.is_open())
        {
            if (ptrSwitch == 1)
            {
    
            }
            if (ptrSwitch == 2)
            {
                while (!fin.eof())
                {
                    string ptrdate, ptryear, ptrmon, ptrmday;
                    int ptrid;
                    double ptrprice;

                    fin >> ptrid;
                    //fin >> ptrdate;
                    fin >> ptryear >> ptrmon >> ptrmday;
                    fin >> ptrprice;

                    ptrdate += ptryear;
                    ptrdate += " ";
                    ptrdate += ptrmon;
                    ptrdate += " ";
                    ptrdate += ptrmday;
                    istringstream dateStream(ptrdate);

                    tm inputdate = { 0 };

                    dateStream >> inputdate.tm_year >> inputdate.tm_mon >> inputdate.tm_mday;
                    inputdate.tm_year -= 1900;
                    inputdate.tm_mon--;

                    time_t dateTime = mktime(&inputdate);

                    localtime_s(&inputdate, &dateTime);

                    Spending ptrspending(ptrid, inputdate, ptrprice);
                    s.push_back(ptrspending);
                }
            }
        }
        else
        {
            cout << "Не удалось открыть файл!" << endl;
        }
        fin.close();
    }

    //--------------------------------------------------------------------------------------------------------------

    bool outputReportCostS(tm localTime, bool& ptr)
    {
        if (date.tm_year == localTime.tm_year && date.tm_mon == localTime.tm_mon && date.tm_mday == localTime.tm_mday)
            ptr = true;
        return ptr;
    }

    bool outputReportCostS(time_t localTime, time_t rangeTime, bool& ptr)
    {
        time_t dateTime = mktime(&date);

        if 
        (dateTime >= rangeTime && dateTime <= localTime)
            ptr = true;
        return ptr;
    }

    bool outputReportCategoryS(tm localTime, bool& ptr, int spendingtype)
    {
        if (date.tm_year == localTime.tm_year && date.tm_mon == localTime.tm_mon && date.tm_mday == localTime.tm_mday && category.id == spendingtype)
            ptr = true;
        return ptr;
    }

    bool outputReportCategoryS(time_t localTime, time_t rangeTime, bool& ptr, int spendingtype)
    {
        time_t dateTime = mktime(&date);

        if
            (dateTime >= rangeTime && dateTime <= localTime && category.id == spendingtype)
            ptr = true;
        return ptr;
    }

    //--------------------------------------------------------------------------------------------------------------

    void outputTopCostS(tm localTime, double &top1, double &top2, double &top3)
    {
        if (date.tm_year == localTime.tm_year && date.tm_mon == localTime.tm_mon && date.tm_mday == localTime.tm_mday)
        {
            if (top1 < price)
            {
                top3 = top2;
                top2 = top1;
                top1 = price;
            }
        }
    }

    void outputTopCostS(time_t localTime, time_t rangeTime, double& top1, double& top2, double& top3)
    {
        time_t dateTime = mktime(&date);

        if (dateTime >= rangeTime && dateTime <= localTime)
        {
            if (top1 < price)
            {
                top3 = top2;
                top2 = top1;
                top1 = price;
            }
            else if (price < top1 && price > top2)
            {
                top3 = top2;
                top2 = price;
            }
        }
    }

    void outputTopCategoryS(tm localTime, int spendingtype, double& top1, double& top2, double& top3)
    {
        if (date.tm_year == localTime.tm_year && date.tm_mon == localTime.tm_mon && date.tm_mday == localTime.tm_mday)
        {
            if (top1 < price)
            {
                top3 = top2;
                top2 = top1;
                top1 = price;
            }
        }
    }

    void outputTopCategoryS(time_t localTime, time_t rangeTime, int spendingtype, double& top1, double& top2, double& top3)
    {
        time_t dateTime = mktime(&date);

        if (dateTime >= rangeTime && dateTime <= localTime && category.id == spendingtype)
        {
            if (top1 < price)
            {
                top3 = top2;
                top2 = top1;
                top1 = price;
            }
        }
    }

    void topReport(const double top1, const double top2, const double top3, bool& c1, bool& c2, bool& c3)
    {
        if (top1 == price)
            c1 = true;
        else if (top2 == price)
            c2 = true;
        else if (top3 == price)
            c3 = true;
    }
};
