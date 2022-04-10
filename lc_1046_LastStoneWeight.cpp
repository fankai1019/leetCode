#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// Priority queue
// TC: O(nlogn): building a heap from an array of size n using Flyd's algorithm
//   is O(n) building a heap from empty by inserting elements one by one is
// O(nlogn) removing an element from heap is O(logn)
//   SP: O(n): it needs a prioirty queue to store all the elements
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> ipq(stones.begin(), stones.end());
        while (ipq.size() > 1)
        {
            int a = ipq.top();
            ipq.pop();
            int b = ipq.top();
            ipq.pop();
            if (a != b)
                ipq.push(abs(a - b));
        }

        if (ipq.empty())
            return 0;
        else
            return ipq.top();
    }
};

int main()
{
    vector<int> ivec = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.lastStoneWeight(ivec) << endl;
    return 0;
}
