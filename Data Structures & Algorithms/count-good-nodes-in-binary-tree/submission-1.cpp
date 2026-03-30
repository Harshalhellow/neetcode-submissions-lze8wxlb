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
    int goodnodes = 0;
    int goodNodes(TreeNode* root) {
        int maxsofar= INT_MIN;
        helper(root,maxsofar);
        return goodnodes;

    }
    void helper(TreeNode*root,int maxsofar){
        if(root==nullptr) return;
        if(root->val>=maxsofar) goodnodes++;
        maxsofar = max(root->val,maxsofar);
        helper(root->left,maxsofar);
        helper(root->right,maxsofar);
    }
};
