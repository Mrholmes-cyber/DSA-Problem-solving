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
    bool findTarget(TreeNode* root, int k) {

        stack<TreeNode*> s1, s2;

        TreeNode* curr1 = root;
        TreeNode* curr2 = root;

        // Initialize ascending iterator
        while (curr1 != NULL) {
            s1.push(curr1);
            curr1 = curr1->left;
        }

        // Initialize descending iterator
        while (curr2 != NULL) {
            s2.push(curr2);
            curr2 = curr2->right;
        }

        // Continue until both iterators meet
        while (!s1.empty() && !s2.empty() &&
               s1.top() != s2.top()) {

            int a = s1.top()->val;
            int b = s2.top()->val;

            int sum = a + b;

            if (sum == k) {
                return true;
            }

            // Need a bigger first value
            if (sum < k) {

                TreeNode* node = s1.top();
                s1.pop();

                node = node->right;

                while (node != NULL) {
                    s1.push(node);
                    node = node->left;
                }

            }
            // Need a smaller second value
            else {

                TreeNode* node = s2.top();
                s2.pop();

                node = node->left;

                while (node != NULL) {
                    s2.push(node);
                    node = node->right;
                }
            }
        }

        return false;
    }
};