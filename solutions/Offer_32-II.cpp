/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t) {
                cur.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            else {
                if(q.size()) q.push(NULL); 
                res.push_back(cur); 
                cur.clear();
            }
        }
        return res;
    }
};