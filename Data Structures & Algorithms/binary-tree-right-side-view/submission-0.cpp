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
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
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

        cout << ans.size();
        vector<int> res;
        for(auto v : ans) res.push_back(v[v.size() - 1]);

        return res;
    }
};
