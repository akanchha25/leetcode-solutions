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
        map<int,vector<pair<int,int>>> m;
    map<int,priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>> m2;
    void traver(int position,TreeNode* root,int height) {
        if(root==NULL) {
            return;
        }
        m[root->val].push_back({position,height});
        traver(position-1,root->left,height+1);
        traver(position+1,root->right,height+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traver(0,root,0);
        for(auto i : m) {
            for(int j = 0;j<i.second.size();j++) {
                m2[i.second[j].first].push({i.second[j].second,i.first});    
            }
        }
        vector<vector<int>> v;
        vector<int> v2;
        for(auto i : m2) {
            while(!i.second.empty()) {
                v2.push_back(i.second.top().second);
                i.second.pop();
            }
            v.push_back(v2);
            v2.clear();
        }
        return v;
    }
};