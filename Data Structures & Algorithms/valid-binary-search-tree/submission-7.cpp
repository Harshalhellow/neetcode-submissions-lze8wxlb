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
    bool isValidBST(TreeNode* root) {
        int mins = INT_MIN;
        int maxs = INT_MAX;
        return isValidBST_helper(root,mins,maxs);

    }
    bool isValidBST_helper(TreeNode*root,int mins,int maxs){
        if(!root) return true;
        if(!(root->val>mins&&root->val<maxs)) return false; 
        return isValidBST_helper(root->left,mins,min(maxs,root->val)) && isValidBST_helper(root->right,max(mins,root->val),maxs);
    }
};
