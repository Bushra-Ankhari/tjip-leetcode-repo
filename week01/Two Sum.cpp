

/// time complexity O(n)
/// space complexity O(n)


class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> mp;
    vector<int>ans;
    int n = nums.size(), diff;

    for(int i=0; i<n; i++)
    {
        diff = target - nums[i];
        if(mp.find(diff) != mp.end() && mp.find(diff)->second != i)
        {
            ans.push_back(mp.find(diff)->second);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i;
    }
    return ans;
    }
};
