#include "Club.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Club::split_string(string str, char delimiter) {
    // Ignores empty values
    int first, last = 0;
    vector<string> output;
    while((first=str.find_first_not_of(delimiter, last)) != string::npos) {
        last = str.find(delimiter, first);
        output.push_back(str.substr(first, last-first));
    }
    return output;
}

string Club::vector_to_string(vector<string> vector, string delimiter) {
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

Club::Club(string Name, string Desc, string Members, string Password, string Tags){
    name = Name;
    desc = Desc;
    members = Members;
    password = Password;
    tags = Tags;
}

Club::Club(string Name, string Desc, vector<string> Members, string Password, vector<string> Tags){
    name = Name;
    desc = Desc;
    members = vector_to_string(Members, "~");
    password = Password;
    tags = vector_to_string(Tags, "~");
}

Club::Club(vector<string> input_vector){
    name = input_vector.at(0);
    desc = input_vector.at(1);
    members = input_vector.at(2);
    password = input_vector.at(3);
    tags = input_vector.at(4);
}

// Print Club Info
void Club::print(){
    cout << "Club Name: " << name << endl;
    cout << "Description: " << desc << endl;
    cout << "Members: " << vector_to_string(this->get_members_vector(),", ") << endl;
    cout << "Password: " << password << endl;
    cout << "Tags: " << vector_to_string(this->get_tags_vector(),", ") << endl;
}

// Getters
string Club::get_name(){
    return name;
}

string Club::get_desc(){
    return desc;
}

string Club::get_members_string(){
    return members;
}

vector<string> Club::get_members_vector(){
    return split_string(members,'~');
}

vector<string> Club::get_all() {
    return vector<string> {name,desc,members,password,tags};
}

// Checks
bool Club::member_exist(string net_id){
    for(string member:get_members_vector()) {
        if(net_id == member) {
            return true;
        }
    }
    return false;
}

bool Club::equals(Club club2) {
    if(name == club2.get_name() &&
            desc == club2.get_desc() &&
            members == club2.get_members_string())
        return true;
    return false;
}

// Setters
//    void set_name(string val); // CANNOT SET NAME
void Club::set_desc(string new_desc){
    desc = new_desc;
}

void Club::set_members(string new_members){
    members = new_members;
}

void Club::set_members(vector<string> new_members){
    members = vector_to_string(new_members,"~");
}

// Modifiers
void Club::add_member(string net_id){
    vector<string> temp = split_string(members,'~');
    if(find(temp.begin(), temp.end(), net_id) == temp.end())
        temp.push_back(net_id);
    members = vector_to_string(temp,"~");
}

void Club::delete_member(string net_id){
    vector<string> members_vector = split_string(members,'~');
    auto it = find(members_vector.begin(), members_vector.end(), net_id);
    if(it != members_vector.end())
        members_vector.erase(it);
    else
        throw runtime_error("Member" + net_id + " cannot be found/deleted");
    members = vector_to_string(members_vector,"~");
}

string Club::get_password() {
    return password;
}

string Club::get_tags_string() {
    return tags;
}

vector<string> Club::get_tags_vector() {
    return split_string(tags,'~');
}

void Club::add_tag(string tag) {
    vector<string> temp = split_string(tags,'~');
    if(find(temp.begin(), temp.end(), tag) == temp.end())
        temp.push_back(tag);
    tags = vector_to_string(temp,"~");
}

void Club::delete_tag(string tag) {
    vector<string> tag_vector = split_string(tags,'~');
    auto it = find(tag_vector.begin(), tag_vector.end(), tag);
    if(it != tag_vector.end())
        tag_vector.erase(it);
    else
        throw runtime_error("Tag " + tag + " cannot be found/deleted");
    tags = vector_to_string(tag_vector,"~");
}
