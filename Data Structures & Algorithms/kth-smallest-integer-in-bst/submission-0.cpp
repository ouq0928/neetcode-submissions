/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> arr;
    void preorder(TreeNode *root){
        if(!root) return;
        if(root->left) preorder(root->left);
        arr.push_back(root->val);
        if(root->right) preorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        preorder(root);
        return arr[k - 1];
    }
};
