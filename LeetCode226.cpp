class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    TreeNode* result = root;
    if (root != nullptr) {
        TreeNode* albert = root->right;
        root->right = root->left;
        root->left = albert;
        invertTree(root->left);
        invertTree(root->right);
    }
    return result;
    }
};
