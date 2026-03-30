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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> answer; 
        levelorderhelper(root,level,answer);
        return answer; 
    }

    void levelorderhelper(TreeNode*root,int level,vector<vector<int>>&ans){
        if(root==nullptr) return;
        if(root!=nullptr){
            if(ans.size()<=level){
                ans.push_back({});
            }
             ans[level].push_back(root->val);
        }
        levelorderhelper(root->left,level+1,ans),
        levelorderhelper(root->right,level+1,ans);
    }
};
