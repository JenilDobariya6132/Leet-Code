class NumArray {
private:
    vector<int> tree;
    vector<int> nums;
    int n;
    void updateTree(int index, int value) {
        index++;

        while (index <= n) {
            tree[index] += value;
            index += index & (-index);
        }
    }
    int prefixSum(int index) {
        index++;

        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }

        return sum;
    }

public:
    NumArray(vector<int>& nums) {

        this->nums = nums;
        n = nums.size();

        tree.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            updateTree(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int difference = val - nums[index];

        nums[index] = val;

        updateTree(index, difference);
    }

    int sumRange(int left, int right) {

        if (left == 0) {
            return prefixSum(right);
        }

        return prefixSum(right) - prefixSum(left - 1);
    }
};