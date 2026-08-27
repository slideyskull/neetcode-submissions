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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pstack;
        stack<TreeNode*> qstack;

        pstack.push(p);
        qstack.push(q);

        while (!pstack.empty()) {
            auto ptop = pstack.top();
            auto qtop = qstack.top();
            pstack.pop();
            qstack.pop();
            if (ptop == nullptr && qtop == nullptr) {
                continue;
            } else if (ptop == nullptr || qtop == nullptr) {
                return false;
            } else if (ptop->val != qtop->val) {
                return false;
            }

            pstack.push(ptop->left);
            pstack.push(ptop->right);
            qstack.push(qtop->left);
            qstack.push(qtop->right);
        }

        return qstack.empty();
    }
};
