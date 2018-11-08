#include <iostream>
#include <vector>

class Solution {
   public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        while (m > 0 || n > 0) {
            if (m == 0) {
                nums1[m + n - 1] = nums2[n - 1];
                --n;
                continue;
            }
            if (n == 0) break;
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[m + n - 1] = nums2[n - 1];
                --n;

            } else {
                nums1[m + n - 1] = nums1[m - 1];
                --m;
            }
        }
    }
};

int main() {
    //    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    //    std::vector<int> nums2 = {2, 5, 6};
    std::vector<int> nums1 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    std::vector<int> nums2 = {1, 2, 2};
    Solution a;
    a.merge(nums1, 6, nums2, 3);
    for (auto i : nums1) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
