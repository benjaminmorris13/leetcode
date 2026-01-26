class Solution {
public:
    int search(vector<int>& nums, int target) {
        int max = nums.size() - 1;
        int index = max / 2;
        int min = 0;
        int last = -1;
        while ((min != max) && (index != last)) {
            last = index;
            if (nums[index] > target) {
                max = index;
                index = (max - min) / 2;
                continue;
            }
            else if (nums[index] < target) {
                min = index;
                index = (max + min) / 2;
                continue;
            }
            else {
                return index;
            }
        }
        if (min == max) {
            if (nums[max] == target) {
                return max;
            }
            else {
                return -1;
            } 
        }
        else {
            if (nums[0] == target) {
                return 0;
            }
            else if (nums[nums.size() - 1] == target) {
                return nums.size() - 1;
            }
            else {
                return -1;
            }
        }
        return -1;
    }
};
