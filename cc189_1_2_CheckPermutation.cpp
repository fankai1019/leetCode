#include <iostream>
#include <string>
#include <vector>
using namespace std;

// assume all characters are ascii character
// assume 2 empty strings case is false
// TC: O(n), need to traverse all characters
// SP: O(1), need const size array
class Solution
{
public:
    bool checkPermutations(const string &str1, const string &str2)
    {
        if (str1.size() != str2.size())
            return false;
        if (!str1.size())
            return false;

        vector<int> ivec(128, 0);
        for (size_t i = 0; i < str1.size(); ++i)
        {
            int index = str1[i];
            ++ivec[index];
        }
        for (size_t i = 0; i < str2.size(); ++i)
        {
            int index = str2[i];
            if (ivec[index]-- == 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string str1, str2;
    cout << "Input the first string: ";
    cin >> str1;
    cout << "Input the second string: ";
    cin >> str2;
    Solution s;
    bool result = s.checkPermutations(str1, str2);
    cout << result << endl;
    return 0;
}