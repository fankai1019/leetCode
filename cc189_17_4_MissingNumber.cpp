#include <exception>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// TC: O(n), n is the number of elements, n + n/2 + n/4 + ... + 1 = O(n)
// SC: O(nlogn)? as tree depth is logn and for each recursive call it needs a vector of size n
class Solution
{
public:
    int32_t missingNumber(const vector<int32_t> &ivec)
    {
        length = (int32_t)log2(ivec.size()) + 1;
        return missingNumber(ivec, 0);
    }

    int32_t missingNumber(const vector<int32_t> &ivec, int lsb)
    {
        if (lsb >= length)
            return 0;
        size_t n = ivec.size();
        vector<int32_t> zeros;
        vector<int32_t> ones;
        for (size_t i = 0; i < ivec.size(); ++i)
        {
            if (fetchBit(ivec[i], lsb))
                ones.push_back(ivec[i]);
            else
                zeros.push_back(ivec[i]);
        }
        if (ones.size() < zeros.size())
        {
            int32_t v = missingNumber(ones, lsb + 1);
            return (v << 1) | 1;
        }
        else
        {
            int32_t v = missingNumber(zeros, lsb + 1);
            return (v << 1) | 0;
        }
    }

    // fetch jth bit
    int32_t fetchBit(int32_t x, int j)
    {
        if (j < 0 || j > 31)
            throw runtime_error("wrong value of j.");
        int tmp = 1;
        for (size_t i = 0; i < j; ++i)
            tmp = tmp << 1;
        return x & tmp ? 1 : 0;
    }

    // fetch jth bit of ivec[i]
    int32_t fetchBit(const vector<int32_t> &ivec, int i, int j)
    {
        if (i >= ivec.size())
            throw runtime_error("Exceeds the bound of the vector.");
        return fetchBit(ivec[i], j);
    }

private:
    int32_t length;
};

void printVec(const vector<int32_t> &ivec)
{
    for (size_t i = 0; i < ivec.size(); ++i)
        cout << ivec[i] << " ";
    cout << endl;
}

int main()
{
    int32_t n;
    cout << "Enter n: ";
    cin >> n;
    int32_t m;
    cout << "Enter the missing number: ";
    cin >> m;
    if (m > n)
    {
        cout << "Wrong missing number." << endl;
        return 0;
    }

    vector<int32_t> ivec;
    for (size_t i = 0; i <= n; ++i)
    {
        if (i != m)
            ivec.push_back(i);
    }
    printVec(ivec);

    Solution s;
    int32_t result = s.missingNumber(ivec);
    cout << result << endl;
    return 0;
}