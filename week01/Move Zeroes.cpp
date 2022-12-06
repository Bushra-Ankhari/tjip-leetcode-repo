///Time complexity O(n)
///Space complexity may be O(1) considering same input vector for output vector

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
       int target = 0;
       int ck = count(nums.begin(), nums.end(), target);
       nums.erase(remove(nums.begin(), nums.end(), target), nums.end());
       for(int i=0;i<ck;i++){
       nums.push_back(0);
       }

    }
};



///Time complexity O(n)
///Space complexity O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n = nums.size();
       int j = 0;
       for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }
       }
        for(int i=j; i<n;i++){
                nums[i]=0;

        }
    }
};
