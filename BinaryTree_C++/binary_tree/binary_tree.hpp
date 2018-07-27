#pragma once
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include"node.hpp"
class binary_tree {
public:
	binary_tree();

	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(node*);
	void print_preorder();
	void preorder(node*);
	void print_postorder();
	void postorder(node*);
	void insert(int);
	node *remove(node*,int);
	void destroy_tree();
	void destroy(node*);
	bool search(int);

	node *root;

};
node* minValue(node*);
#endif

