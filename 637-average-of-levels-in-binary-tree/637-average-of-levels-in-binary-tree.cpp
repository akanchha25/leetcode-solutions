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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(!root->left && !root->right) return {root->val/1.0};
        
        vector<double> res;
        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        double count = 0, sum = 0;
        double avg;  
        
        while(!q.empty()){
            int len = q.size();

            while(len--){
                 TreeNode* temp = q.front();
                 q.pop();
                count++;
                sum += temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            avg = sum/(count*1.0);
            count = 0;
            sum = 0;
            res.push_back(avg);
        }
        
        return res;
    }
};
