class Solution {
public:
    long long c[105][205];
    long long getc(int m, int n)
    {
        if(c[m][n]) 
            return c[m][n];
        if(!m || !n || (m == n)) 
            return 1LL;
        return c[m][n] = getc(m - 1, n - 1) + getc(m, n - 1);
    }
    long long uniquePaths(int m, int n) 
    {
        return getc(m - 1, m + n - 2);
    }
};