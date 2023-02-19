class Solution
{
public:
    ///Time Complexity O(N loglog(N))
   ///Space Complexity O(N)
    int countPrimes(int n)
    {
        vector<bool> p(n+1,false);
        if(n<3)
            return 0;
        p[2] = 1;
        int count = 1;
        for(int i = 3; i < n; i += 2)
        {
            p[i] = 1;
        }
        for(int i = 3; i < n; i += 2)
        {
            if(p[i])
            {
                count++;
                for(unsigned long long j = (unsigned long long)i*i; j<n; j+=2*i)
                {
                    p[j] = 0;
                }
            }
        }
        return count;
    }

};
