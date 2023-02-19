///Time Complexity O(NlogN)
///Space Complexity O(logN)

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        int j = 0;
        int Remove = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]< intervals[j][1])
            {
                Remove++;
                if(intervals[i][1]<= intervals[j][1])
                {
                    j=i;
                }
            }
            else
            {
                j=i;
            }
        }
        return Remove;
    }
};
