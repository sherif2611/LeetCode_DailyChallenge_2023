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
     * we will store the left subtree next to the root in a vector and The right subtree next to the root in another vector
     * then we will compare each element with its opposite.
     */
    // We defined an map of adress to set the address of each element whether it was visited or not.
    map<void*,bool>mp,mp2;
    // vector l to sore the left subtree in it and r to right subtree
    vector <int>l,r;
    // to store all elemets of left subtree 
    void left(TreeNode* root){
        // if the node equal NULL we store -1 instead of NULL and return
        if(root==NULL){
            l.push_back(-1);
            return;
        }
        // if map of node adress not equal 1 then i store the element of this node Otherwise,If this place has been visited before then the item in it will not be stored
        if(!mp[&(root->val)])
        l.push_back(root->val),mp[&(root->val)]=1;
        else return;
        left(root->left);
        left(root->right);
    }
    // we reept the same process in another subtree
    void right(TreeNode* root){
        if(root==NULL){
            r.push_back(-1);
            return;
        }
        if(!mp2[&(root->val)])
        r.push_back(root->val),mp2[&(root->val)]=1;
        else return;
        right(root->right);
        right(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        left(root);
        right(root);
        // we will compare all elements
        for(int i=0;i<l.size();i++){
            if(l[i]!=r[i])return 0;
        }
        return 1;
    }
};
