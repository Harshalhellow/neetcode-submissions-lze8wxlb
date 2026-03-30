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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootindex = find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        vector<int>preorderleft(preorder.begin()+1,preorder.begin()+1+rootindex);
        vector<int>preorderright(preorder.begin()+1+rootindex,preorder.end());
        vector<int>inorderleft(inorder.begin(), inorder.begin()+rootindex);
        vector<int>inorderright(inorder.begin()+rootindex+1,inorder.end());
        root->left = buildTree(preorderleft,inorderleft);
        root->right = buildTree(preorderright,inorderright);
        return root; 
        
    }
};
