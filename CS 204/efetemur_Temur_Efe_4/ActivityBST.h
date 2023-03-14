#ifndef _ACTIVITYBST_H
#define _ACTIVITYBST_H

#include<string>
#include <iostream>
using namespace std;

struct tree_node {
	int time;
	string activity;
	tree_node* right;
	tree_node* left;
	tree_node* parent;
	tree_node(int t, const string& a) : time(t), activity(a),
		right(nullptr), left(nullptr),
		parent(nullptr) {}
}; 

class ActivityBST {
	private:
		tree_node* root;
		
	public:
		ActivityBST();
		ActivityBST(const ActivityBST&);
		~ActivityBST();
		tree_node* getRoot() const;
		void recursiveDelete(tree_node*);
		void recursiveAdd(ActivityBST&, tree_node*) const;
		void add(int, const string&);
		ostream& inOrder(ostream&, tree_node*) const;
		ActivityBST operator+(const ActivityBST&) const;
		ActivityBST operator+=(const ActivityBST&);
		ActivityBST operator=(const ActivityBST&);
};

ostream& operator<<(ostream&, const ActivityBST&);
#endif 