#pragma once

#include "../Feed/Feed.h"

#include "CSVDatabase.h"

class CSVFeed : public CSVDatabase {
public:
    using CSVDatabase::CSVDatabase;

    void print_nice();

    // Returns a post class of a specified id
    Post get_post(int id);
    // Adds a post to the database
    void add_post(Post post);
    // Updates a posts information (Found using id)
    void update_post(Post post);
    void update_post(int id, string const& column, string const& value);
    // Deletes a club from database
    void delete_post(Post post);
    void delete_post(int id);
    // Places entire feed into Feed class
    Feed get_feed();
    // Updates entire database from Feed class
    void set_feed(Feed feed);

    vector<Post> get_posts(const string& club_name);
    vector<Post> get_posts();

};
