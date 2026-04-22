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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        bool flag = true;
        if(root) q1.push(root);
        while(!q1.empty() || !q2.empty()){
            if(flag){
                while(!q1.empty()){
                    TreeNode *nd = q1.front(); q1.pop();
                    temp.push_back(nd->val);
                    if(nd->left) q2.push(nd->left);
                    if(nd->right) q2.push(nd->right);
                }
                res.push_back(temp);
            }else{
                while(!q2.empty()){
                    TreeNode *nd = q2.front(); q2.pop();
                    temp.push_back(nd->val);
                    if(nd->left) q1.push(nd->left);
                    if(nd->right) q1.push(nd->right);
                }
                res.push_back(temp);
            }
            temp.clear();
            flag = !flag;
        }
        return res;
    }
};
