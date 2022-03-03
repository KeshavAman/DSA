/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
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
public:
    int findPosition(vector<int>& inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index >= n || inorderStart > inorderEnd) return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);
        
        root -> left = solve(inorder, preorder, index, inorderStart, position-1, n);
        root -> right = solve(inorder, preorder, index, position+1, inorderEnd, n);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};
