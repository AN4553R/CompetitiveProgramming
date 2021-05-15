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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;       
        queue<pair<TreeNode*, int>>q; // node, level
        if(root == nullptr) return {};
        q.push({root, 0});
        
        pair<TreeNode*, int>prev {root, 0};
        
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.second != prev.second) {
                result.push_back(prev.first->val);
            }
        
            prev = cur;
            
            if(cur.first != nullptr && cur.first->left != nullptr) {
                q.push({cur.first->left, cur.second + 1});
            }
            if(cur.first != nullptr && cur.first->right != nullptr) {
                q.push({cur.first->right, cur.second + 1});
            }
            if(q.empty()) {
                result.push_back(cur.first->val);
            }
            
        }
        return result;
    }
};
