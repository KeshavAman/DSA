/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

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
private:
    bool isValid(TreeNode *root,long long mini,long long maxi){
        if(root == NULL)return true;
        if(root->val>mini && root->val<maxi){
        bool left=isValid(root->left,mini,root->val);
        bool right=isValid(root->right,root->val,maxi);    
            return left && right;
        }
        else{
        return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int mini=-9223372036854775808,
        maxi=9223372036854775807;
        return isValid(root, mini, maxi);
    }
};
