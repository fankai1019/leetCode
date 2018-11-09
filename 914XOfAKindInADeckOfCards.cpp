#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < deck.size(); ++i) {
            map[deck[i]]++;
        }

        int min = INT_MAX;
        std::vector<int> count;
        for (auto& elem : map) {
            min = std::min(min, elem.second);
            count.push_back(elem.second);
        }

        for (int i = 2; i <= min; ++i) {
            int divisable = true;
            for (auto elem : count) {
                if (elem % i != 0) {
                    divisable = false;
                    break;
                };
            }
            if (divisable) return true;
        }

        return false;
    }
};

int main() {
    std::vector<int> inputs = {1, 2, 3, 4, 4, 3, 2, 1};
    Solution a;
    std::cout << a.hasGroupsSizeX(inputs) << std::endl;
    return 0;
}
