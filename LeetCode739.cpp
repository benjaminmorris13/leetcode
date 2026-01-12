class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack {};
        vector<int> answer(temperatures.size(), 0);
        vector<int> temps = temperatures;
        if (temperatures.size() == 1) {
            answer.push_back(0);
            return answer;
        }
        else {
            for (size_t i = 0; i < temperatures.size() - 1; i++) {
                stack.push_back(i);
                while (!(stack.empty())) {
                    if (temperatures[i + 1] > temperatures[stack.back()]) {
                        answer[stack.back()] = i + 1 - stack.back();
                        stack.pop_back();
                    } 
                    else {
                        break;
                    }
                }
            }
            return answer;
        }
    }
};
