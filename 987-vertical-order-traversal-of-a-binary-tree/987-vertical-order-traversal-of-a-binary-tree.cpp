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
       map<int,vector<pair<int,int>>> mp;
    
    void dfs(TreeNode* root, int r, int c)
    {
        if(!root)   return;
        
        mp[c].push_back({r, root->val});
        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        
        vector<vector<int>> ans;
        int n;
        for(auto& m : mp)
        {
            sort(m.second.begin(), m.second.end());
            
            vector<int> vec;
            for(auto& p : m.second)
            {
                vec.push_back(p.second);
            }
            ans.push_back(vec);
            
        }
        return ans;
    }
};