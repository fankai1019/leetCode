#include "utils.h"

using namespace std;

// Binary search
// TC: O(logn) T(n) = T(n/2) + O(1) there are 2^n possible subsets and each time we need to copy path into results
// SC: O(logn) stack frame size is logn
class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 1;
        int high = n;
        return bs(1, n);
    }

private:
    int bs(long low, long high)
    {
        if (low > high)
            return -1;
        long mid = (low + high) / 2;
        long num = guess(mid);
        if (!num)
            return mid;
        if (num > 0)
            return bs(mid + 1, high);
        else
            return bs(low, mid - 1);
    }
};
