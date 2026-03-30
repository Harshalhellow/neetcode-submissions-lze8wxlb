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
        if(!root&&subRoot!=nullptr) return false; 
        if(root->val==subRoot->val&& issame(root,subRoot)) return true; 
        else return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool issame(TreeNode* p, TreeNode* q){
        if(!p&&!q) return true; 
        if(!p||!q) return false;
        if(p->val!=q->val) return false;
        return issame(p->left,q->left) && issame(p->right,q->right);
    }

    // find root
    // identify  if it and the sub root is the same 
};
