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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        // q.push(new TreeNode(-1));
        // vector<int> level;

        // while (!q.empty()) {
        //     TreeNode* f = q.front();
        //     q.pop();

        //     if (f->left) {
        //         q.push(f->left);
        //     }
        //     if (f->right) {
        //         q.push(f->right);
        //     }

        //     if (f->val == -1) {
        //         if(q.empty()) q.push(new TreeNode(-1));
        //         ans.push_back(level);
        //         level.clear();
        //     } else
        //         level.push_back(f->val);
        // }

        while (!q.empty()) {
            vector<int> level;
            queue<TreeNode*> q2;

            while (!q.empty()) {
                TreeNode* f = q.front();
                q.pop();
                level.push_back(f->val);
                if(f->left) q2.push(f->left);
                if(f->right) q2.push(f->right);
            }

            ans.push_back(level);

            while(!q2.empty()) {
                q.push(q2.front());
                q2.pop();
            }
        }

        return ans;
    }
};
