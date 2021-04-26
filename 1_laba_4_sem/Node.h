#include<iostream>
#pragma once
#ifndef Node_h
using namespace std;
enum COLOR { RED, BLACK };
template<typename T1, typename T2>
class Node {
public:
	T1 key;
	T2 data;
	COLOR color;
	Node<T1, T2>* left, * right, * parent;
	Node(T1 key, T2 data) : key(key), data(data) {
		parent = left = right = NULL;
		color = RED;
	}
	~Node() = default;
	
		Node<T1, T2> * uncle() {
		if (parent == NULL || parent->parent == NULL)
			return NULL;
		if (parent->isOnLeft())
			return parent->parent->right;
		else
			return parent->parent->left;
	}
	bool isOnLeft() { return this == parent->left; }
	Node<T1, T2>* sibling() {
		if (parent == NULL)
			return NULL;
		if (isOnLeft())
			return parent->right;
		return parent->left;
	}
	void moveDown(Node<T1, T2>* nParent) {
		if (parent != NULL) {
			if (isOnLeft()) {
				
					parent->left = nParent;
			}
			else {
				parent->right = nParent;
			}
		}
		nParent->parent = parent;
		parent = nParent;
	}
	bool has0Child() {
		return (left != NULL && left->color == 0) ||
			(right != NULL && right->color == 0);
	}
};
#define Node_h
#endif 