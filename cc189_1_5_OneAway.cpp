#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Assume if 2 strs are the same, it is false
// TC: O(1) if string sizes are different by more than 2 O(n) otherwise
// SC: O(1) we only need a few size t and boolean variables
class Solution
{
public:
    bool oneAway(const string &str1, const string &str2)
    {
        if (str1.size() == str2.size())
            return oneEditReplace(str1, str2);
        else if (str1.size() > str2.size())
            return oneAway(str2, str1);

        size_t index1 = 0;
        size_t index2 = 0;
        for (size_t i = 0; i < str1.size(); ++i)
        {
            if (str1[index1] == str2[index2])
            {
                index1++;
                index2++;
            }
            else
            {
                if (index1 != index2)
                    return false;
                index2++;
            }
        }
        return true;
    }

private:
    bool oneEditReplace(const string &str1, const string &str2)
    {
        if (str1.size() != str2.size())
            return false;
        bool found_difference = false;
        for (size_t i = 0; i < str1.size(); ++i)
        {
            if (str1[i] != str2[i])
            {
                if (found_difference)
                    return false;
                found_difference = true;
            }
        }
        return true;
    }
};

int main()
{
    vector<string> str_vec1{"pale", "pales", "pale", "pale"};
    vector<string> str_vec2{"ple", "pale", "bale", "bake"};
    Solution s;
    for (size_t i = 0; i < str_vec1.size(); ++i)
    {
        bool result = s.oneAway(str_vec1[i], str_vec2[i]);
        cout << result << endl;
    }
    return 0;
}