#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Datetime {
    string hour, min, year, month, day, am_pm;

    int get_military_time(string hour, string min, string ampm) const;
public:
    Datetime(int Year, int Month, int Day, int Hour, int Min);
    Datetime(string Year, string Month, string Day, string Hour, string Min, string Am_pm);
    Datetime();
    Datetime(string datetime);

    string get_datetime();
    string get_time();
    string get_date();

    // Comparison
    bool equals(Datetime datetime2);
    bool operator<(const Datetime &datetime2) const;
};
