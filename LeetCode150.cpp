class Solution {
public:
int evalRPN(vector<string>& tokens) {
    vector<int> stack {};
    for (string token : tokens) {
        try {
            int num = std::stoi(token);
            stack.push_back(num);
        }
        catch (std::invalid_argument& e) {
            int num1 = stack.back();
            stack.pop_back();
            int num2 = stack.back();
            stack.pop_back();
            int num3;
            if (token == "+") {
                num3 = num1 + num2;
            }
            else if (token == "-") {
                num3 = num2 - num1;
            }
            else if (token == "*") {
                num3 = num1 * num2;
            }
            else {
                num3 = num2 / num1;
            }
            stack.push_back(num3);
        }
    }
    return stack.back();
}
};
