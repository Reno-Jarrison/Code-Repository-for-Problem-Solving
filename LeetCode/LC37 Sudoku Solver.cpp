class Solution {
public:
    bool visr[9][9], visc[9][9], visx[9][9];
    int cntr[9], cntc[9], cnt, ok;
    vector<pair<int, int>> sum[20], pos;
    vector<vector<char>> ans;
    void dfs(int step, vector<vector<char>>& board)
    {
        if (step == cnt)
            ans = board, ok = 1;
        if (ok) 
            return;
        for (int i = 0; i < 9 && !ok; i++)
        {
            int r = pos[step].first, c = pos[step].second;
            int id = r / 3 * 3 + c / 3;
            if (visr[r][i] || visc[c][i] || visx[id][i]) 
                continue;
            board[r][c] = i + '1';
            visr[r][i] = visc[c][i] = visx[id][i] = true;
            dfs(step + 1, board);
            visr[r][i] = visc[c][i] = visx[id][i] = false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int x = board[i][j] - '1';
                visr[i][x] = visc[j][x] = visx[i/3*3+j/3][x] = true;
                cntr[i]++, cntc[j]++;
            }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    sum[cntr[i]+cntc[j]].push_back(make_pair(i, j)), cnt++;
        for (int i = 17 ; i >= 0; i--) 
            for (auto x : sum[i])
                pos.push_back(x);
        dfs(0, board);
        board = ans;
    }
};