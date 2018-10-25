#include <iostream>
#include <vector>

// This is greedy algorithm.
class Solution {
   public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1) {
            if (bits[i] == 0)
                i++;
            else
                i += 2;
        }
        return i == n - 1;
    }
};

int main() {
    std::vector<int> bits = {1, 1, 0};
    Solution a;
    std::cout << a.isOneBitCharacter(bits) << std::endl;
    return 0;
}
