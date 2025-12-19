class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int max = numbers.size() - 1;
        int one = 0;
        int two = max;
        int first;
        int second;
        while (1) {
            int sum = numbers[one] + numbers[two];
            if ((sum == target) && (one != two)) {
                if (one > two) {
                    first = two + 1;
                    second = one + 1;
                    break;
                }
                else {
                    first = one + 1;
                    second = two + 1;
                    break;
                }
            }
            else if (numbers[one] + numbers[two] > target) {
                two = two - 1;
            }
            else {
                one = one + 1;
            }
            if (one > max) {
                one = 0;
            }
            if (two < 0) {
                two = max;
            }
            else {
                continue;
            }
        }
        vector<int> result {first, second};
        return result;
    }
};
