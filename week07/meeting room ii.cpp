///Time Complexity O(NlogN)
///Space Complexity O(N)

class Solution
{
public:
    int minMeetingRooms (vector<vector<int>>& intervals)
    {
        map<int,int>room_stats;
        for(auto &interval: intervals)
        {
            room_stats[interval[0]]++;
            room_stats[interval[1]]--;
        }
        int min_no_room = 0;
        int curr_room = 0;
        for(auto &it: room_stats){
            curr_room +=it.second;
            min_no_room = max (min_no_room, curr_room);
        }
        return min_no_room;
        }
    };
