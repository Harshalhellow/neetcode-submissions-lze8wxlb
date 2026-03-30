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
        vector<vector<int>> answer; 
        vectorhelper(root,answer,1);
        return answer; 
        
    }

    void vectorhelper(TreeNode*root,vector<vector<int>>&answers, int level){
        if(!root) return;
        if(answers.size()<level) {
            answers.push_back(vector<int>{});
            answers[level-1].push_back(root->val);
        }
        else answers[level-1].push_back(root->val);
           
        
        vectorhelper(root->left,answers,level+1);
        vectorhelper(root->right,answers,level+1);

    }
};
