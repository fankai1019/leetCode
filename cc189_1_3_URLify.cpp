#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TC: O(n), need to traverse all characters
// SP: O(1), do not need extra space
class Solution
{
public:
    void URLify(string &str, int length)
    {
        int num_spaces = numSpaces(str, length);
        size_t start = length + 2 * num_spaces - 1;
        for (size_t i = length - 1; i < length; --i)
        {
            if (str[i] == ' ')
            {
                str[start--] = '0';
                str[start--] = '2';
                str[start--] = '%';
            }
            else
            {
                str[start--] = str[i];
            }
        }
    }

private:
    int numSpaces(const string &str, size_t length)
    {
        int count = 0;
        for (size_t i = 0; i < length; ++i)
        {
            if (str[i] == ' ')
                ++count;
        }
        return count;
    }
};

int main()
{
    string str = "Mr John Smith    ";
    Solution s;
    s.URLify(str, 13);
    cout << str << endl;
    return 0;
}