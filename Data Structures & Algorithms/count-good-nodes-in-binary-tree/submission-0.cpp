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
    int res = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, -101);
        return res;
    }
    void dfs(TreeNode *root, int cur_max){
        if(!root) return;
        if(root->val >= cur_max){
            res++;
        }
        cur_max = max(root->val, cur_max);
        if(root->left) dfs(root->left, cur_max);
        if(root->right) dfs(root->right, cur_max);
    }
};
