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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()){
            int len = q.size();
            TreeNode *rmost = nullptr;
            for(int i = 0; i < len; i++){
                rmost = q.front(); q.pop();
                if(rmost->left) q.push(rmost->left);
                if(rmost->right) q.push(rmost->right);
            }
            if(rmost){
                res.push_back(rmost->val);
            }
        }
        return res;
    }
};
