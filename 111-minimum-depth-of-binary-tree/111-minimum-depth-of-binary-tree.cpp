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
    int minDepth(TreeNode* root) {
         if(root==NULL){
            return 0;
        }
        int height_of_left_subtree=minDepth(root->left);
        int height_of_right_subtree=minDepth(root->right);
        
        if(root->left==NULL)
            return height_of_right_subtree+1;
        else if(root->right==NULL)
            return height_of_left_subtree+1;
        
        return min(height_of_left_subtree,height_of_right_subtree)+1;
        
    }
};