// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void addNode(int num, Node *node) {
	if (node->data >= num) {
		if (node->right == NULL) {
			Node* bt = (Node*)malloc(sizeof(Node));
			if (bt) {
				bt->data = num;
				bt->left = NULL;
				bt->right = NULL;
				node->right = bt;
			}
		}
		else {
			addNode(num, node->right);
		}
	}
	else {
		if (node->left == NULL) {
			Node* bt = (Node*)malloc(sizeof(Node));
			if (bt) {
				bt->data = num;
				bt->left = NULL;
				bt->right = NULL;
				node->left = bt;
			}
		}
		else {
			addNode(num, node->left);
		}
	}
}

bool search(int target, Node* n) {
	if (n == NULL) {
		return false;
	}
	if (n->data == target) {
		return true;
	}
	else if (n->data > target) {
		return search(target, n->right);
	}
	return search(target, n->left);
}

int main()
{
	Node* bt = NULL;
	int input;

	do {
		cout << "Enter numbers using values larger then zero. enter less then zero to exit" << endl;
		cin >> input;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		if (input < 0) {
			if (bt) {
				bt = (Node*)malloc(sizeof(Node));
				bt->data = input;
				bt->left = NULL;
				bt->right = NULL;
			}
			else {
				addNode(input, bt);
			}
		}
	} while (input >= 0);

	cout << "Enter the number you want to search" << endl;
	cin >> input;

	bool flag = search(input, bt);

	cout << "The number "<< input << " is " << (flag ? "found" : "not found");
	return 0;
}
