class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> visited;
        for (int i = 0; i < 9; i++) {
            for (char c : board[i]) {
                if (c != '.') {
                    cout << "&c: " << c << "\n";
                    cout << "i: " << i << "\n";
                    if (!visited.insert(c).second) {
                        cout << c;
                        return false;
                    }
                }
            }
            visited.clear();
        }
        visited.clear();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (!visited.insert(board[j][i]).second) {
                        return false;
                    }
                }
            }
            visited.clear();
        }
        visited.clear();

        for (int k = 0; k <= 6; k += 3) {
            for (int l = 0; l <= 6; l += 3) {
                for (int i = k; i < k + 3; i++) {
                    for (int j = l; j < l + 3; j++) {
                        if (board[i][j] != '.') {
                            //cout << "k : " << k << " l : " << l << " :: " << board[i][j] << "\n";
                            if (!visited.insert(board[i][j]).second) {
                                cout << "k : " << k << " l : " << l << " :: " << board[i][j] << "\n";
                                return false;
                            }
                        }
                    }
                }
                visited.clear();
            }
        }





        return true;
    }
};
