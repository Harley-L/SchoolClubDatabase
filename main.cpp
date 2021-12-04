#include <iostream>
#include "Database/CSVClub.h"
#include "Database/CSVUser.h"
#include "Database/CSVFeed.h"
#include "Club/Club.h"
#include "User/User.h"



using namespace std;

int main() {
    // Load Information from database
    CSVUser csvuser = CSVUser("../Database/user_database.csv");
    CSVClub csvclub = CSVClub("../Database/club_database.csv");
    CSVFeed csvfeed = CSVFeed("../Database/feed_database.csv");

    // Print all information read from database nice
    cout << "Clubs:" << endl;
    csvclub.print_nice();
    cout << "Users:" << endl;
    csvuser.print_nice();
    cout << "Feed:" << endl;
    csvfeed.print_nice();

    // Put information into respective classes
    vector<Club> clubs = csvclub.get_clubs();
    vector<User> users = csvuser.get_users();
    Feed feed = csvfeed.get_feed();
    vector<Post> post_vector = feed.get_feed();

    // Modify some club
    Club temp_club = clubs.at(0);
    temp_club.add_tag("new_tag");
    temp_club.add_member("18h");
    clubs.at(0) = temp_club; // Update club vector

    // Modify some user
    User temp_user = users.at(0);
    temp_user.set_password("new_password");
    temp_user.set_email("new@email.com");
    users.at(0) = temp_user; // Update user vector

    // Modify some post
    Post temp_post = post_vector.at(0);
    temp_post.set_club("Updated_Club");
    post_vector.at(0) = temp_post; // Update post vector

    // Update csv objects
    csvuser.set_users(users);
    csvclub.set_clubs(clubs);
    csvfeed.set_feed(Feed(post_vector));

    // Update local database
    csvuser.flush();
    csvclub.flush();
    csvfeed.flush();
    return 0;
}
