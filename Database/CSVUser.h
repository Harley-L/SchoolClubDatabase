#pragma once

#include "../User/User.h"

#include "CSVDatabase.h"

class CSVUser : public CSVDatabase {
public:
    using CSVDatabase::CSVDatabase;
    void set_users(const vector<User>&);

    void print_nice();

    // Returns a user class of a specified identifier
    User get_user(string identifier);
    // Adds a user to the database
    void add_user(User user);
    // Updates a users information (Found using identifier)
    void update_user(User user);
    void update_user(string identifier, string column, string value);
    // Deletes a user from database
    void delete_user(User user);
    void delete_user(string identifier);

    vector<User> get_users();
};
