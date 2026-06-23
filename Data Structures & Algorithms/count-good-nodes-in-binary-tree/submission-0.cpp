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
    int dfs(TreeNode* root, int maxV) {
        if(!root) return 0;
        
        int t = maxV <= root->val;

        maxV = max(root->val, maxV);
        int l = dfs(root->left, maxV);
        int r = dfs(root->right, maxV);

        return t + l + r;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
