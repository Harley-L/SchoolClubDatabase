#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class CSVDatabase {
protected:
    string csv_path;
    vector<vector<string>> data;

    vector<string> split_string(string str, char delimiter);
    int get_row_index(string identifier);
    int get_col_index(string col_name);
    string replace_commas(string str);
    string add_back_commas(string str);

public:
    // Constructor
    CSVDatabase(string path);

    CSVDatabase();
    // Opens database and places data in vector

    // ======= Methods =======
    void flush(); // flushes vector into csv
    void flush(string path); // flushes vector into csv
    void print(); // Prints data in vector

    // Fetches data by index
    vector<string> get_row(int index);
    vector<string> get_col(int index);

    // Fetches data by identifier/name
    vector<string> get_row(string identifier);
    vector<string> get_col(string identifier);
    string data_at_row_col(string row_identifier, string col_identifier);

    // Check if row exists
    bool row_exist(string identifier);
};
