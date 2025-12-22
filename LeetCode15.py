class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        max = len(nums)
        for i in range(max):
            if ((i > 0) and (nums[i] == nums[i - 1])):
                continue
            left = i + 1
            right = max - 1
            while (left < right):
                if (nums[i] + nums[left] + nums[right] == 0):
                    new = [nums[i], nums[left], nums[right]]
                    result.append(new)
                    while ((left < right) and (nums[left] == nums[left + 1])):
                        left = left + 1
                    while ((left < right) and (nums[right] == nums[right - 1])):
                        right = right - 1
                    left = left + 1
                    right = right - 1
                elif (nums[i] + nums[left] + nums[right] > 0):
                    right = right - 1
                else:
                    left = left + 1
        return result
