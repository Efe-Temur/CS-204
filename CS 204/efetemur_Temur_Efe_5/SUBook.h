#ifndef SUBOOK
#define SUBOOK

#include<string>
#include <iostream>
#include <vector>
using namespace std;

class Post;
class User;
class Comment;

class User {
private:
	string name;
	vector<Post*> posts;
	int num_comments;

public:
	User();
	User(string);
	~User();
	Post& createPost(string content);
	vector<Post*> getPosts();
	int getNumComments();
	string getName();
	friend class Post;
	friend class Comment;
};


class Post {
private:
	User user;
	string content;
	vector<Comment*> comments;
public:
	Post();
	Post(User,string);
	~Post();
	void addComment(string content, User* commenter);
	vector<Comment*> getComments();
	User& getUser();
	string getContent();
};

class Comment {
private:
	User user;
	string content;
	Post post;
public:
	Comment();
	Comment(User&, Post&, string);
	~Comment();
	User& getUser();
	string getContent();
	Post& getPost();
};


#endif