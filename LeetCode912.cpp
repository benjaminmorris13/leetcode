class Solution {
public:
    void merge(vector<int>& one, vector<int>& two) {
        int l1 = one.size();
        int l2 = two.size();
        one.resize(l1 + l2);
        while ((l1 > 0) && (l2 > 0)) {
            if (one[l1 - 1] > two[l2 - 1]) {
                one[l1 + l2 - 1] = one[l1 - 1];
                l1 -= 1;
            }
            else {
                one[l1 + l2 - 1] = two[l2 - 1];
                l2 -= 1;
            }
        }
        if (l2 == 0) {
            return;
        }
        else {
            while (l2 != 0) {
                one[l2 - 1] = two[l2 - 1];
                l2 -= 1;
            }
            return;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        if (low < high) {
            vector<int> left {};
            vector<int> right {};
            for (int i = 0; i <= mid; i++) {
                left.push_back(nums[i]);
            }
            for (int j = mid + 1; j <= high; j++) {
                right.push_back(nums[j]);
            }
            vector<int> newleft = sortArray(left);
            vector<int> newright = sortArray(right);
            merge(newleft, newright);
            return newleft;
        }
        return nums;
    }
};
