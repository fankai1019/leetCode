#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(n), we traverse the array once
// SC: O(1), we just need 2 integers to track sum and max sum
class Solution
{
public:
    int contiguousSequence(const vector<int> &ivec)
    {
        int sum = 0; // do i need to consider overflow?
        int max_sum = sum;
        for (size_t i = 0; i < ivec.size(); ++i)
        {
            sum += ivec[i];
            if (sum < 0)
            {
                sum = 0;
                continue;
            }
            if (sum >= max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
};

void printVec(const vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> ivec = {2, -8, 3, -2, 4, -10};
    printVec(ivec);
    Solution s;
    int result = s.contiguousSequence(ivec);
    cout << result << endl;
    return 0;
}