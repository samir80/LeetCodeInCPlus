/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(int nStart, int nEnd, vector<int>& nums)
    {
        int nLen = nEnd - nStart + 1;
        if (nLen < 1)
            return NULL;
        if (1 == nLen) {
            TreeNode* p = new TreeNode(nums.at(nStart));
            return p;
        }
        int nMid = nStart + nLen / 2;
        TreeNode* root = new TreeNode(nums.at(nMid));
        root->left = buildBST(nStart, nMid - 1, nums);
        root->right = buildBST(nMid + 1, nEnd, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int nLen = nums.size();
        if (0 == nLen) {
            return NULL;
        }
        return buildBST(0, nLen - 1, nums);
    }
};
