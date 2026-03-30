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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int left = hieghtcal(root->left);
        int right = hieghtcal(root->right);
        int diamater = left+right;
        int potentialmax= max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(diamater,potentialmax);
    }

    int hieghtcal(TreeNode*root){
        if(root==nullptr) return 0;
        return 1+max(hieghtcal(root->left),hieghtcal(root->right));
    }
};


// each node gives back there 