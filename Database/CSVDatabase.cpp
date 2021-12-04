#include "CSVDatabase.h"

vector<string> CSVDatabase::split_string(string str, char delimiter) {
    vector<string> output;
    size_t pos;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        output.push_back(token);
        str.erase(0, pos + 1);
    }
    output.push_back(str);
    return output;
}

int CSVDatabase::get_row_index(string identifier) {
    int i = 0;
    for(vector<string> elms:data) {
        if(elms.at(0) == identifier) {
            return i;
        }
        i++;
    }
    throw runtime_error("No such row");
}


int CSVDatabase::get_col_index(string col_name) {
    int i = 0;
    for(string col:data.at(0)) {
        if(col == col_name) {
            return i;
        }
        i++;
    }
    throw runtime_error("No such col");
}

string CSVDatabase::replace_commas(string str) {
//    replace(elm.begin(), elm.end(), ",", "*");
    string result;
    string find = ",";
    string replace = "\u00EA";
    size_t find_len = find.size();
    size_t pos, from=0;
    while (string::npos != (pos=str.find(find,from))) {
        result.append(str, from, pos-from);
        result.append(replace);
        from = pos + find_len;
    }
    result.append(str, from, string::npos);
    return result;
}

string CSVDatabase::add_back_commas(string str) {
    string result;
    string find = "\u00EA";
    string replace = ",";
    size_t find_len = find.size();
    size_t pos, from=0;
    while (string::npos != (pos=str.find(find,from))) {
        result.append(str, from, pos-from);
        result.append(replace);
        from = pos + find_len;
    }
    result.append(str, from, string::npos);
    return result;
}



CSVDatabase::CSVDatabase(string path) {
    // Instance Variable Initialization
    csv_path = move(path);
    ifstream myFile(csv_path);

    // Catching errors
    if(!myFile.is_open()) throw runtime_error("Could not open file");
    if(csv_path.find(".csv") == string::npos) throw runtime_error("File not a csv");


    // Put csv data into vector
    string line, colname;
    string val;
    vector<string> columns;
    vector<vector<string>> temp_data;
    vector<string> temp;
    // Read the column names
    if(myFile.good())
    {
        // Extract the first line in the file
        getline(myFile, line);

        // Create a stringstream from line
        stringstream ss(line);

        // Extract each column name
        while(getline(ss, colname, ',')){

            // Initialize and add <colname, int vector> pairs to result
            columns.push_back(colname);
        }
    }
    data.push_back(columns);
    // Read data, line by line
    while(getline(myFile, line)) {
//        data.push_back(split_string(add_back_commas(line), ','));
        temp = split_string(line, ',');
        for(int i=0; i<temp.size(); i++)
            temp[i] = add_back_commas(temp[i]);
        data.push_back(temp);
    }

    myFile.close();
}

void CSVDatabase::flush() {
    ofstream myFile(csv_path);
    int j = 0;
    int data_len = data.size();
    for(vector<string> row:data) {
        for (int i = 0; i<row.size();i++) {
            myFile << replace_commas(row[i]);
            try {
                row.at(i+1);
                myFile << ",";
            } catch(const out_of_range& oor) {
                continue;
            }
        }
        j++;
        if(j != data_len)
            myFile << endl;
    }
    // Close the file
    myFile.close();
}

void CSVDatabase::flush(string path) {
    ofstream myFile(path);
    int j = 0;
    int data_len = data.size();
    for(vector<string> row:data) {
        for (int i = 0; i<row.size();i++) {
            myFile << row[i];
            try {
                row.at(i+1);
                myFile << ",";
            } catch(const out_of_range& oor) {
                continue;
            }
        }
        j++;
        if(j != data_len)
            myFile << endl;
    }
    // Close the file
    myFile.close();
}

void CSVDatabase::print() {
    for(vector<string> row:data) {
        for (int i = 0; i<row.size();i++) {
            cout << row[i];
            try {
                row.at(i+1);
                cout << ",";
            } catch(const out_of_range& oor) {
                continue;
            }
        }
        cout << endl;
    }
}

vector<string> CSVDatabase::get_row(int index) {
    try {
        return data.at(index); // Fetched Properly
    } catch(exception const & ex) {
        return vector<string> {}; // Fetched an improper index
    }
}

vector<string> CSVDatabase::get_col(int index) {
    try {
        vector<string> col;
        int i = 0;
        for(vector<string> row:data) {
            // Don't append the get_col name
            if(i == 0) {
                i++;
                continue;
            }
            col.push_back(row.at(index));
        }
        return col;
    } catch(exception const & ex) {
        return vector<string> {}; // Fetched an improper index
    }
}

vector<string> CSVDatabase::get_row(string identifier) {
    return get_row(get_row_index(identifier));
}

vector<string> CSVDatabase::get_col(string identifier) {
    return get_col(get_col_index(identifier));
}

string CSVDatabase::data_at_row_col(string row_identifier, string col_identifier) {
    return get_row(row_identifier).at(get_col_index(col_identifier));
}

bool CSVDatabase::row_exist(string identifier) {
    bool output = false;
    for(vector<string> row:data) {
        if(row.at(0) == identifier)
            output = true;
    }
    return output;
}

