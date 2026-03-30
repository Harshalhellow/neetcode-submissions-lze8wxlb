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
        return valid(root,INT_MIN,INT_MAX);
        
    }

    bool valid(TreeNode* root, int smallest, int largest){
        if(root==nullptr) return true;
        if(!(smallest<root->val&&root->val<largest)) return false;
        return valid(root->left,smallest,root->val) && valid(root->right,root->val,largest);
    }
};
