#include "CSVUser.h"

User CSVUser::get_user(string identifier) {
    vector<string> temp = get_row(identifier);
    return User(temp.at(0),temp.at(1),temp.at(2),temp.at(3),temp.at(4),temp.at(5),temp.at(6));
}

void CSVUser::add_user(User user) {
    if(row_exist(user.get_net_id()))
        throw runtime_error("Attempted to add a user that already exists");
    data.push_back(user.get_all());
}

void CSVUser::delete_user(User user) {
    data.erase(data.begin()+get_row_index(user.get_net_id()));
}

void CSVUser::delete_user(string identifier) {
    data.erase(data.begin()+get_row_index(identifier));
}

void CSVUser::update_user(User user) {
    delete_user(user);
    add_user(user);
}

void CSVUser::update_user(string identifier, string column, string value) {
    int col_num = get_col_index(column);
    vector<string> temp = get_row(identifier);
    delete_user(identifier);
    temp.at(col_num) = value;
    User temp_user = User(temp);
    add_user(temp_user);
}

void CSVUser::print_nice() {
    int i = 0;
    for(vector<string> user:data) {
        if(i == 0) {
            i++;
            continue;
        }
        cout << "User " << i << ":" << endl;
        User(user).print();
        cout << endl;
        i++;
    }
}

vector<User> CSVUser::get_users() {
    vector<User> users;
    int i = 0;
    for(vector<string> temp:data) {
        if(i==0) {
            i++;
            continue;
        }
        users.push_back(User(temp));
    }
    return users;
}

void CSVUser::set_users(const vector<User>& users) {
    vector<string> titles = data.at(0);
    data.clear();
    data.push_back(titles);
    for(User user:users)
        data.push_back(user.get_all());
}
