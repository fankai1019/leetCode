#include <iostream>
#include <vector>

class Solution {
   public:
    int maxDistToClosest(std::vector<int>& seats) {
        int distance = 0;
        int max = 0;
        int first = 0;
        for (int i = 0; i < seats.size(); ++i)
            if (seats[i] == 1) {
                first = i;
                break;
            }
        int prev = first;
        for (int i = first; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                max = std::max(max, (prev + i) / 2 - prev);
                distance = 0;
                prev = i;
            } else
                ++distance;
        }
        return std::max(std::max(max, distance), first);
    }
};

int main() {
    std::vector<int> inputs = {1, 0, 0, 0, 1, 0, 1};
    Solution a;
    std::cout << a.maxDistToClosest(inputs) << std::endl;

    return 0;
}
