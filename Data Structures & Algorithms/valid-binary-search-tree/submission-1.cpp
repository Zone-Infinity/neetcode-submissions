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
    bool dfs(TreeNode* root, int minV, int maxV) {
        if (!root) return true;

        if (root->val <= minV || root->val >= maxV) return false;
        return dfs(root->left, minV, root->val) && dfs(root->right, root->val, maxV);
    }

   public:
    bool isValidBST(TreeNode* root) { return dfs(root, INT_MIN, INT_MAX); }
};
