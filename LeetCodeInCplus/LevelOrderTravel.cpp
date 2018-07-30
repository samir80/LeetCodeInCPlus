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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vecRet;
        vector<vector<TreeNode*>> vecTravel;
        if (NULL == root)
            return vecRet;

        vector<TreeNode*> vecTInit;
        vecTInit.push_back(root);
        vecTravel.push_back(vecTInit);

        
        int nLayer = 0;

        while (vecTravel[nLayer].size() > 0) {
            vecTInit.clear();
            for (int i = 0; i < vecTravel[nLayer].size(); i++) {
                if(vecTravel[nLayer][i]->left != NULL)
                    vecTInit.push_back(vecTravel[nLayer][i]->left);
                if (vecTravel[nLayer][i]->right != NULL)
                    vecTInit.push_back(vecTravel[nLayer][i]->right);
            }
            if (vecTInit.empty())
                break;
            vecTravel.push_back(vecTInit);
            nLayer++;
        }
        
        vector<int> vecVInit;
        for (int i = 0; i < vecTravel.size(); i++) {
            vecVInit.clear();
            for (int j = 0; j < vecTravel[i].size(); j++) {
                vecVInit.push_back(vecTravel[i][j]->val);
            }
            vecRet.push_back(vecVInit);
        }

        return vecRet;
    }
};
