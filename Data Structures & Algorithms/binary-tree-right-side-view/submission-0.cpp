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
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        if(root) q1.push(root);
        bool flag = true;
        while(!q1.empty() || !q2.empty()){
            if(flag){
                TreeNode *cur;
                while(!q1.empty()){
                    cur = q1.front(); q1.pop();
                    if(cur->left) q2.push(cur->left);
                    if(cur->right) q2.push(cur->right);
                }
                res.push_back(cur->val);
            }else{
                TreeNode *cur;
                while(!q2.empty()){
                    cur = q2.front(); q2.pop();
                    if(cur->left) q1.push(cur->left);
                    if(cur->right) q1.push(cur->right);
                }
                res.push_back(cur->val);
            }
            flag = !flag;
        }
        return res;
    }
};
