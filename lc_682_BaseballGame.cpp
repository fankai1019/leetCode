#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// BR
// TC: O(n) iterator over ops
// SC: O(n) need a vector to store all ints
class Solution1
{
public:
  int calPoints(vector<string> &ops)
  {
    vector<int> results;
    for (size_t i = 0; i < ops.size(); ++i)
    {
      const string &str = ops[i];
      if (str == "D")
      {
        results.push_back(2 * results[results.size() - 1]);
      }
      else if (str == "C")
      {
        results.erase(results.end() - 1);
      }
      else if (str == "+")
      {
        results.push_back(results[results.size() - 1] + results[results.size() - 2]);
      }
      else
      {
        results.push_back(stoi(str));
      }
    }
    int sum = 0;
    for (size_t i = 0; i < results.size(); ++i)
      sum += results[i];
    return sum;
  }
};

// Stack
// TC: O(n) iterator over ops
// SC: O(n) need a stack to store all ints
class Solution2
{
public:
  int calPoints(vector<string> &ops)
  {
    stack<int> istack;
    for(size_t i=0; i<ops.size(); ++i)
    {
      const string& str = ops[i];
      if(str == "D")
        istack.push(2*istack.top());
      else if(str == "C")
        istack.pop();
      else if(str == "+")
      {
        int second = istack.top();
        istack.pop();
        int first = istack.top();
        istack.push(second);
        istack.push(first + second);
      }
      else
        istack.push(stoi(str));
    }

    int sum = 0;
    while(!istack.empty())
    {
      int tmp = istack.top();
      istack.pop();
      sum += tmp;
    }
    return sum;
  }
};

int main()
{
  vector<string> svec = {"5", "2", "C", "D", "+"};
  // Solution1 s;
  Solution2 s;
  cout << s.calPoints(svec) << endl;
  return 0;
}
