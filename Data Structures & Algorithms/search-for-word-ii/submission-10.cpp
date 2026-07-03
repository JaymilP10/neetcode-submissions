class TrieNode {
    public:
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> used(board.size(), vector<bool> (board[0].size(), false));
        vector<string> output;

        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* current = root;

            for (char c : word) {
                int idx = c - 'a';

                if (current->children[idx] == nullptr) {
                    current->children[idx] = new TrieNode();
                }

                current = current->children[idx];
            }

            current->word = word;
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, root, output, i, j);
            }
        }

        return output;
    }

    void dfs(vector<vector<char>> &board, TrieNode* root, vector<string>& output, int i, int j) {

        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0) {
            return;
        }

        char c = board[i][j];

        if (c == '#') {
            return;
        }

        if (root->children[c - 'a'] == nullptr) {
            return;
        }
        
        root = root->children[c - 'a'];

        if (!root->word.empty()) {
            output.push_back(root->word);
            root->word = "";
        }

        board[i][j] = '#';

        dfs(board, root, output, i + 1, j);
        dfs(board, root, output, i - 1, j);
        dfs(board, root, output, i, j + 1);
        dfs(board, root, output, i, j - 1);

        board[i][j] = c;
    }
};