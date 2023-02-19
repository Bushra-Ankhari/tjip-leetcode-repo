class Solution {
public:
    ///Time Complexity O(N)
    ///Space Complexity O(N)
    int triangularSum(vector<int>& nums) {

        while(nums.size()!=1){
            int n=nums.size();
        for(int i=0;i<n-1;i++){
            int val=nums[i]+nums[i+1];
            nums[i]=val%10;
        }
            nums.pop_back();
        }
        return nums[0];
    }
};
