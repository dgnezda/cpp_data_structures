//
//  tree_node2.cpp
//  data_structures - tree
//
//  Created by Domen Gnezda on 10. 11. 2023.
//

#include <iostream>
#include <vector>
using namespace std;


template<typename V>
class tree_node {
	V value;
	vector<tree_node<V>*> children;

public:
	tree_node(V const &val)
	: value(val)
	{}

	void add_child(tree_node<V> &child) {
		children.push_back(&child);
	}

	void print() {
		cout << "Tree node: " << value << endl;
		cout << "\t|" << endl;
		for (int i = 0; i < children.size(); ++i) {
			cout << "\t|- " << children.at(i)->val() << endl;
		}
	}

	V get_child_at(int index) {
		return children.at(index)->val();
	}

	V val() {
		return value;
	}
};


int main() {
	tree_node<int> root {0};
	tree_node<int> child1 {1};
	tree_node<int> child2 {2};
	tree_node<int> child3 {3};
	root.add_child(child1);
	root.add_child(child2);
	root.add_child(child3);
	root.print();
	cout << root.val() << endl;
	for (int i = 0; i < 3; ++i) {
		cout << root.get_child_at(i) << endl;
	}
	return 0;
}