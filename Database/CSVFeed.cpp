#include "CSVFeed.h"

void CSVFeed::print_nice() {
    int i = 0;
    for (const vector<string>& post:data) {
        if (i == 0) {
            i++;
            continue;
        }
        cout << "Club " << i << ":" << endl;
        Post(post).print();
        cout << endl;
        i++;
    }
}

vector<Post> CSVFeed::get_posts(const string& club_name) {
    int i = 0;
    vector<Post> temp;
    for (vector<string> post:data) {
        if (i == 0) {
            i++;
            continue;
        }
        if(post[2] == club_name)
            temp.push_back(Post(post));
    }
    return temp;
}

vector<Post> CSVFeed::get_posts() {
    int i = 0;
    vector<Post> temp;
    for (const vector<string>& post:data) {
        if (i == 0) {
            i++;
            continue;
        }
        temp.push_back(Post(post));
    }
    return temp;
}

Post CSVFeed::get_post(int id) {
    int i = 0;
    for (vector<string> post:data) {
        if (i == 0) {
            i++;
            continue;
        }
        if (post[0]==to_string(id))
            return Post(post);
    }
    throw runtime_error("No such post with id: " + to_string(id));
}

void CSVFeed::add_post(Post post) {
    if(row_exist(to_string(post.get_id())))
        throw runtime_error("Attempted to add a post that already exists");
    data.push_back(post.get_all());
}

void CSVFeed::update_post(Post post) {
    delete_post(post);
    add_post(post);
}

void CSVFeed::update_post(int id, string const& column, string const& value) {
    int col_num = get_col_index(column);
    vector<string> temp = get_row(id);
    delete_post(id);
    temp.at(col_num) = value;
    Post temp_user = Post(temp);
    add_post(temp_user);
}

void CSVFeed::delete_post(Post post) {
    data.erase(data.begin()+get_row_index(to_string(post.get_id())));
}

void CSVFeed::delete_post(int id) {
    data.erase(data.begin()+get_row_index(to_string(id)));
}

Feed CSVFeed::get_feed() {
    Feed feed;
    int i = 0;
    for (const vector<string>& post:data) {
        if (i == 0) {
            i++;
            continue;
        }
        feed.add_post(post);
    }
    return feed;
}

void CSVFeed::set_feed(Feed feed) {
    data.clear();
    data.push_back(vector<string> {"id","datetime","club_name","content_vector","comment_vector"});
    for(Post post:feed.get_feed()) {
        data.push_back(post.get_all());
    }
}
