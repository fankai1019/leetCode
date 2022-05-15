#include "utils.h"

using namespace std;

// Two pointer
// TC: O(n) loop over all digits
// SC: O(n) a vector is needed
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        vector<int> ivec;
        while (x)
        {
            ivec.push_back(x % 10);
            x /= 10;
        }

        int start = 0;
        int end = ivec.size() - 1;

        while (start <= end)
        {
            if (ivec[start++] != ivec[end--])
                return false;
        }
        return true;
    }
};

int main()
{
    int x = 121;
    Solution s;
    bool result = s.isPalindrome(x);
    cout << result << endl;
    return 0;
}
