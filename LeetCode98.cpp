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
    bool isValidBST(TreeNode* root, long long upper=2147483648, long long lower=-2147483649) {
        if (root == nullptr) {
            return true;
        }
        else if ((root->val < upper) && (root->val > lower)) {
            return (isValidBST(root->left,(long long) root->val, lower) && (isValidBST(root->right, upper, (long long) root->val)));
        }
        else {
            return false;
        }
    }
};
