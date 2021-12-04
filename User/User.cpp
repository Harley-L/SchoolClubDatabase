#include "User.h"

vector<string> User::split_string(string str, char delimiter) {
    // Ignores empty values
    int first, last = 0;
    vector<string> output;
    while((first=str.find_first_not_of(delimiter, last)) != string::npos) {
        last = str.find(delimiter, first);
        output.push_back(str.substr(first, last-first));
    }
    return output;
}

string User::vector_to_string(vector<string> vector, string delimiter) {
    int i = 0;
    string output;
    int vector_len = vector.size();
    for(string elm:vector) {
        output += elm;
        i++;
        if(i != vector_len)
            output += delimiter;
    }
    return output;
}

User::User(string Net_id, string Name, string Email, string Password, string Grad_year, string Clubs, string Tags) {
    net_id = Net_id;
    name = Name;
    email = Email;
    password = Password;
    grad_year = Grad_year;
    clubs = Clubs;
    tags = Tags;
}

User::User(vector<string> input_vector) {
    net_id = input_vector.at(0);
    name = input_vector.at(1);
    email = input_vector.at(2);
    password = input_vector.at(3);
    grad_year = input_vector.at(4);
    clubs = input_vector.at(5);
    tags = input_vector.at(6);
}

// Print
void User::print() {
    cout << "User: " << net_id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Graduation: " << grad_year << endl;
    cout << "Clubs: " << vector_to_string(this->get_clubs_vector(),", ") << endl;
    cout << "Tags: " << vector_to_string(this->get_tags_vector(),", ") << endl;
}

// Getters
string User::get_net_id() {
    return net_id;
}

string User::get_name() {
    return name;
}

string User::get_email() {
    return email;
}

string User::get_password() {
    return password;
}

string User::get_grad_year_string() {
    return grad_year;
}

string User::get_clubs_string() {
    return clubs;
}

vector<string> User::get_clubs_vector() {
    return split_string(clubs, '~');
}

vector<string> User::get_all() {
    return vector<string> {net_id,name,email,password,grad_year,clubs,tags};
}

// Setters
//void User::set_net_id(string val) { // CANNOT SET NETID TO ANYTHING ELSE
//    net_id = val;
//}

void User::set_name(string val) {
    name = val;
}
void User::set_email(string val) {
    email = val;
}

void User::set_password(string val) {
    password = val;
}

void User::set_grad_year_string(string val) {
    grad_year = val;
}

void User::set_clubs_string(string val) {
    clubs = val;
}

void User::set_clubs_string(vector<string> val) {
    clubs = vector_to_string(val,"~");
}

string User::get_tags_string() {
    return tags;
}

vector<string> User::get_tags_vector() {
    return split_string(tags, '~');
}

void User::set_tags_string(string val) {
    tags = val;
}

void User::set_tags_string(vector<string> val) {
    tags = vector_to_string(val,"~");
}

void User::delete_tag(string tag) {
    vector<string> tag_vector = split_string(tags,'~');
    auto it = find(tag_vector.begin(), tag_vector.end(), tag);
    if(it != tag_vector.end())
        tag_vector.erase(it);
    else
        throw runtime_error("Tag " + tag + " cannot be found/deleted");
    tags = vector_to_string(tag_vector,"~");
}

void User::add_tag(string tag) {
    vector<string> temp = split_string(tags,'~');
    if(find(temp.begin(), temp.end(), tag) == temp.end())
        temp.push_back(tag);
    tags = vector_to_string(temp,"~");
}

void User::delete_club(string club) {
    vector<string> club_vector = split_string(clubs,'~');
    auto it = find(club_vector.begin(), club_vector.end(), club);
    if(it != club_vector.end())
        club_vector.erase(it);
    else
        throw runtime_error("Club " + club + " cannot be found/deleted");
    clubs = vector_to_string(club_vector,"~");
}

void User::add_club(string club) {
    vector<string> temp = split_string(clubs,'~');
    if(find(temp.begin(), temp.end(), club) == temp.end())
        temp.push_back(club);
    clubs = vector_to_string(temp,"~");
}
