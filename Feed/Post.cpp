#include "Post.h"

vector<string> Post::split_string(string str, char delimiter) {
    // Ignore missing values
    int first, last = 0;
    vector<string> output;
    while((first=str.find_first_not_of(delimiter, last)) != string::npos) {
        last = str.find(delimiter, first);
        output.push_back(str.substr(first, last-first));
    }
    return output;
}

string Post::vector_to_string(vector<string> vector, string delimiter) {
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

Post::Post(Datetime Datetime, vector<string> Content, string Club, vector<Comment> Comments) {
    id = Random::get(1, 100000000);
    datetime = Datetime;
    content = Content;
    club_name = Club;
    comments = Comments;
}

Post::Post(vector<string> post) {
    id = stoi(post.at(0));
    datetime = Datetime(post.at(1));
    content = split_string(post.at(2),'~');
    club_name = post.at(3);
    vector<string> all_comments = split_string(post.at(4),'~');
    int len_comments = all_comments.size() / 3;
    // Divide comments into 3s
    vector<string> comment;
    for(int i=0;i<len_comments;i++) {
        comment.push_back(all_comments.at((i*3)+0));
        comment.push_back(all_comments.at((i*3)+1));
        comment.push_back(all_comments.at((i*3)+2));
        comments.push_back(Comment(comment));
        comment.clear();
    }

}


void Post::print() {
    cout << club_name << " at: " << datetime.get_datetime() << endl;
    for (const string &cont:content)
        cout << cont << endl;
    cout << "Comments:" << endl;
    for (Comment comment:comments) {
        cout << comment.get_user() << ": ";
        cout << comment.get_content() << " (";
        cout << comment.get_datetime().get_datetime() << ")" << endl;
    }
}

bool Post::equals(Post post2) {
    if(datetime.equals(post2.get_datetime()) &&
                club_name == post2.get_club_name() &&
                id == post2.get_id())
        return true;
    return false;
}


// Setters
void Post::set_datetime(Datetime Datetime) {
    datetime = Datetime;
}

void Post::set_content(vector<string> Content) {
    content = Content;
}

void Post::set_club(string Club) {
    club_name = Club;
}

void Post::set_comments(vector<Comment> Comments) {
    comments = Comments;
}

// Getters
Datetime Post::get_datetime() {
    return datetime;
}

vector<string> Post::get_content() {
    return content;
}

string Post::get_club_name() {
    return club_name;
}

vector<Comment> Post::get_comments() {
    return comments;
}

int Post::get_id() {
    return id;
}

vector<string> Post::get_all() {
    vector<string> comments_string;
    for(Comment comment:comments)
        comments_string.push_back(comment.get_all());
    return vector<string> {to_string(id),datetime.get_datetime(),club_name,vector_to_string(content,"~"),vector_to_string(comments_string, "~")};
}