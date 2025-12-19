class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
            else if (nums[i] < target) {
                continue;
            }
            else {
                return i;
            }
        }
        return static_cast<int>(nums.size());
    }
};
