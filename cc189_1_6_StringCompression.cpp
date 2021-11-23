#include <iostream>
#include <string>
using namespace std;

// TC: O(n), we need to traverse through all characters in the string
// SP: O(n), we need a new string with size appromately to n if there are not many repeats
class Solution1
{
public:
    string stringCompression(const string &str)
    {
        string result;
        if (str.size() <= 1)
            return str;
        result.push_back(str[0]);
        size_t j = 0;
        size_t counter = 1;
        for (size_t i = 1; i < str.size(); ++i, ++j)
        {
            if (str[i] == str[j])
            {
                counter++;
            }
            else
            {
                result += to_string(counter);
                result.push_back(str[i]);
                counter = 1;
            }

            if (i == str.size() - 1)
                result += to_string(counter);
        }
        if (result.size() >= str.size())
            return str;
        return result;
    }
};

// cleaner code
class Solution2
{
public:
    string stringCompression(const string &str)
    {
        string result;
        size_t counter = 0;
        for (size_t i = 0; i < str.size(); ++i)
        {
            counter++;
            if (i == str.size() - 1 || str[i] != str[i + 1])
            {
                result.push_back(str[i]);
                result += to_string(counter);
                counter = 0;
            }
        }
        return result.size() < str.size() ? result : str;
    }
};

int main()
{
    string str = "aabcccccaaa";
    // Solution1 s;
    Solution2 s;
    str = s.stringCompression(str);
    cout << str << endl;
    return 0;
}