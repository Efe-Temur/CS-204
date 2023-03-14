#include<string>
#include <iostream>
#include "SUBook.h"
using namespace std;


User::User() {}

User::User(string s) {
	name = s;
	num_comments = 0;
}

User::~User() {
	
	/*for (int i = 0; i < posts.size(); i++) {
			posts[i]->~Post();			
		}*/

//	for (Post* obj : posts)		
//		delete obj;
//posts.clear();

	
	//for (int i = 0; i < posts.size(); i++) {
	//	/*posts[i]->~Post();*/
	//	delete posts[i];
	//}
	//posts.clear();
}

Post& User::createPost(string content) {
	Post* p = new Post(*this ,content);
	posts.push_back(p);
	return *p;
}

vector<Post*> User::getPosts() {
	return posts;
}

int User::getNumComments() {
	return num_comments;
}

string User::getName() {
	return name;
}
Post::Post() {

}

Post::Post(User u, string s) {
	user = u;
	content = s;
}

Post::~Post() {

	/*for (int i = 0; i < comments.size(); i++) {
		comments[i]->~Comment();
	}*/

	//for (Comment* obj : comments)
	//	delete obj;
	//comments.clear();

	
	
	//for (int i = 0; i < comments.size(); i++) {
	//	/*comments[i]->~Comment();*/
	//	delete comments[i];
	//}
	//comments.clear();
}

void Post::addComment(string content, User* commenter) {
	Comment* c = new Comment(*commenter, *this, content);
	comments.push_back(c);
	commenter->num_comments++;
}

vector<Comment*> Post::getComments() {
	return comments;
}

User& Post::getUser() {

	return user;
}

string Post::getContent() {
	return content;
}
Comment::Comment(){}

Comment::Comment(User& u, Post& p , string s) {
	user = u;
	post = p;
	content = s;
}

Comment::~Comment() {
	user.num_comments--;
}

User& Comment::getUser() {
	return user;
}

string Comment::getContent() {
	return content;
}

Post& Comment::getPost() {
	return post;
}