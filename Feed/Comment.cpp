#include "Comment.h"

Comment::Comment(string User, Datetime Datetime, string Content) {
    user = User;
    datetime = Datetime;
    content = Content;
}

Comment::Comment(vector<string> vector) {
    user = vector.at(0);
    datetime = Datetime(vector.at(1));
    content = vector.at(2);
}

Datetime Comment::get_datetime() {
    return datetime;
}

string Comment::get_content() {
    return content;
}

string Comment::get_user() {
    return user;
}

void Comment::set_content(string Content) {
    content = Content;
}

void Comment::set_datetime(Datetime Datetime) {
    datetime = Datetime;
}

void Comment::set_user(string User) {
    user = User;
}

void Comment::print() {
    cout << "User: " << user << endl;
    cout << "DateTime: " << datetime.get_datetime() << endl;
    cout << "Content: " << content << endl;
}

string Comment::get_all() {
    return user + "~" + datetime.get_datetime() + "~" + content;
}
