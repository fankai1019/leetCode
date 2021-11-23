#include <iostream>
#include <vector>
using namespace std;

// TC: O(n), O(str1.length) because isSubString O(n) only because it has to copy the result into a new string
//     and string concatenation takes O(n)
// SC: O(n), string concatenation takes twice as much space as the original str
class Solution
{
public:
    bool stringRotation(const string &str1, const string &str2)
    {
        string str1str1(str1);
        str1str1 += str1;
        return isSubString(str1str1, str2);
    }

    static bool isSubString(const string &str1, const string &str2)
    {
        if (str1.size() < str2.size())
            return false;
        // TC: O(n), from https://stackoverflow.com/questions/8869605/c-stringfind-complexity
        return str1.find(str2) != string::npos;
    }
};

int main()
{
    const string str1 = "waterbottle";
    const string str2 = "erbottlewat";
    Solution s;
    bool result = s.stringRotation(str1, str2);
    cout << result << endl;
    return 0;
}