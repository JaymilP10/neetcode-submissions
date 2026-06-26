class Solution {
public:
    bool isPalindrome(string s) {

        string modified_S;

        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {

                modified_S.push_back(tolower(s[i]));
            }
        }

        cout << modified_S;

        for (int i = 0; i < modified_S.length(); i++) {
            if (modified_S[i] != modified_S[modified_S.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
