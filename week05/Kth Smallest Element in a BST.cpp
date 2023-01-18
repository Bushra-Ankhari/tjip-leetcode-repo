///Time Complexity O(N), Space Complexity O(N)

class Solution {
public:
   vector<int> v;
	void inOrder(TreeNode* root){
		if(root==NULL)return;
		inOrder(root->left);
		v.push_back(root->val);
		inOrder(root->right);
	}
	int kthSmallest(TreeNode* root, int k) {
		inOrder(root);
		return v[k-1];
	}
};
