class Solution:
    def isValid(self, s: str) -> bool:
        try:
            sets = {"(": ")", "{": "}", "[": "]"}
            line = []
            for char in s:
                if char in sets.keys():
                    line.append(char)
                else:
                    if (sets[line[-1]] == char):
                        line.pop(-1)
                    else:
                        return False
            if (len(line) == 0):
                return True
            else:
                return False
        except:
            return False
