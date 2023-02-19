///Time Complexity O(log2(b))
///Space Complexity O(1)

double find_expo(double a, unsigned int b)
{
    if (b == 0)
        return 1.0;
    if(b%2 == 0)
    {
        auto t = find_expo(a, b / 2);
        return t*t;
    }
    return a * find_expo(a, b - 1);
}
double myPow(double x, int n)
{
    bool inverse_stat = n < 0 ? true : false;
    auto res = find_expo (x, abs(n));
    if (inverse_stat)
        res = 1.0 / res;
    return res;
}
