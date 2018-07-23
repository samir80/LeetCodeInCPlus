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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> qe1;
        queue<TreeNode*> qe2;
        queue<TreeNode*>* pqe1 = NULL;
        queue<TreeNode*>* pqe2 = NULL;
        int nDepth = 0;
        if (NULL == root)
            return 0;
        qe1.push(root);
        nDepth++;
        pqe1 = &qe1;
        pqe2 = &qe2;
        while (!pqe1->empty()) {
            while (!pqe1->empty()) {
                TreeNode* p = pqe1->front();
                pqe1->pop();
                if (p && p->left)
                    pqe2->push(p->left);
                if (p && p->right)
                    pqe2->push(p->right);
            }
            if (pqe2->empty())
                break;
            nDepth++;
            queue<TreeNode*>* temp = pqe1;
            pqe1 = pqe2;
            pqe2 = temp;
        }
       return nDepth;
    }
};
