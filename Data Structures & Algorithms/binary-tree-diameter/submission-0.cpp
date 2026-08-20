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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int left_height = calculateHeight(root->left);
        int right_height = calculateHeight(root->right);
        int diameter = left_height + right_height;
        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);
        return max({diameter,left_diameter,right_diameter});
    }
};