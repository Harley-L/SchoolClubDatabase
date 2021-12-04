#pragma once

#include "../Club/Club.h"
#include "../User/User.h"
#include "../Database/CSVClub.h"
#include "../HelperClasses/Datetime.h"

#include <vector>
#include <iostream>

class Comment {
    Datetime datetime = Datetime(2010,1,1,1,1);
    string content;
    string user;
public:
    Comment(string User, Datetime Datetime, string Content);
    Comment(vector<string> vector);

    void print();

    // Getters
    Datetime get_datetime();
    string get_content();
    string get_user();
    string get_all();

    // Setters
    void set_datetime(Datetime Datetime);
    void set_content(string Content);
    void set_user(string User);
};
