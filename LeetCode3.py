class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lengthy = len(s)
        if (lengthy == 0):
            return 0
        elif (lengthy == 1):
            return 1
        else:
            longest = 1
            for i in range(lengthy):
                c = i
                letters = {s[i]}
                while True:
                    if (c == lengthy - 1):
                        break
                    else:
                        c += 1
                        albert = len(letters)
                        letters.add(s[c])
                        if (len(letters) == albert):
                            break
                        else:
                            continue
                if (len(letters) > longest):
                    longest = len(letters)
                else:
                    continue
            return longest
