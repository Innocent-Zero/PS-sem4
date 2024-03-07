#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool ans;

    int getHt(TreeNode* root){
        if(!root) return 0;
        int lst = getHt(root->left);
        int rst = getHt(root->right);
        if(abs(lst-rst) > 1) ans = false;
        return 1 + max(lst, rst);
    }

    bool isBalanced(TreeNode* root) {
        ans = true;
        getHt(root);
        return ans;
    }
};

// Function to create a new node
TreeNode* newNode(int item) {
    TreeNode* temp = new TreeNode(item);
    return temp;
}

int main() {
    Solution sol;

    // Binary Tree Formation
    TreeNode* root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->left->right->right = newNode(45);
    root->right->left = newNode(30);
    root->right->right = newNode(35);

    if (sol.isBalanced(root)) {
        cout << "Tree is balanced." << endl;
    } else {
        cout << "Tree is not balanced." << endl;
    }

    return 0;
}
