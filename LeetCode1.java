class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] numbers = Arrays.copyOf(nums, nums.length);
        Arrays.sort(numbers);
        int right = nums.length - 1;
        int left = 0;
        while (right > left) {
            if (numbers[right] + numbers[left] > target) {
                right = right - 1;
            } 
            else if (numbers[right] + numbers[left] < target) {
                left = left + 1;
            }
            else {
                break;
            }
        }
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == numbers[left]) {
                result[0] = i;
                break;
            }
            else {
                continue;
            }
        }
        for (int j = 0; j < nums.length; j++) {
            if ((nums[j] == numbers[right]) && (j != result[0])) {
                result[1] = j;
                break;
            }
            else {
                continue;
            }
        }
        return result;
    }
}
