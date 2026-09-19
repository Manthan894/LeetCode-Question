class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int leftHeight = height(root->left);
        if (leftHeight == -1){
            return -1;
        }
        int rightHeight = height(root->right);
        if (rightHeight == -1){
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna