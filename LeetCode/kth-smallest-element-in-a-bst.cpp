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
    void inOrder(TreeNode* node, int k, vector<int>&vals) {
        if(node == nullptr || !k)return;
        inOrder(node->left, k, vals);
        vals.push_back(node->val), k--;
        inOrder(node->right, k,  vals);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>result;
        inOrder(root, k, result);
        return result[k - 1];
    }
};
