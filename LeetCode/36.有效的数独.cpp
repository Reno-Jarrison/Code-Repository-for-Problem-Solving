class Solution {
public:
    bool visr[9][9], visc[9][9], visx[9][9];
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j]=='.') 
                    continue;
                int id = i / 3 * 3 + j / 3, x = board[i][j] - '1';
                if (visr[i][x] || visc[j][x] || visx[id][x]) 
                    return false;
                visr[i][x] = visc[j][x] = visx[id][x] = true;
            }
        return true;
    }
};