#include"binary_tree.hpp"

binary_tree::binary_tree() {
	root = NULL;
}

void binary_tree::insert(int d) {
	node* t = new node;
	node* prev;
	t->number = d;
	t->left = NULL;
	t->right = NULL;
	prev = NULL;

	if (isEmpty())
		root = t;
	else {
		node* cur;
		cur = root;
		while (cur != NULL) {
			prev = cur;
			if (t->number > cur->number)
				cur = cur->right;
			else
				cur = cur->left;
		}

		if (t->number < prev->number)
			prev->left = t;
		else
			prev->right = t;

	}
}

node* binary_tree::remove(node *root,int d) {
	if (root == NULL)
		return root;

	if (d < root->number)
		root->left = remove(root->left, d);
	else if (d > root->number)
		root->right = remove(root->right, d);
	else {
		if (root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		node* temp = minValue(root->right);
		root->number = temp->number;
		root->right = remove(root->right, temp->number);
	}
	return root;
}
node* minValue(node* p) {
	node* cur = p;
	while (cur->left != NULL)
		cur = cur->left;
	return cur;
}
void binary_tree::print_inorder() {
	inorder(root);
}

void binary_tree::inorder(node *p) {
	if (p != NULL) {
		if (p->left) 
			inorder(p->left);
		cout << " " << p->number << " ";
		if (p->right)
			inorder(p->right);
	}
	else return;
}

void binary_tree::print_preorder() {
	preorder(root);
}

void binary_tree::preorder(node *p) {
	if (p != NULL) {
		cout << " " << p->number << " ";
		if (p->left)
			inorder(p->left);
		if (p->right)
			inorder(p->right);
	}
	else return;
}

void binary_tree::print_postorder() {
	postorder(root);
}

void binary_tree::postorder(node *p) {
	if (p != NULL) {
		if (p->left)
			inorder(p->left);
		if (p->right)
			inorder(p->right);
		cout << " " << p->number << " ";
	}
	else return;
}

void binary_tree::destroy_tree() {
	destroy(root);
}

void binary_tree::destroy(node *p) {
	if (p != NULL) {
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

bool binary_tree::search(int d) {
	node* tmp = root;
	while (tmp != NULL) {
		if (tmp->number == d)
			break;
		if (d > tmp->number) {
			tmp = tmp->right;
		}
		else if (d < tmp->number) {
			tmp = tmp->left;
		}
	}
	if (tmp == NULL)
		return false;
	if (tmp->number == d)
		return true;
	return false;
}