#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>& nums) {
        return std::set<int>(nums.begin(), nums.end()).size() < nums.size()
                   ? true
                   : false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    Solution a;
    std::cout << a.containsDuplicate(nums) << std::endl;
    return 0;
}
