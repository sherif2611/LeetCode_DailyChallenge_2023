// Author: Sherif Ibrahim
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
    /*
                                                                              1
                                                                       2              3
                                                                  4       5       6     -1
                                                               -1  -1  -1 -1  -1 -1  -1 -1
                                                                    
                                                                    // -1 == NULL
 */
    bool ok=true;
    map<int,int>mp;
    vector<vector<int>>v;                                 
    // we will store the values in 2d vector v 
    void solve(TreeNode* root,int i){
        if(root==NULL){
            if(!mp[i])
            v.push_back(vector<int>()),mp[i]=1;
            v[i].push_back(-1);
            return;
        }
        if(!mp[i])
        v.push_back(vector<int>()),mp[i]=1;
        v[i].push_back(root->val);
        solve(root->left,i+1);
        solve(root->right,i+1);
    }
    // we will check if tree is complete binary tree or not
    bool isCompleteTree(TreeNode* root) {
        solve(root,0);
        // if any value in tree is -1 (NULL) execpt leaves ,then the tree is not complete binary tree 
        for(int i=0;i<v.size()-2;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==-1)ok=0;
            }
        }
        map<int,int>mp2;
        // if any value in leaves equal -1 and there is value not equal to -1 and its position > position of -1 , then ths tree is not complete binary tree 
        for(int i=0;i<v[v.size()-2].size();i++){
            mp2[v[v.size()-2][i]]=1;
            if(mp2[-1]&&v[v.size()-2][i]!=-1){
                ok=0;
            }
        }
        return ok;
    }
};
