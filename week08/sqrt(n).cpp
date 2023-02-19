class Solution
{
     ///Time Complexity O(loge(n))
    ///Space Complexity O(1)
public:
    int mySqrt(int x)
    {
        double Xn = x;
        while (fabs (Xn*Xn - x)>1e-6)
        {
            Xn = (Xn + x / Xn) / 2;
        }
        return Xn;
    }
};
