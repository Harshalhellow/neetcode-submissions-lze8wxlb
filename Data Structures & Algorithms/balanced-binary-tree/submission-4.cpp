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
        if(isBalancedhelper(root)<0) return false;
        else return true; 
    }

    int isBalancedhelper(TreeNode* root){
        if(!root) return 0;
        int left = isBalancedhelper(root->left);
        int right = isBalancedhelper(root->right);
        if(left<0||right<0) return -1;
        if(abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
};
