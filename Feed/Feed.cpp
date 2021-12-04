#include "Feed.h"

Feed::Feed() = default;

int Feed::get_row_index(int identifier) {
    int i = 0;
    for(Post elms:feed) {
        if(elms.get_id() == identifier) {
            return i;
        }
        i++;
    }
    throw runtime_error("No such row");
}

int Feed::get_row_index(Post post2) {
    int i = 0;
    for(Post elms:feed) {
        if(elms.get_id() == post2.get_id()) {
            return i;
        }
        i++;
    }
    throw runtime_error("No such row");
}

Feed::Feed(vector<Post> Feed) {
    for(Post elm:Feed) {
        feed.push_back(elm);
    }
}

void Feed::print() {
    for(Post post:feed) {
        post.print();
        cout << endl;
    }
}

void Feed::add_post(Post new_post) {
    feed.emplace_back(new_post);
}

void Feed::remove_post(Post del_post) {
    feed.erase(feed.begin()+get_row_index(del_post));
}

void Feed::remove_post(int identifier) {
    feed.erase(feed.begin()+get_row_index(identifier));
}

void Feed::update_post(int identifier, Post updated_post) {
    remove_post(identifier);
    add_post(updated_post);
}

vector<Post> Feed::get_feed() {
    return feed;
}
