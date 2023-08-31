#pragma once
#include "Library.h"
//#include "Spending.h"

using namespace std;

class Products // Продукты
{
private:
    string name;
    Date date;
    double price;
public:
    
    Products(string _name, int _date_day, int _date_mon, int _date_year, double _price)
        : name(_name), price(_price)
    {
        date.date_day = _date_day;
        date.date_mon = _date_mon;
        date.date_year = _date_year;
    }

    Products() : Products("unknown", 1, 1, 1970, 0.0) {}

    // Аксессоры
    string getName() { return name; }
    int getDateDay() { return date.date_day; }
    int getDateMon() { return date.date_mon; }
    int getDateYear() { return date.date_year; }
    double getPrice() { return price; }

    // Мутаторы
    void setName(string _name) { name = _name; }
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

    Products(const Products& other)
    {
        name = other.name;
        date.date_day = other.date.date_day;
        date.date_mon = other.date.date_mon;
        date.date_year = other.date.date_year;
        price = other.price;
    }

    Products& operator= (const Products& other)
    {
        if (this == &other) { return *this; }

        name = other.name;
        date.date_day = other.date.date_day;
        date.date_mon = other.date.date_mon;
        date.date_year = other.date.date_year;
        price = other.price;

        return *this;
    }
};

class Taxi // Такси
{
private:
    string name;
    Date date;
    double price;
public:

};

class Pharmacy // Медицина и аптеки
{
private:
    string name;
    Date date;
    double price;
public:
};

class GoodsAndServices // Книги и развлечения
{
private:
    string name;
    Date date;
    double price;
public:
};

class Restaurants // Рестораны
{
private:
    string name;
    Date date;
    double price;
public:
};

class Fuel // Топливо
{
private:
    string name;
    Date date;
    double price;
public:
};