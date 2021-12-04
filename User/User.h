#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class User {
private:
    string net_id, name, email, password, grad_year, clubs, tags;
    vector<string> split_string(string str, char delimiter);
    string vector_to_string(vector<string> vector, string delimiter);
public:
    // Add more parameters when the database is finalized
    User() = default;
    User(string Net_id, string Name, string Email, string Password, string Grad_year, string Clubs, string Tags);
    User(vector<string> input_vector);

    // Print User Info
    void print();

    // Getters
    string get_net_id();
    string get_name();
    string get_email();
    string get_password();
    string get_grad_year_string();
    string get_clubs_string();
    vector<string> get_clubs_vector();
    string get_tags_string();
    vector<string> get_tags_vector();
    vector<string> get_all();

    // Setters
//    void set_net_id(string val); // CANNOT SET NETID TO ANYTHING ELSE
    void set_name(string val);
    void set_email(string val);
    void set_password(string val);
    void set_grad_year_string(string val);
    void set_clubs_string(string val);
    void set_clubs_string(vector<string> val);
    void set_tags_string(string val);
    void set_tags_string(vector<string> val);
    void add_tag(string val);
    void delete_tag(string val);
    void add_club(string val);
    void delete_club(string val);

};