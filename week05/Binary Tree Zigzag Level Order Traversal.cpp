///Time Complexity O(N), Space Complexity O(N)  where N= no of nodes

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder (TreeNode* root)
    {
        if(!root)
            return {};
        vector<vector<int>> levelwise_nodes;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int len = Q.size();
            vector<int> nodes;
            for(int i=0; i<len; i++)
            {
                auto u = Q.front();
                Q.pop();
                nodes.push_back(u->val);
                if(u->left)
                    Q.push(u->left);
                if(u->right)
                    Q.push(u->right);
            }
            levelwise_nodes.push_back(nodes);
        }
        int i=0;
        for(auto &nodes: levelwise_nodes)
        {
            if(i%2 == 1)
            {
                reverse(nodes.begin(), nodes.end());
            }
            i++;
        }
        return levelwise_nodes;
    }
};
