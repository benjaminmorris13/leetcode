class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        if (root == nullptr) {
            return result;
        }
        else {
            return std::max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        }
    }
};
