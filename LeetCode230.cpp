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
    vector<int> vectorize(TreeNode* root) {
        if (root == nullptr) {
            return (vector<int> {});
        }
        else {
            vector<int> left = vectorize(root->left);
            vector<int> right = vectorize(root->right);
            left.push_back(root->val);
            for (int elem : right) {
                left.push_back(elem);
            }
            return left;
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vectored = vectorize(root);
        TreeNode* current = root;
        return (vectored[k - 1]);
    }
};
