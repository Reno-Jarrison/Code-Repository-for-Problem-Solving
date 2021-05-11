class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (!matrix.size())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > h(n, vector<int>(m)), l(n, vector<int>(m)), r(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                h[i][j] = 1,l[i][j] = r[i][j] = j;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++)
                if (matrix[i][j - 1] != '0') 
                    l[i][j] = l[i][j - 1];
            for (int j = m - 2; j >= 0; j--)
                if (matrix[i][j + 1] != '0') 
                    r[i][j] = r[i][j + 1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue;
                if (i > 0 && matrix[i - 1][j] != '0') {
                    h[i][j] = h[i - 1][j] + 1;
                    l[i][j] = max(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                }
                ans = max(ans, (r[i][j] - l[i][j] + 1) * h[i][j]);
            }
        return ans;
    }
};