class Solution {
public:
    string longestPalindrome(string s) {
        int len = static_cast<int>(s.length());
        string max = "";
        max += s[0];
        for (int i = 0; i < len; i++) {
            string theword;
            string rightword = "";
            string leftword = "";
            rightword += s[i];
            leftword += s[i];
            int left = i;
            int right = i + 1;
            if (right >= len) {
                break;
            }
            if (s[right] == s[i]) {
                rightword = rightword + s[right];
                while (1) {
                    right = right + 1;
                    left = left - 1;
                    if ((right >= len) || (left < 0)) {
                        break;
                    }
                    else {
                        if (s[right] == s[left]) {
                            rightword = s[left] + rightword + s[right];
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            //check odd palindromes
            left = i;
            right = i;
            while (1) {
                left = left - 1;
                right = right + 1;
                if ((right >= len) || (left < 0)) {
                    break;
                }
                else {
                    if (s[right] == s[left]) {
                        leftword = s[left] + leftword + s[right];
                    }
                    else {
                        break;
                    }
                }
            }
            if (leftword.length() > rightword.length()) {
                theword = leftword;
            }
            else {
                theword = rightword;
            }
            if (theword.length() > max.length()) {
                max = theword;
            }
            else {
                continue;
            }
        }
        return max;
    }
};
