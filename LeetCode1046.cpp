class Solution {
public:
    void up(vector<int>& stones) {
        size_t syz = stones.size();
        int syze = static_cast<int>(syz);
        int index = syze - 1;
        while (1) {
            int par = index - 1;
            if (par < 0) {
                return;
            }
            else {
                par /= 2;
            }
            if (stones[index] > stones[par]) {
                int albert = stones[index];
                stones[index] = stones[par];
                stones[par] = albert;
                index = par;
            }
            else {
                break;
            }
        }
    }

    int remove(vector<int>& stones) {
        int result = stones[0];
        stones[0] = stones[stones.size() - 1];
        stones.pop_back();
        int syze = static_cast<int>(stones.size());
        int index = 0;
        while (1) {
            int left = (2 * index) + 1;
            int right = (2 * index) + 2;
            if ((left >= syze) && (right >= syze)) {
                break;
            }
            else if (left == (syze - 1)) {
                if (stones[index] < stones[left]) {
                    int albert = stones[index];
                    stones[index] = stones[left];
                    stones[left] = albert;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                if ((stones[index] > stones[left]) && (stones[index] > stones[right])) {
                    break;
                }
                else {
                    int swap;
                    if (stones[left] > stones[right]) {
                        swap = left;
                    }
                    else {
                        swap = right;
                    }
                    int einstein = stones[swap];
                    stones[swap] = stones[index];
                    stones[index] = einstein;
                    index = swap;
                }
            }
        }
        return result;
    }

    int lastStoneWeight(vector<int>& stones) {
        int syze = static_cast<int>(stones.size());
        if (syze == 1) {
            return stones[0];
        }
        else {
            int index = syze / 2;
            index -= 1;
            for (int i = index; i >= 0; i--) {
                int node = i;
                while (1) {
                    int left = (node * 2) + 1;
                    int right = (node * 2) + 2;
                    if ((left >= syze) && (right >= syze)) {
                        break;
                    }
                    else if (left == syze - 1) {
                        if (stones[node] < stones[left]) {
                            int bill = stones[node];
                            stones[node] = stones[left];
                            stones[left] = bill;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        if ((stones[node] > stones[left]) && (stones[node] > stones[right])) {
                            break;
                        }
                        else {
                            int swap;
                            if (stones[left] > stones[right]) {
                                swap = left;
                            }
                            else {
                                swap = right;
                            }
                            int gates = stones[swap];
                            stones[swap] = stones[node];
                            stones[node] = gates;
                            node = swap;
                        }
                    }
                }
            }
            while (stones.size() > 1) {
                int first = remove(stones);
                int second = remove(stones);
                int diff = first - second;
                stones.push_back(diff);
                up(stones);
            }
            return stones[0];
        }
    }
};
