#pragma once

#include "Post.h"

using namespace std;

class Feed {
    vector<Post> feed;
    int get_row_index(int identifier);
    int get_row_index(Post del_post);
public:
    Feed();
    Feed(vector<Post> Feed);

    void print();

    void add_post(Post new_post);
    void remove_post(Post del_post);
    void remove_post(int identifier);
    void update_post(int identifier, Post updated_post);

    vector<Post> get_feed();
};
