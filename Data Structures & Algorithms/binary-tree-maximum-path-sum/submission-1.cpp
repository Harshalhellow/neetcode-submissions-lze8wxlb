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
    int maxPathSum(TreeNode* root) {
        int results = root->val; 
        dfs(root,results);
        return results;
    }
    int dfs(TreeNode* root,int &results){
        if(!root) return 0; 
        int maxleft = max(dfs(root->left,results),0);
        int maxright = max(dfs(root->right,results),0);
        results = max(results, root->val+maxleft+maxright);
        return root->val + max(maxleft,maxright);
    }


};
