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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        bool answer;  
        int left = hieghtcal(root->left);
        int right = hieghtcal(root->right);
        int maxinum = max(left,right);
        int minium = min(left,right);
        if(maxinum>minium+1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }

    int hieghtcal(TreeNode*root){
        if(root==nullptr) return 0;
        return 1+max(hieghtcal(root->left),hieghtcal(root->right));
    }

};
