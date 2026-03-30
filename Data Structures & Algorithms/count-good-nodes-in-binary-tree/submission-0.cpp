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
    int goodnodes = 0;
    int goodNodes(TreeNode* root) {
        vector<int> temp;
        temp.push_back(root->val);
        helper(root,temp);
        return goodnodes--;
    }
    void helper(TreeNode*root,vector<int>temp){
        if(root==nullptr) return;
        for(int i=0; i<temp.size(); i++){
            if(root->val<temp[i]) break;
            if(root->val>=temp[i]&&i==temp.size()-1) goodnodes++;
        }
        temp.push_back(root->val);
        helper(root->right,temp);
        helper(root->left,temp);
    }

    // create a temp vector 
    //dfs through the whole thing going right 
    // when looking at a node check through the whole vector if a greate value doenst exsist ++counter
    // make sure to make a copy of a vector each time 
    
};
