using namespace std;
#include <string>
#include <iostream>
#include <string>
#include <sstream>

#include "activity_bst.h"


string fill_with_zeros(int num_zeros, const string& input) {
	int zeros_to_add = num_zeros - input.length();
	if (zeros_to_add < 0) zeros_to_add = 0;
	return string(zeros_to_add, '0') + input;
}
string number_to_time(int number) {
	return fill_with_zeros(2, to_string(number / 100)) + ":" + fill_with_zeros(2,
		to_string(number % 100));
}

void add_activity(tree_node*& root, int time, const string& activity)

{
	tree_node *newNode, *nodePtr;
	newNode = new tree_node(time, activity);
	newNode->left = newNode->right = nullptr;
	
	if (0 <= time % 100 && time % 100 < 60 && int(time / 100 < 24) && int(time / 100 >= 0)) {

	}
	else {
		cout << "ERROR! Could not add activity '" << activity << "' due to illegal time value"<<endl;
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
	cout << "added activity " << activity << " at " << number_to_time(time) << endl;

}


void func1(tree_node* root, int time)
{
	
	while (root != nullptr && root->right != nullptr) {

		if (time > root->time && time >= root->right->time) {
			root = root->right;

		}
		else if (time < root->time) {
			root = root->left;
		}
		else {
			break;
		}
	}

	if (root == nullptr || root->time > time) {
		cout << "[" << number_to_time(time) << "] - ""free" << endl;
	}
	else {
		cout << "[" << number_to_time(time) << "] - "<<root->activity<<endl;
	}
}

void func2(tree_node* root, int time)
{


	while (root != nullptr && root->right != nullptr) {

		if (time > root->time && time >= root->right->time) {
			root = root->right;

		}
		else if (time < root->time) {
			root = root->left;
		}
		else {
			break;
		}
	}

	if (root == nullptr || root->time > time) {
		if (root != nullptr) {
			if (root->right == nullptr) {
				if (root == nullptr) {
					cout << "Time Period: [00:00 - " << "00:00" << "]:free " << endl;
				}
				else {
					cout << "Time Period: [00:00 - " << number_to_time(root->time) << "]:free " << endl;
				}
			}
			else {

				cout << "Time Period: [00:00 - " << number_to_time(root->right->time) << "]:free " << endl;
			}
		}
		else {
			cout << "Time Period: [00:00 - " << "00:00" << "]:free " << endl;
		}
	}
	else {
		if (root->right != nullptr) {
			cout << "Time Period: ["<< number_to_time(root->time)<<" - " << number_to_time(root->right->time) << "] :" << root->activity << endl;
		}
		else {
			cout << "Time Period: [" << number_to_time(root->time) << " - " << "00:00" << "] :" << root->activity << endl;
		}
	}
}


void print_activity(tree_node* root, int time) {
	if (0 <= time % 100 && time % 100 < 60 && int(time / 100 < 24) && int(time / 100 >= 0)) {

	}
	else {
		cout << "ERROR! Could not add activity '" << "' due to illegal time value" << endl;
		return;
	}
	
	
	func1(root,time);
}

void print_activity_and_duration(tree_node* root, int time) {
	if (0 <= time % 100 && time % 100 < 60 && int(time / 100 < 24) && int(time / 100 >= 0)) {

	}
	else {
		cout << "ERROR! Could not add activity '" << "' due to illegal time value" << endl;
		return;
	}

	func2(root, time);
}

void func3(tree_node* root,int time) {

	while (root != nullptr && root->right != nullptr) {

		if (time > root->time && time > root->right->time) {
			root = root->right;

		}
		else if (time < root->time) {
			root = root->left;
		}
		else {
			break;
		}
	}

}

void inorder_check(tree_node* root, const string& activity, tree_node* temp) {
	if (root != nullptr) {
		inorder_check(root->right, activity, temp);
		if (root->activity == activity) {
			func3(temp, root->time);
			cout << "Time period: [" << temp->time << " - " << root->time << "]: " << root->activity << endl;
		}
		
		inorder_check(root->left, activity, temp);
	}
}

void print_single_activity(tree_node* root, const string& activity) {

	tree_node* temp;
	temp = root;

	inorder_check(root, activity, temp);

}

void print_all_activities(tree_node* root) {
	if (root != nullptr) {
		print_all_activities(root->left);
		cout << "["<<number_to_time(root->time) << "] - " << root->activity << endl;
		print_all_activities(root->right);
	}
}

void delete_tree(tree_node* root) {
	if (root == nullptr) {
		return;
		
		
	}	
	
	delete_tree(root->left);
	delete_tree(root->right);

	delete root;
	
	return;
}