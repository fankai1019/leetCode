#include <iostream>
#include <vector>

class Solution {
   public:
    int searchInsert(std::vector<int>& nums, int target) {
        int pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                pos = i;
                return pos;
            }
        }
        pos = nums.size();
        return pos;
    }
};

int main() {
    std::vector<int> inputs = {1, 3, 5, 6};
    Solution a;
    std::cout << a.searchInsert(inputs, 2) << std::endl;
    return 0;
}
