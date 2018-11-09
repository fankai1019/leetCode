#include <iostream>
#include <vector>

class Solution {
   public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0 &&
                ((i == 0 || flowerbed[i - 1] == 0) &&
                 (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))) {
                if (--n == 0) return true;
                flowerbed[i] = 1;
            }
        }

        return false;
    }
};

int main() {
    std::vector<int> inputs = {1, 0, 0, 0, 1};
    Solution a;
    std::cout << a.canPlaceFlowers(inputs, 2) << std::endl;
    return 0;
}
