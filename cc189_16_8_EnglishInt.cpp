#include <iostream>
#include <vector>
using namespace std;

// Assume an integer is 32 bits and INT_MAX is 2^32 - 1 which is aboult 2 billion
// TC: O(n), we traverse all digits, n is the number of digits
// SC: O(1), only integers and a vector of max size 4 are needed for storage
class Solution
{
public:
    string englishInt(int x)
    {
        if (x < 0)
            return "Negative " + englishInt(-x);
        if (x == 0)
            return "Zero";

        string result;
        vector<string> str_vec;
        do
        {
            int q = x % 1000; // 0-999
            x /= 1000;        // min 0
            string below_1000 = convertChunk(q);
            str_vec.push_back(below_1000);
        } while (x);

        for (size_t i = str_vec.size() - 1; i < str_vec.size(); --i)
        {
            result += str_vec[i];
            // The max integer is 2 billion
            if (i == 3)
                result += " Billion ";
            else if (i == 2 && str_vec[i].size())
                result += " Million ";
            else if (i == 1 && str_vec[i].size())
                result += " Thousand ";
        }
        return result;
    }

private:
    string convertChunk(int x)
    {
        string result;
        if (x < 1000)
        {
            // int q = x % 100; // 0-99
            // x /= 100;
            if (x >= 100)
            {
                result += digitToString(x / 100);
                result += " Hundred";
                x %= 100;
            }

            if (x >= 20) // 20-99
            {
                int q = x % 10;
                if (result.size())
                    result += " ";
                result += tenthToString(x / 10);
                if (x % 10 != 0)
                {
                    if (result.size())
                        result += " ";
                    result += digitToString(q);
                }
            }
            else if (x != 0) // 1-19
            {
                if (result.size())
                    result += " ";
                result += digitToString(x);
            }
        }
        return result;
    }

    string digitToString(int x)
    {
        static vector<string> map = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return map[x];
    }

    string tenthToString(int x)
    {
        static vector<string> map = {
            "", "", "Twenty", "Thrity", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return map[x];
    }
};

int main()
{
    int a = -INT_MAX;
    // int a = 1000000000;
    // int a = 100030000;
    // int a = -9009;
    Solution s;
    string result = s.englishInt(a);
    cout << result << endl;
    return 0;
}