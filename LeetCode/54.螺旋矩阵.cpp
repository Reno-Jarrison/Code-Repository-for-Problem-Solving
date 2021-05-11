class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        int curx = 0, cury = 0, dir = 0, cnt = m * n;
        vector<int> ans;
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        while (cnt--) {
            ans.push_back(matrix[curx][cury]);
            vis[curx][cury] = true;
            int nx = curx + dx[dir], ny = cury + dy[dir];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                dir = (dir + 1) % 4;
            curx = curx + dx[dir], cury = cury + dy[dir];
        }
        return ans;
    }
};