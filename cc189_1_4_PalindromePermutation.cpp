#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TC: O(n), we need to traverse all characters
// SC: O(1), we need a counter vector with a fixed size 26
class Solution1
{
public:
  bool panlindromePermutation(const string &str)
  {
    string str_lower(str);
    transform(str_lower.begin(), str_lower.end(), str_lower.begin(), [](unsigned char c)
              { return tolower(c); });

    vector<int> ivec(26, 0);
    for (size_t i = 0; i < str_lower.size(); ++i)
    {
      if ('a' <= str_lower[i] && str_lower[i] <= 'z')
      {
        int index = str_lower[i] - 'a';
        ++ivec[index];
      }
    }

    int num_odds = 0;
    for (size_t i = 0; i < ivec.size(); ++i)
    {
      if (ivec[i])
      {
        if (ivec[i] % 2)
        {
          ++num_odds;
          if (num_odds > 1)
            return false;
        }
      }
    }
    if (num_odds <= 1)
      return true;
    return false;
  }
};

// save more space with bit vector
class Solution2
{
public:
  bool panlindromePermutation(const string &str)
  {
    string str_lower(str);
    transform(str_lower.begin(), str_lower.end(), str_lower.begin(), [](unsigned char c)
              { return tolower(c); });

    uint32_t checker = 0;
    for (size_t i = 0; i < str_lower.size(); ++i)
    {
      if ('a' <= str_lower[i] && str_lower[i] <= 'z')
      {
        int index = str_lower[i] - 'a';
        uint32_t this_checker = 1 << index;
        checker ^= this_checker;
      }
    }
    return !(checker & (checker - 1));
  }
};

int main()
{
  string str = "Tact Coa";
  // Solution1 s;
  Solution2 s;
  bool result = s.panlindromePermutation(str);
  cout << result << endl;
  return 0;
}