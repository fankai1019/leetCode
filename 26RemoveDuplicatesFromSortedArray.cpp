#include <iostream>
#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int pos = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != nums[i - 1]) nums[pos++] = nums[i];

        return pos;
    }
};

int main() {
    std::vector<int> inputs = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution a;
    std::cout << a.removeDuplicates(inputs) << std::endl;
    return 0;
}
