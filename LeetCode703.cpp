class KthLargest {
private:
    int target;
    vector<int> store;
public:
    void down(vector<int>& nums, int n) {
        while (1) {
            int left = (2 * n) + 1;
            int right = (2 * n) + 2;
            int syze = static_cast<int>(nums.size());
            if ((left >= syze) && (right >= syze)) {
                break;
            }
            else if (left == syze - 1) {
                if (nums[n] < nums[left]) {
                    int albert = nums[n];
                    nums[n] = nums[left];
                    nums[left] = albert;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                if ((nums[n] > nums[left]) && (nums[n] > nums[right])) {
                    break;
                }
                else {
                    int swap;
                    if (nums[left] > nums[right]) {
                        swap = left;
                    }
                    else {
                        swap = right;
                    }
                    int einstein = nums[swap];
                    nums[swap] = nums[n];
                    nums[n] = einstein;
                    n = swap;
                }
            }
        }
    }

    int del(vector<int>& nums) {
        int result = nums[0];
        int last = nums[nums.size() - 1];
        nums[0] = last;
        nums.pop_back();
        down(nums, 0);
        return result;
    }

    KthLargest(int k, vector<int>& nums) : target{k}, store{nums} {
        int siz = static_cast<int>(nums.size());
        if (siz > 1) {
            int node = siz / 2;
            node -= 1;
            for (int i = node; i >= 0; i--) {
                down(nums, i);
            }
            vector<int> rev {};
            int stop = std::min(siz, k);
            for (int j = 0; j < stop; j++) {
                int max = del(nums);
                rev.push_back(max);
            }
            vector<int> real{};
            for (int l = stop - 1; l >= 0; l--) {
                real.push_back(rev[l]);
            }
            store = real;
        }
        else {
            return;
        }
    }

    void reverse(vector<int>& nums, int n) {
        while (1) {
            int left = (2 * n) + 1;
            int right = (2 * n) + 2;
            int syze = static_cast<int>(nums.size());
            if ((left >= syze) && (right >= syze)) {
                break;
            }
            else if (left == syze - 1) {
                if (nums[n] > nums[left]) {
                    int albert = nums[n];
                    nums[n] = nums[left];
                    nums[left] = albert;
                    break;
                }
                else {
                    break;
                }
            }
            else {
                if ((nums[n] < nums[left]) && (nums[n] < nums[right])) {
                    break;
                }
                else {
                    int swap;
                    if (nums[left] < nums[right]) {
                        swap = left;
                    }
                    else {
                        swap = right;
                    }
                    int einstein = nums[swap];
                    nums[swap] = nums[n];
                    nums[n] = einstein;
                    n = swap;
                }
            }
        }

    }
    
    int add(int val) {
        if (store.size() < target) {
            int index = store.size();
            store.push_back(val);
            while (1) {
                int par = index - 1;
                if (par < 0) {
                    break;
                }
                else {
                    par /= 2;
                }
                if (store[index] < store[par]) {
                    int albert = store[par];
                    store[par] = store[index];
                    store[index] = albert;
                    index = par;
                }
                else {
                    break;
                }
            }
            return store.front();
        }
        else if (val < store.front()) {
            return store.front();
        }
        else {
            store[0] = val;
            reverse(store, 0);
            return store.front();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
