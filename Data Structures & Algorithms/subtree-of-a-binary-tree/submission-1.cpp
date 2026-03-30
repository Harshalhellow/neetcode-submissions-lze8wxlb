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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr) return true;
        if(root==nullptr) return false;
        if(checker(root,subRoot)) return true; 
        else return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }

    bool checker(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr&&subRoot==nullptr) return true;
        if(root!=nullptr&&subRoot!=nullptr&&root->val==subRoot->val) return checker(root->left,subRoot->left)&& checker(root->right,subRoot->right);
        else return false; 

    }
};

// go through the tree comparing the values for the same root if you find the same root
// use a different fucntion to check if its the same thing if not continue checking 

