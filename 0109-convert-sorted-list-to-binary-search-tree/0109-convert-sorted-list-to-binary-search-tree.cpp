/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> arr;

    TreeNode* build(int l, int r) {
        if(l > r) return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }

        return build(0, arr.size() - 1);
    }
};