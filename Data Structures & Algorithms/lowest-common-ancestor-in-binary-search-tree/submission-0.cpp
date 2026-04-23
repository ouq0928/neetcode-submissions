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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lower = (p->val < q->val) ? p : q;
        TreeNode *higher = (lower == p) ? q : p;
        while(root){
            if(root->val == p->val || root->val == q->val){
                return root;
            }else if(root->val > lower->val && root->val > higher->val){
                root = root->left;
            }else if(root->val < lower->val && root->val < higher->val){
                root = root->right;
            }else if(root->val > lower->val && root->val < higher->val){
                return root;
            }
        }
    }
};
