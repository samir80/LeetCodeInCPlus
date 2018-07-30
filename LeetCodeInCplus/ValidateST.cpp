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
    bool isSame(TreeNode* t1, TreeNode* t2) 
    {
        if (NULL == t1 && NULL == t2)
            return true;
        if (t1 != NULL && t2 != NULL) {
            return (t1->val == t2->val) && isSame(t1->left, t2->right) && isSame(t1->right, t2->left);
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(NULL == root)
            return true;
        return isSame(root->left, root->right);
    }
};
