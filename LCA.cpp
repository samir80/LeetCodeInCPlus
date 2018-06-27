/**
* Definition for a binary tree node.
*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecPath1;
        vector<TreeNode*> vecPath2;

        if (BackTrace(root, p, vecPath1))
            vecPath1.insert(vecPath1.begin(), root);
        if (BackTrace(root, q, vecPath2))
            vecPath2.insert(vecPath2.begin(), root);

        vector<TreeNode*>::iterator itr1 = vecPath1.begin();
        vector<TreeNode*>::iterator itr2 = vecPath2.begin();


        TreeNode* lca = NULL;
        for (; itr1 != vecPath1.end() && itr2 != vecPath2.end(); ++itr1, ++itr2) {
            if (*itr1 == *itr2) {
                lca = *itr1;
            }
            else {
                break;
            }

        }
        return lca;
    }

    int BackTrace(TreeNode* root, TreeNode* p, vector<TreeNode*>& vecPath) {
        if (root == p) {
            return 1;
        }
        if (root->left) {
            if (BackTrace(root->left, p, vecPath)) {
                vecPath.insert(vecPath.begin(), root->left);
                return 1;
            }
        }

        if (root->right) {
            if (BackTrace(root->right, p, vecPath)) {
                vecPath.insert(vecPath.begin(), root->right);
                return 1;
            }
        }

        return 0;
    }
};
