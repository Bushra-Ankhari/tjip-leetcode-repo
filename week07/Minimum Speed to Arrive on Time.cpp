///Time Complexity O(Nlog(N))
///Space Complexity O(1)

class Solution
{
    static const int MAX_SPEED = INT_MAX / 2;
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int L = 1, R = MAX_SPEED;
        while(L<R)
        {
            int M = L + (R - L) / 2;
            double elapsed_time = 0.0;
            for(int i = 0; i<dist.size(); i++)
            {
                if(i+1 == dist.size())
                    elapsed_time +=1.0* dist[i]/ M;
                else
                    elapsed_time += (dist[i] + M-1) / M;
            }
            if(elapsed_time>hour)
                L = M + 1;
            else
                R = M;
        }
        return L == MAX_SPEED ?  -1 : L;
    }
};
