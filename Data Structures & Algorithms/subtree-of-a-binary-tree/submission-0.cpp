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
    // Helper function: Checks if two trees are exactly identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: If both are null, they are identical
        if (!p && !q) {
            return true;
        }
        // Base case 2: If one is null and the other isn't, they are not identical
        if (!p || !q) {
            return false;
        }
        // Base case 3: If values don't match, they are not identical
        if (p->val != q->val) {
            return false;
        }

        // Recursive step: Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // Main function: Checks if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If root is null, subRoot cannot be a subtree (given subRoot is never null)
        if (!root) {
            return false;
        }

        // Step 1: Check if the current 'root' node and its descendants are identical to 'subRoot'
        if (isSameTree(root, subRoot)) {
            return true;
        }

        // Step 2: If not, recursively check if 'subRoot' is a subtree of the left child or the right child
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
