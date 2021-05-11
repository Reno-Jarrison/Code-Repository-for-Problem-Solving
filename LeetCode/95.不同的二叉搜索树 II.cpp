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
    TreeNode* copy(TreeNode *src, int delta) {
        if (src == NULL) return NULL;
        TreeNode *des = new TreeNode(src->val + delta);
        des->left = copy(src->left, delta);
        des->right = copy(src->right, delta);
        return des;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[n + 1];
        if (!n) 
            return dp[0];
        dp[0].push_back(NULL);
        TreeNode *init = new TreeNode(1);
        dp[1].push_back(init);
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                for (auto lrt: dp[j - 1]) 
                    for(auto rrt: dp[i - j]) {
                        TreeNode *tmp = new TreeNode(j);
                        tmp->left = copy(lrt, 0);
                        tmp->right = copy(rrt, j);
                        dp[i].push_back(tmp);
                    }
        return dp[n];
    }
};