/// time complexity O(n)
/// space complexity O(1)


class Solution {
public:

int singleNumber(vector<int>& nums)
{
int unique = 0;
for( int i : nums)
{
unique^=i;
}
return unique;
}
};


/// time complexity O(n)
/// space complexity O(n)


class Solution {
public:

int singleNumber(vector<int>& nums)
{
if(nums.size()==1) return nums[0];
if(nums.size()==0) return -1;
unordered_set<int>s;

for(int i : nums)
{
if(s.find(i) != s.end()){
s.erase(i);
}
else{
s.insert(i);
}
}
for(int i : s)
{
return i;
}
return -1;
}
};
