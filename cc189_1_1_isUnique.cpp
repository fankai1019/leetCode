#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution1
{
public:
    // TC: O(n), it needs to traverse all characters in the string
    // SC: O(n), it needs to store all characters in the set
    bool isUnique(const string &str)
    {
        set<char> cset;
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (cset.count(str[i]))
                return false;
            cset.insert(str[i]);
        }
        return true;
    }
};

// How to make the space complexity constant?
// Which data structure can be used to store all the characters in one place?
// Assume all the charaters are lower case letters
// TC: O(1), the max number of characters i needs to traverse is 26
// SC: O(1), it needs an array of size 26
class Solution2
{
public:
    bool isUnique(const string &str)
    {
        vector<int> ivec(26, 0);
        if (str.size() > 26)
            return false;
        for (size_t i = 0; i < str.size(); ++i)
        {
            int index = str[i] - 'a';
            if (ivec[index])
                return false;
            ivec[index]++;
        }
        return true;
    }
};

// Use of bit vector to save more space
// instead of using an array of size 26
// we only use a 32 bits integer
// Assume all the charaters are lower case letters
// TC: O(1)
// SC: O(1)
class Solution3
{
public:
    bool isUnique(const string &str)
    {
        if (str.size() > 26)
            return false;
        int32_t checker = 0; // int32_t has enough number of bits for the work
        for (size_t i = 0; i < str.size(); ++i)
        {
            int index = str[i] - 'a';
            // reminder: undefined behavior is index is negative and exceeds the number of bits in the result
            int32_t this_checker = 1 << index;
            if (checker & this_checker)
                return false;
            checker = checker | this_checker;
        }
        return true;
    }
};

int main()
{
    string str;
    cin >> str;
    cout << "input string: " << str << endl;
    // Solution1 a;
    // Solution2 a;
    Solution3 a;
    bool result = a.isUnique(str);
    cout << result << endl;
    return 0;
}