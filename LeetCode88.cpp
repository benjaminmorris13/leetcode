class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(n + m);
        while ((m > 0) && (n > 0)) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                nums1[m - 1] = 0;
                m -= 1;
            }
            else {
                nums1[m + n - 1] = nums2[n - 1];
                n -= 1;
            }
        }
        if (n == 0) {
            return;
        }
        else {
            while (n != 0) {
                nums1[m + n - 1] = nums2[n - 1];
                n -= 1;
            }
            return;
        }
    }
};
