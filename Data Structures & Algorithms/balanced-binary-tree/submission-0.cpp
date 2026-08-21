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
int calculateHeight(TreeNode* node){
        if(node==NULL) return 0;
        int left_height = calculateHeight(node->left);
        int right_height = calculateHeight(node->right);
        int ans = max(left_height,right_height);
        return 1 + ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left_b_height = calculateHeight(root->left);
        int right_b_height = calculateHeight(root->right);
        int left = isBalanced(root->left);
        int right = isBalanced(root->right);
        if(abs(left_b_height-right_b_height) <=1 &&left && right){
            return true;
        }
        else {
            return false;
        }
    }
};