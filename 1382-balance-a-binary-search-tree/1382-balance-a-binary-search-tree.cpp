class Solution {
public:
    vector<int> nums;

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;

        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int low, int high) {
        if(low > high)
            return NULL;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(low, mid - 1);
        root->right = build(mid + 1, high);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);

        return build(0, nums.size() - 1);
    }
};