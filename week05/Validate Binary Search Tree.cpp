///Time Complexity O(N), Space Complexity O(N)

class Solution
{
public:
    bool isValidBST(TreeNode* root, long long L = LLONG_MIN, long long R = LLONG_MAX)
    {
        if(root == NULL)
            return true;
        if(L>=root->val || root->val>=R)
            return false;
        auto lstatus = isValidBST(root->left, L, root->val);
        auto rstatus = isValidBST(root->right, root->val, R);
        return lstatus && rstatus;
    }

};
