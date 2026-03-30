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
    int longestpath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return longestpath;
    }
    int helper(TreeNode*root){
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        longestpath = max(longestpath,left+right);
        return 1+max(left,right);
    }


    // i need to return what the max path is each node can make without splitting
    // then i can just add node left and right if that beats the longest path if not then i just return the longest path plus 1 for the root node

};
