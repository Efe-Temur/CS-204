#include<string>
#include <iostream>
#include "ActivityBST.h"
using namespace std;

string fill_with_zeros(int num_zeros, const string& input) {
	int zeros_to_add = num_zeros - input.length();
	if (zeros_to_add < 0) zeros_to_add = 0;
	return string(zeros_to_add, '0') + input;
}
string number_to_time(int number) {
	return fill_with_zeros(2, to_string(number / 100)) + ":" + fill_with_zeros(2,
		to_string(number % 100));
}

ActivityBST::ActivityBST() {
	root = nullptr;
}

ActivityBST::ActivityBST(const ActivityBST& rhs) {
	root = nullptr;
	this->recursiveAdd(*this,rhs.root);
}


ActivityBST::~ActivityBST() {
	recursiveDelete(root);
}

void ActivityBST::recursiveDelete(tree_node* root) {
	if (root == nullptr)
		return;
	
	recursiveDelete(root->left);
	recursiveDelete(root->right);
	delete root;
}

void ActivityBST::recursiveAdd(ActivityBST& tree, tree_node* root) const {
	if (root == nullptr)
		return;

	recursiveAdd(tree, root->left);
	recursiveAdd(tree, root->right);
	tree.add(root->time, root->activity);
}

void ActivityBST::add(int time, const string& activity) {
	tree_node* newNode, * nodePtr;
	newNode = new tree_node(time, activity);
	newNode->left = newNode->right = nullptr;

	if (0 <= time % 100 && time % 100 < 60 && int(time / 100 < 24) && int(time / 100 >= 0)) {

	}
	else {
		
		return;
	}
	if (!root) {
		root = newNode;
	}
	else {
		nodePtr = root;

		while (nodePtr) {
			if (time < nodePtr->time) {
				if (nodePtr->left) {
					nodePtr = nodePtr->left;
				}
				else {
					nodePtr->left = newNode;
					newNode->parent = nodePtr;
					break;
				}
			}
			else if (time > nodePtr->time) {
				if (nodePtr->right) {
					nodePtr = nodePtr->right;
				}
				else {
					nodePtr->right = newNode;
					newNode->parent = nodePtr;
					break;
				}
			}
		}
	}

}

//void ActivityBST::add2(int time, const string& activity) const {
//	tree_node* newNode, * nodePtr;
//	newNode = new tree_node(time, activity);
//	newNode->left = newNode->right = nullptr;
//	nodePtr = this->root;
//
//	while (nodePtr) {
//		if (time < nodePtr->time) {
//			if (nodePtr->left) {
//				nodePtr = nodePtr->left;
//			}
//			else {
//				nodePtr->left = newNode;
//				newNode->parent = nodePtr;
//				break;
//			}
//		}
//		else if (time > nodePtr->time) {
//			if (nodePtr->right) {
//				nodePtr = nodePtr->right;
//			}
//			else {
//				nodePtr->right = newNode;
//				newNode->parent = nodePtr;
//				break;
//			}
//		}
//	}
//}

tree_node* ActivityBST::getRoot() const {
	return root;
}

ostream& ActivityBST::inOrder(ostream& os, tree_node* root) const {
	if (root == NULL)
		return os;

	ActivityBST::inOrder(os, root->left);
	os <<"["<< number_to_time(root->time) << "] - " << root->activity << endl;
	ActivityBST::inOrder(os, root->right);
	return os;
}

ActivityBST ActivityBST::operator+(const ActivityBST& rhs) const {
	ActivityBST temp;
	recursiveAdd(temp, this->root);
	recursiveAdd(temp, rhs.root);
	return temp;
}

ActivityBST ActivityBST::operator+=(const ActivityBST& rhs) {
	recursiveAdd(*this, rhs.root);
	return *this;
}

ActivityBST ActivityBST::operator=(const ActivityBST& rhs) {
	this->~ActivityBST();
	this->root = nullptr;
	this->recursiveAdd(*this, rhs.root);
	return *this;
}

ostream& operator<<(ostream& os, const ActivityBST& tree)
{
	return tree.inOrder(os, tree.getRoot());
}