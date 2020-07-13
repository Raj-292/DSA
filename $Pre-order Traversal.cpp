#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void preorder(Node* temp) {
	if (!temp) {
		return;
	}

	cout << temp->data << ' ';
	preorder(temp->left);
	preorder(temp->right);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	Node* root = new Node(10);
	root->left = new Node(11);
	root->left->left = new Node(7);
	root->right = new Node(9);
	root->right->left = new Node(15);
	root->right->right = new Node(8);

	cout << "Pre-order traversal of the Tree: ";
	preorder(root);

}
