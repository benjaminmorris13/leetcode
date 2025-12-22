class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> indexes{};
        int k = 0;
        int c = 0;
        int syze = nums.size();
        for (int i = 0; i < syze; i++) {
            if (nums[i] != val) {
                k = k + 1;
            }
            else {
                indexes.push_back(i);
                c = c + 1;
            }
        }
        if (c > 0) {
            c = c - 1;
            for (int j = c; j >= 0; j--) {
                nums.erase(nums.begin() + indexes[j]);
            }
        }

        return k;
    }
};
