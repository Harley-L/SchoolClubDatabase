#include "Datetime.h"

int Datetime::get_military_time(string Hour, string Min, string ampm) const {
    int houri = stoi(Hour);
    if(ampm == "PM" && houri != 12)
        houri += 12;
    if(houri == 12 && ampm == "AM")
        houri = 0;
    return stoi(to_string(houri)+Min);
}


Datetime::Datetime(int Year, int Month, int Day, int Hour, int Min) {
    // Exceptions:
    if (Year < 2000 || Year > 3000)
        throw runtime_error("Incorrectly formatted Year: " + to_string(Year));
    if (Month < 1 || Month > 12)
        throw runtime_error("Incorrectly formatted Month: " + to_string(Month));
    if (Day < 1 || Day > 31)
        throw runtime_error("Incorrectly formatted Day: " + to_string(Day));
    if (Hour < 0 || Hour > 24)
        throw runtime_error("Incorrectly formatted Hour: " + to_string(Hour));
    if (Min < 0 || Min > 59)
        throw runtime_error("Incorrectly formatted Min: " + to_string(Min));

    // Convert to string
    // Year
    year = to_string(Year);
    //Month
    if (Month >=1 && Month <=9)
        month = "0"+to_string(Month);
    else
        month = to_string(Month);
    // Day
    if (Day >=1 && Day <=9)
        day = "0"+to_string(Day);
    else
        day = to_string(Day);
    // Hour and am_pm
    if (Hour >=1 && Hour <=9) {
        hour = "0" + to_string(Hour);
        am_pm = "AM";
    }
    else
        if (Hour >= 13) {
            am_pm = "PM";
            Hour = Hour - 12;
            if (Hour >= 1 && Hour <= 9)
                hour = "0" + to_string(Hour);
            else
                hour = to_string(Hour);
        }
        else {
            hour = to_string(Hour);
            am_pm = "AM";
        }
    // Min
    if (Min >=1 && Min <=9)
        min = "0"+to_string(Min);
    else
        min = to_string(Min);
}

Datetime::Datetime(string Year, string Month, string Day, string Hour, string Min, string Am_pm) {
    // Exceptions:
    if (stoi(Year) < 1000 || stoi(Year) > 3000)
        throw runtime_error("Incorrectly formatted Year: " + Year);
    if (stoi(Month) < 1 || stoi(Month) > 12)
        throw runtime_error("Incorrectly formatted Month: " + Month);
    if (stoi(Day) < 1 || stoi(Day) > 31)
        throw runtime_error("Incorrectly formatted Day: " + Day);
    if (stoi(Hour) < 0 || stoi(Hour) > 24)
        throw runtime_error("Incorrectly formatted Hour: " + Hour);
    if (stoi(Min) < 0 || stoi(Min) > 59)
        throw runtime_error("Incorrectly formatted Min: " + Min);
    if (Am_pm != "AM" && Am_pm != "PM" )
        throw runtime_error("Incorrectly formatted AM/PM: " + Am_pm);

    // Convert to string
    // Year
    year = Year;

    //Month
    if (Month.length() == 1)
        month = "0"+Month;
    else
        month = Month;

    // Day
    if (Day.length() == 1)
        day = "0"+Day;
    else
        day = Day;

    // Hour
    if (Hour.length() == 1)
        hour = "0" + Hour;
    else
    if (stoi(Hour) >= 13) {
        Hour = to_string(stoi(Hour) - 12);
        if (Hour.length() == 1)
            hour = "0" + Hour;
        else
            hour = Hour;
    }
    else
        hour = Hour;

    // Min
    if (Min.length() == 1)
        min = "0"+Min;
    else
        min = Min;

    am_pm = Am_pm;
}

Datetime::Datetime() {
    time_t     now = time(nullptr);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    string Hour, Min, Year, Month, Day, Am_pm;
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    strftime(buf, sizeof(buf), "%Y", &tstruct);
    year = buf;
    strftime(buf, sizeof(buf), "%m", &tstruct);
    month = buf;
    strftime(buf, sizeof(buf), "%d", &tstruct);
    day = buf;
    strftime(buf, sizeof(buf), "%I", &tstruct);
    hour = buf;
    strftime(buf, sizeof(buf), "%M", &tstruct);
    min = buf;
    strftime(buf, sizeof(buf), "%p", &tstruct);
    am_pm = buf;
}

Datetime::Datetime(string datetime) {
//    "2021-11-08: 09:14 PM" Format
    try {
        year = datetime.substr(0, 4);
        month = datetime.substr(5, 2);
        day = datetime.substr(8, 2);
        hour = datetime.substr(12, 2);
        min = datetime.substr(15, 2);
        am_pm = datetime.substr(18, 2);

        // Exceptions:
        if (stoi(year) < 1000 || stoi(year) > 3000)
            throw runtime_error("Incorrectly formatted Year: " + year);
        if (stoi(month) < 1 || stoi(month) > 12)
            throw runtime_error("Incorrectly formatted Month: " + month);
        if (stoi(day) < 1 || stoi(day) > 31)
            throw runtime_error("Incorrectly formatted Day: " + day);
        if (stoi(hour) < 0 || stoi(hour) > 24)
            throw runtime_error("Incorrectly formatted Hour: " + hour);
        if (stoi(min) < 0 || stoi(min) > 59)
            throw runtime_error("Incorrectly formatted Min: " + min);
        if (am_pm != "AM" && am_pm != "PM" )
            throw runtime_error("Incorrectly formatted AM/PM: " + am_pm);
    } catch(const exception& e) {
        throw runtime_error("Datetime " + datetime + " is in the improper format");
    }
}

string Datetime::get_datetime() {
    return year + "-" + month + "-" + day + ": " + hour + ":" + min + " " + am_pm;
}
string Datetime::get_date() {
    return year + "-" + month + "-" + day;
}

string Datetime::get_time() {
    return hour + ":" + min + " " + am_pm;
}

bool Datetime::equals(Datetime datetime2) {
    if(this->get_datetime() == datetime2.get_datetime())
        return true;
    return false;
}

bool Datetime::operator<(const Datetime &datetime2) const {
    if(stoi(this->year)<stoi(datetime2.year))
        return true;
    if(stoi(this->year)>stoi(datetime2.year))
        return false;
    if(stoi(this->month)<stoi(datetime2.month))
        return true;
    if(stoi(this->month)>stoi(datetime2.month))
        return false;
    if(stoi(this->day)<stoi(datetime2.day))
        return true;
    if(stoi(this->day)>stoi(datetime2.day))
        return false;

    // Time of day:
    if(get_military_time(this->hour,this->min,this->am_pm)<get_military_time(datetime2.hour,datetime2.min,datetime2.am_pm))
        return true;
    return false;
}
