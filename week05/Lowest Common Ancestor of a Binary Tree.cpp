///Time Complexity O(N), Space Complexity O(N)

class Solution
{
public:
    TreeNode* searchNode (TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val ==q->val)
            return root;
        auto lres = searchNode (root->left, p, q);
        auto rres = searchNode (root->right, p,q);
        if (lres && rres)
            return root;
        return lres? lres: rres;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return searchNode (root, p,q);
    }

};
