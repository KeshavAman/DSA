/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
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
    int findPosition(vector<int>& inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postorderIndex, int inorderStart, int inorderEnd, int n){
        if(postorderIndex < 0 || inorderStart > inorderEnd) return NULL;
        
        int element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root -> right = solve(inorder, postorder, postorderIndex, position+1, inorderEnd, n);
        root -> left = solve(inorder, postorder, postorderIndex, inorderStart, position-1, n);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        TreeNode* ans = solve(inorder, postorder, postorderIndex, 0, n-1, n);
        return ans;
    }
};
