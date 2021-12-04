#pragma once

#include "../Club/Club.h"

#include "CSVDatabase.h"

class CSVClub : public CSVDatabase {
public:
    using CSVDatabase::CSVDatabase;
    void set_clubs(const vector<Club>&);

    void print_nice();

    // Returns a club class of a specified identifier
    Club get_club(string name);
    // Adds a club to the database
    void add_club(Club club);
    // Updates a club information (Found using name)
    void update_club(Club club);
    void update_club(string name, string column, string value);
    // Deletes a club from database
    void delete_club(Club club);
    void delete_club(string name);

    // returns a vector of clubs
    vector<Club> get_clubs();

};
