class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t left = 0;
        size_t right = height.size() - 1;
        int max;
        if (height[left] < height[right]) {
            max = (right - left) * (height[left]);
        }
        else {
            max = (right - left) * (height[right]);
        }
        while (left < right) {
            int area;
            if (height[left] < height[right]) {
                left = left + 1;
                if (height[left] < height[right]) {
                    area = (right - left) * (height[left]);
                }
                else {
                    area = (right - left) * (height[right]);
                }
                if (area > max) {
                    max = area;
                }
                else {
                    continue;
                }
            }
            else if (height[right] < height[left]) {
                right = right - 1;
                if (height[left] < height[right]) {
                    area = (right - left) * (height[left]);
                }
                else {
                    area = (right - left) * (height[right]);
                }
                if (area > max) {
                    max = area;
                }
                else {
                    continue;
                }
            }
            else {
                left = left + 1;
                right = right - 1;
                if (height[left] < height[right]) {
                    area = (right - left) * (height[left]);
                }
                else {
                    area = (right - left) * (height[right]);
                }
                if (area > max) {
                    max = area;
                }
                else {
                    continue;
                }
            }
        }
        return max;
    }
};
