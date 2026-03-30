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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        rightsideheler(root,answer,0);
        return answer; 
        
    }
    void rightsideheler(TreeNode*root,vector<int>&right,int level){
        if(!root) return;
        if(right.size()==level) right.push_back(root->val);
        rightsideheler(root->right,right,level+1);
        rightsideheler(root->left,right,level+1);
    }
};


// at each level the right most subtree is the only node that matters
// dfs through go right left ode if that level already has a node dont add anything if not add stuff
