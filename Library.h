#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <compare>

using namespace std;
using namespace filesystem;

struct Date
{
    int date_day;
    int date_mon;
    int date_year;
};

struct Category 
{
    int id;
    string name;
};