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
    pair<TreeNode *, TreeNode *> leftmost(TreeNode *root){
        pair<TreeNode *, TreeNode *> p = {nullptr, nullptr};
        if(root->right){
            p.first = root->right;
            p.second = root;
        }
        else return p;
        while(p.first->left){
            p.second = p.first;
            p.first = p.first->left;
        }
        return p;
    }
    pair<TreeNode *, TreeNode *> rightmost(TreeNode *root){
        pair<TreeNode *, TreeNode *> p = {nullptr, nullptr};
        if(root->left){
            p.first = root->left;
            p.second = root;
        }
        else return p;
        while(p.first->right){
            p.second = p.first;
            p.first = p.first->right;
        }
        return p;
    }
    void replace(pair<TreeNode *, TreeNode *> p){
        auto lmost = leftmost(p.first);
        auto rmost = rightmost(p.first);
        if(!lmost.first && !rmost.first){
            if(p.first == p.second->left){
                p.second->left = nullptr;
            }else p.second->right = nullptr;
            delete p.first;
            return;
        }
        pair<TreeNode *, TreeNode *> higher;
        if(lmost.first && rmost.first){
            higher = (lmost.first->val > rmost.first->val) ? lmost : rmost;
        }else if(lmost.first) higher = lmost;
        else if(rmost.first) higher = rmost;
        p.first->val = higher.first->val;
        replace(higher);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        queue<pair<TreeNode *,TreeNode *>> q;
        TreeNode *dummy = new TreeNode(0, nullptr, root);
        if(root) q.push({root, dummy});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur.first->val == key){
                replace(cur);
                break;
            }
            if(cur.first->left) {
                q.push({cur.first->left, cur.first});
            }
            if(cur.first->right) q.push({cur.first->right, cur.first});
        }
        return dummy->right;
    }
};