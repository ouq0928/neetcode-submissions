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
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(p == nullptr && q == nullptr) return true;
        if((p != nullptr && q == nullptr) || (q != nullptr && p == nullptr)) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root, subRoot)) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front(); q.pop();
            if(isSameTree(node->left, subRoot) || isSameTree(node->right, subRoot)) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }   
        return false;
    }
};
