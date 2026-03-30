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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> answers;
        kthsmallest(root,answers);
        return answers[k-1];
        
    }
    void kthsmallest(TreeNode*root, vector<int>&answer){
        if(!root) return;
        kthsmallest(root->left,answer);
        answer.push_back(root->val);
        kthsmallest(root->right,answer);
    }


};
