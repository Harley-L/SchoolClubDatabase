#pragma once

#include "Comment.h"
#include "../HelperClasses/random.hpp"

using Random = effolkronium::random_static;

class Post {
    int id;
    Datetime datetime;
    vector<string> content; // [0] for words, all other indices are for paths to media
    string club_name;
    vector<Comment> comments;

    vector<string> split_string(string str, char delimiter);
    string vector_to_string(vector<string> vector, string delimiter);
public:
    Post(Datetime Datetime, vector<string> Content, string Club, vector<Comment> Comments);
    Post(vector<string> post);

    void print();

    // Comparison
    bool equals(Post post2);

    // Setters
    void set_datetime(Datetime Datetime);
    void set_content(vector<string> Content);
    void set_club(string club_name);
    void set_comments(vector<Comment> Comments);

    // Getters
    Datetime get_datetime();
    vector<string> get_content();
    string get_club_name();
    vector<Comment> get_comments();
    int get_id();
    vector<string> get_all();



};
