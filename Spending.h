#pragma once
#include "Library.h"

using namespace std;

class Spending
{
private:
    Category category;
    Date date;
    double price;
    
public:

    Spending(int _category_id, int _date_year, int _date_mon, int _date_day, double _price)
        : price(_price)
    {
        switch (_category_id)
        {
        case 1:
            category.id = _category_id;
            category.name = "Products";
            break;
        case 2:
            category.id = _category_id;
            category.name = "Taxi";
            break;
        case 3:
            category.id = _category_id;
            category.name = "Pharmacy";
            break;
        case 4:
            category.id = _category_id;
            category.name = "GoodsAndServices";
            break;
        case 5:
            category.id = _category_id;
            category.name = "Restaurants";
            break;
        case 6:
            category.id = _category_id;
            category.name = "Fuel";
            break;
        }

        date.date_year = _date_year;
        date.date_mon = _date_mon;
        date.date_day = _date_day;
    }

    Spending() : Spending(0, 1970, 1, 1, 0.0) {}

    // Аксессоры
    //int getCategory() { return category; }
    //string getName() { return name; }
    int getDateDay() { return date.date_day; }
    int getDateMon() { return date.date_mon; }
    int getDateYear() { return date.date_year; }
    double getPrice() { return price; }

    // Мутаторы
    //void setCategory(int _category) { category = _category; }
    //void setName(string _name) { name = _name; }
    void setDate(Date _date)
    {
        date.date_day = _date.date_day;
        date.date_mon = _date.date_mon;
        date.date_year = _date.date_year;
    }
    void setDateDay(Date _date) { date.date_day = _date.date_day; }
    void setDateMon(Date _date) { date.date_mon = _date.date_mon; }
    void setDateYear(Date _date) { date.date_year = _date.date_year; }
    void setPrice(double _price) { price = _price; }

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
                    string ptr_category_id_str, ptr_date_str, ptr_year_str, ptr_mon_str, ptr_day_str, ptr_price_str;

                    fin >> ptr_category_id_str >> ptr_date_str >> ptr_price_str;

                    int ptr_category_id = stod(ptr_category_id_str);

                    ptr_year_str += ptr_date_str[0];
                    ptr_year_str += ptr_date_str[1];
                    ptr_year_str += ptr_date_str[2];
                    ptr_year_str += ptr_date_str[3];
                    ptr_mon_str += ptr_date_str[4];
                    ptr_mon_str += ptr_date_str[5];
                    ptr_day_str += ptr_date_str[6];
                    ptr_day_str += ptr_date_str[7];
                    int ptr_year = stoi(ptr_year_str);
                    int ptr_mon = stoi(ptr_mon_str);
                    int ptr_day = stoi(ptr_day_str);

                    double ptr_price = stod(ptr_price_str);

                    Spending ptrspending(ptr_category_id, ptr_year, ptr_mon, ptr_day, ptr_price);
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
};



//
//4 20231210 28.0
//1 20231211 19.0
//3 20231212 5.0
//5 20231213 30.0
//6 20231214 45.0
//2 20231215 10.0
//1 20231216 40.0
//3 20231217 12.5
//5 20231218 55.0
//4 20231219 33.0
//1 20231220 28.0
//3 20231221 6.0
//5 20231222 42.0
//6 20231223 20.0
//2 20231224 15.0
//1 20231225 18.0