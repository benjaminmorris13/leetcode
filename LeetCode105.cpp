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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        else if (inorder.size() == 1) {
            preorder.erase(preorder.begin());
            TreeNode* result = new TreeNode(inorder.at(0));
            return result;
        }
        else {
            vector<int>::iterator root = preorder.begin();
            TreeNode* result = new TreeNode(*root);
            vector<int> newin {};
            while (1) {
                if (*root == inorder.front()) {
                    inorder.erase(inorder.begin());
                    break;
                }
                else {
                    newin.push_back(inorder.front());
                    inorder.erase(inorder.begin());
                }
            }
            preorder.erase(root);
            result->left = buildTree(preorder, newin);
            result->right = buildTree(preorder, inorder);
            return result;
        }
    }
};
