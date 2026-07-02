class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() == 0) {
            return "";
        }
        int l = 0;
        int r = 0;
        int bestLeft = 0;
        int bestRight = 0;

        unordered_map<char, int> charsNeeded;
        unordered_map<char, int> charsFound;

        for (char c : t) {
            charsNeeded[c]++;
        }

        int requiredChars = charsNeeded.size();
        int formed = 0;
        int bestLength = INT_MAX;

        string output = "";

        while (r < s.length()) {
            char c = s[r];
            charsFound[c]++;

            if (charsNeeded.contains(c) && charsFound[c] == charsNeeded[c]) {
                formed++;
            }

            while (formed == requiredChars) {
                if ((r - l + 1) < bestLength) {
                    bestLength = r - l + 1;
                    bestLeft = l;
                    bestRight = r;
                }

                char leftChar = s[l];
                charsFound[leftChar]--;

                if (charsNeeded.contains(leftChar) && charsFound[leftChar] < charsNeeded[leftChar]) {
                    formed--;
                }

                l++;
            }
            r++;
        }

        if (bestLength == INT_MAX) {
            return "";
        }

        for (int i = bestLeft; i < bestLeft + bestLength; i++) {
            output.push_back(s[i]);
        }

        return output;


    }
};
