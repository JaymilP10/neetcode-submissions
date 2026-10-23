class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (findWord(board, 0, word, i, j)) {
                    return true;
                }
            
            }
        }

        return false;
    }

    bool findWord(vector<vector<char>>& board, int index, string word, int x, int y) {
        
        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || board[x][y] == '0'|| word[index] != board[x][y]) {
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        char tempChar = board[x][y];

        board[x][y] = '0';

        if (findWord(board, index + 1, word, x + 1, y) == false 
        && findWord(board, index + 1, word, x - 1, y) == false 
        && findWord(board, index + 1, word, x, y + 1) == false
        && findWord(board, index + 1, word, x, y - 1) == false) {
            board[x][y] = tempChar;
            return false;
        }
        return true;


    }
};
