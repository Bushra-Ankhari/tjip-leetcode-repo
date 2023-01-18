///Time Complexity O(N), Space Complexity O(N)

class Solution
{
    public:
    TreeNode* constructBSTfrom(vector<int> &nums, int L, int R)
    {
        if(L>R)
            return NULL;
        int M= L + (R-L)/2;
        TreeNode* root = new TreeNode(nums[M]);
        root->left = constructBSTfrom(nums, L, M-1);
        root->right = constructBSTfrom(nums,M+1,R);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int> &nums)
    {
        return constructBSTfrom(nums, 0, nums.size() -1);
    }
};
