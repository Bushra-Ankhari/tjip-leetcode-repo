///Time complexity O(n)
///Space complexity O(1)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vote = 1;
        int candidate = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == candidate){
                vote++;
            }
            else{
                vote--;
            }
            if(vote == 0){
                candidate = nums[i];
                vote++;
            }
        }
        vote = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == candidate){
                vote++;
            }
        }
        if(vote>n/2){
            return candidate;
        }
        else{
            return -1;
        }
    }
};


///Time complexity O(nlogn)
///Space complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];

    }
};
