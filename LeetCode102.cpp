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
#include <queue>
#include <cmath>
class Solution {
public:
    struct solu {
        TreeNode* node;
        int rank;
        solu(): node{nullptr}, rank{0} {}
        solu(TreeNode* x, int y): node{x}, rank{y} {}
    };

    queue<solu> bfs(TreeNode* root) {
        solu first = solu(root, 0);
        queue<solu> visit {};
        visit.push(first);
        queue<solu> result {};
        while (!(visit.empty())) {
            result.push(visit.front());
            solu current = visit.front();
            if (current.node->left != nullptr) {
                visit.push(solu(current.node->left, current.rank + 1));
            }
            if (current.node->right != nullptr) {
                visit.push(solu(current.node->right, current.rank + 1));
            }
            visit.pop();
        }
        return result;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<solu> values {};
        vector<vector<int>> result {};
        if (root == nullptr) {
            return result;
        }
        else {
            values = bfs(root);
        }
        while (!(values.empty())) {
            solu current = values.front();
            if (result.size() <= current.rank) {
                vector<int> newlevel {current.node->val};
                result.push_back(newlevel);
                values.pop();
            }
            else {
                result[current.rank].push_back(current.node->val);
                values.pop();
            }
        }
        return result;
    }
};
