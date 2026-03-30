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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string results;
        dfs(root,results);
        return results;
    }

    void dfs(TreeNode*root,string &results){
        if(!root) {
            results.append(",N");
            return;
        } 
        else  results.append(","+to_string(root->val));
        dfs(root->left,results);
        dfs(root->right,results);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return decorder(data,index);
    }

    TreeNode* decorder(string &data,int &index){
        string tonum;
        int number;
        if(data[index]==','){
            index++;
            while(data[index]!=','&&data[index]!='N'){
                tonum +=data[index];
                index++;
            }
            if(data[index]!='N') number = stoi(tonum);
        }
        
        if(data[index]!='N') {
            TreeNode* root = new TreeNode(number);
            root->left = decorder(data,index);
            root->right = decorder(data,index);
            return root;
        }
        else {
            index++;
            return nullptr;
        }

    }
};
