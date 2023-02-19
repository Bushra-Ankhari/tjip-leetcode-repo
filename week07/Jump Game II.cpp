///Time Complexity O(N)
///Space Complexity O(1)
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int count = 0;
        int curr = 0;
        int mxjump = 0;

        for(int i=0; i< nums.size()-1; i++)
        {
            mxjump = max(mxjump, nums[i]+ i);
            if(i==curr)
            {
                curr = mxjump;
                count++;
            }
        }
        return count;
    }
};
