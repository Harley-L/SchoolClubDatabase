#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Club {
private:
    string name, desc, members, password, tags;

    vector<string> split_string(string str, char delimiter);
    string vector_to_string(vector<string> vector, string delimiter);
public:
    // Add more parameters when the database is finalized
    Club() = default;
    Club(string Name, string Desc, string Members, string Password, string Tags);
    Club(string Name, string Desc, vector<string> Members, string Password, vector<string> Tags);
    Club(vector<string> input_vector);

    // Print Club Info
    void print();

    // Getters
    string get_name();
    string get_desc();
    string get_password();
    string get_members_string();
    vector<string> get_members_vector();
    string get_tags_string();
    vector<string> get_tags_vector();
    vector<string> get_all();

    // Checks
    bool member_exist(string net_id);
    bool equals(Club club2);


    // Setters
//    void set_name(string val); // CANNOT SET NAME
    void set_desc(string new_desc);
    void set_members(string new_members);
    void set_members(vector<string> new_members);

    // Modifiers
    void add_member(string net_id);
    void delete_member(string net_id);
    void add_tag(string tag);
    void delete_tag(string tag);
};