#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int item) {
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

int findDepth(Node* root, int x) {
	if (root == NULL)
		return -1;

	int dist = -1;

	if ((root->data == x) || (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0)
		return dist + 1;

	return dist;
}

int findHeightUtil(Node* root, int x, int& height) {
	if (root == NULL) {
		return -1;
	}

	int leftHeight = findHeightUtil(root->left, x, height);
	int rightHeight = findHeightUtil(root->right, x, height);

	int ans = max(leftHeight, rightHeight) + 1;

	if (root->data == x)
		height = ans;

	return ans;
}

int findHeight(Node* root, int x) {
	int h = -1;
	int maxHeight = findHeightUtil(root, x, h);
	return h;
}

int main() {
	Node* root = newNode(5);
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->left->right = newNode(25);
	root->left->right->right = newNode(45);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

	int k = 25;

	cout << "Depth: " << findDepth(root, k) << "\n";
	cout << "Height: " << findHeight(root, k);

	return 0;
}
