//
//  tree_node.cpp
//  data_structures - binary tree
//
//  Created by Domen Gnezda on 31. 10. 2023.
//


#include <iostream>

using namespace std;

template<typename V>
class tree_node {
	V value;
	tree_node<V> *left_child {nullptr};
	tree_node<V> *right_child {nullptr};

public:
	tree_node(V const &val)
	: value(val)
	{}

	void set_left_child(tree_node<V> &l_child) {
		left_child = &l_child;
	}

	void set_right_child(tree_node<V> &r_child) {
		right_child = &r_child;
	}

	void print() {
		cout << "Root node: " << value << endl;
		cout << "\t|" << endl;
		cout << "\t|-Left child: " << left_child->value << endl;
		cout << "\t|-Right child: " << right_child->value << endl;
	}
};


int main() {
	tree_node<int> root {0};
	tree_node<int> left {1};
	tree_node<int> right {2};
	root.set_left_child(left);
	root.set_right_child(right);
	root.print();
	
	return 0;
}