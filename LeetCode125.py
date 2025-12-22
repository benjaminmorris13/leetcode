class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        sentence = ""
        for char in s:
            if (char.isalnum()):
                sentence += char
            else:
                continue
        one = 0
        two = len(sentence) - 1
        while (one < two):
            if (sentence[one] == sentence[two]):
                one = one + 1
                two = two - 1
            else:
                return False
        return True
