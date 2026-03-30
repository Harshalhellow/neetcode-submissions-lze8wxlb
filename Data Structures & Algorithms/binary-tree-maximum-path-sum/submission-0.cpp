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
    int results = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return results;
    }
    int getmax(TreeNode*root){
        if(!root) return 0;
        int left = getmax(root->left);
        int right = getmax(root->right);
        int path = root->val + max(left,right);
        return max(0,path);

    }
    void dfs(TreeNode*root){
        if(!root)return;
        int left = getmax(root->left);
        int right = getmax(root->right);
        results = max(results, root->val+left+right);
        dfs(root->left);
        dfs(root->right);
    }


};


// there are three options
// u can have just root
// root and left
// root and right 
// for each dfs thing u travel just return ur highest value 
// if all values are negative 