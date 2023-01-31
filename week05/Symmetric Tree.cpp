///Time Complexity O(N), Space Complexity O(N) N=No of Nodes

class Solution
{
private:
    bool isMirror(TreeNode* lft, TreeNode* rht)
    {
        if(!lft && !rht)
            return true;
        if(!lft || !rht)
            return false;
        return (lft->val == rht->val) && isMirror(lft->left, rht->right) && isMirror(lft->right, rht->left);
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }

};
