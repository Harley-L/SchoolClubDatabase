#include "CSVClub.h"

Club CSVClub::get_club(string name) {
    vector<string> temp = get_row(name);
    return Club(temp.at(0),temp.at(1),temp.at(2),temp.at(3),temp.at(4));
}

void CSVClub::add_club(Club club) {
    if(row_exist(club.get_name()))
        throw runtime_error("Attempted to add a club that already exists");
    data.push_back(club.get_all());
}

void CSVClub::delete_club(Club club) {
    data.erase(data.begin()+get_row_index(club.get_name()));
}

void CSVClub::delete_club(string name) {
    data.erase(data.begin()+get_row_index(name));
}

void CSVClub::update_club(Club club) {
    delete_club(club);
    add_club(club);
}

void CSVClub::update_club(string name, string column, string value) {
    int col_num = get_col_index(column);
    vector<string> temp = get_row(name);
    delete_club(name);
    temp.at(col_num) = value;
    Club temp_user = Club(temp);
    add_club(temp_user);
}

void CSVClub::print_nice() {
    int i = 0;
    for(vector<string> club:data) {
        if(i == 0) {
            i++;
            continue;
        }
        cout << "Club " << i << ":" << endl;
        Club(club).print();
        cout << endl;
        i++;
    }
}

vector<Club> CSVClub::get_clubs() {
    vector<Club> clubs;
    int i = 0;
    for(vector<string> temp:data) {
        if(i==0) {
            i++;
            continue;
        }
        clubs.push_back(Club(temp));
    }
    return clubs;
}

void CSVClub::set_clubs(const vector<Club>& clubs) {
    vector<string> titles = data.at(0);
    data.clear();
    data.push_back(titles);
    for(Club club:clubs)
        data.push_back(club.get_all());
}
