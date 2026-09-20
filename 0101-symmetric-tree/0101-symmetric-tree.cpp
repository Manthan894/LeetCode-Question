class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr){
            return true;
        }
        if (left == nullptr || right == nullptr){
            return false;
        }
        if (left->val != right->val){
            return false;
        }
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna