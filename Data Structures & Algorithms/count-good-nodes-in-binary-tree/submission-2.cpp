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

    int goodNodes(TreeNode* root) {
        int goodnodes = 0; 
        int maxsofar = INT_MIN;
        goodnodeshelper(root,goodnodes,maxsofar);
        return goodnodes;   
    }

    void goodnodeshelper(TreeNode*root, int &goodnodes, int maxsofar){
        if(!root) return;
        if(root->val>=maxsofar) goodnodes++;
        maxsofar = max(maxsofar,root->val);
        goodnodeshelper(root->left,goodnodes,maxsofar);
        goodnodeshelper(root->right,goodnodes,maxsofar);

    }

};
