class Solution {
    public boolean isAnagram(String s, String t) {
        char[] ess = s.toCharArray();
        char[] tee = t.toCharArray();
        Arrays.sort(ess);
        Arrays.sort(tee);
        if (ess.length != tee.length) {
            return false;
        }
        else {
            for (int i = 0; i < ess.length; i++) {
                if (ess[i] == tee[i]) {
                    continue;
                }
                else {
                    return false;
                }
            }
            return true;
        }
    }
}
