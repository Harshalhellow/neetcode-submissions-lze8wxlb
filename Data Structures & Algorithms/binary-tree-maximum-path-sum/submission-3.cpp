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
    int maxpath = INT_MIN; 
    int maxPathSum(TreeNode* root) {
        int caller = maxPathSumhelper(root);
        return maxpath;
    }

    int maxPathSumhelper(TreeNode*root){
        if(!root) return 0;
        int left = maxPathSumhelper(root->left);
        int right =maxPathSumhelper(root->right);
        maxpath = max(maxpath,max(0,left)+max(0,right)+root->val);
        return root->val+max(max(0,left),max(0,right));
    }
};

// ret
