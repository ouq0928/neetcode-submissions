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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *nd = new TreeNode(val);
        if(!root) return nd;
        TreeNode *cur = root;
        while(cur){
            // cout << cur->val << "\n";
            if(cur->val > val && cur->left){
                // cout << 1;
                cur = cur->left;
                continue;
            }else if(cur->val > val && !cur->left){
                cur->left = nd;
                cur = cur->left;
                // cout << 2;
                break;
            }else if(cur->val < val && cur->right){
                cur = cur->right;
                // cout << 3;
                continue;
            }else if(cur->val < val && !cur->right){
                cur->right = nd;
                cur = cur->right;
                // cout << 4;
                break;
            }
        }
        return root;
    }
};