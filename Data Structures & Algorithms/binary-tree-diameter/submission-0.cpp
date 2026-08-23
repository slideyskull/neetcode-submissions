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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findLength(root, diameter);
        return diameter - 1;
    }

    int findLength(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        int lengthL = findLength(root->left, diameter);
        int lengthR = findLength(root->right, diameter);
        diameter = max(diameter, lengthL + lengthR + 1);

        return max(lengthL, lengthR) + 1;
    }
};
