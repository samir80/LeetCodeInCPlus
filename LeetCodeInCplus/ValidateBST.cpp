#include "stdafx.h"
#include <vector>

using namespace std;
/* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isIncresingSequence(vector<int>& vecSeq)
    {
        int nLen = vecSeq.size();
        for (int i = 0; i <= nLen - 2; i++)
        {
            if (vecSeq[i] >= vecSeq[i + 1])
                return false;
        }
        return true;
    }
    void InOrderTravel(TreeNode* root)
    {
        if (NULL == root)
            return;
        InOrderTravel(root->left);
        m_vecNodes.push_back(root->val);
        InOrderTravel(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (NULL == root || (NULL == root->left && NULL == root->right))
            return true;
        InOrderTravel(root);
        return isIncresingSequence(m_vecNodes);
    }
public:
    vector<int> m_vecNodes;
};
