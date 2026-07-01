class Solution {
public:

    vector<vector<string>> output;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> columns(n, false);
        vector<bool> diagonal1(2*n, false);
        vector<bool> diagonal2(2*n, false);
        dfs(0, n, board, columns, diagonal1, diagonal2);
        return output;
    }

    void dfs(int row, int n, vector<string>& board, vector<bool>& columns, vector<bool>& diagonal1, vector<bool>& diagonal2) {
        if (row == n) {
            output.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!columns[col] && !diagonal1[row - col + n] && !diagonal2[row + col]) {
                board[row][col] = 'Q';
                columns[col] = true;
                diagonal1[row - col + n] = true;
                diagonal2[row + col] = true;
                dfs(row + 1, n, board, columns, diagonal1, diagonal2);
                board[row][col] = '.';
                columns[col] = false;
                diagonal1[row - col + n] = false;
                diagonal2[row + col] = false;
            }
        }
    }
};
