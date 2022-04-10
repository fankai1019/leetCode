#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// Priority queue
// TC: O(nlogk): n elements need to be inserted to heap and each of which takes time logk
// SC: O(k): k elements in the heap
class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums) : k_(k)
  {
    for (size_t i = 0; i < k; ++i)
      ipq_.push(INT_MIN);
    for (size_t i = 0; i < nums.size(); ++i)
    {
      int num = nums[i];
      if (num > ipq_.top())
      {
        ipq_.pop();
        ipq_.push(num);
      }
    }
  }

  int add(int val)
  {
    if (val > ipq_.top())
    {
      ipq_.pop();
      ipq_.push(val);
    }
    int result = ipq_.top();
    if (result == INT_MIN)
      return 0;
    return ipq_.top();
  }

private:
  int k_;
  priority_queue<int, std::vector<int>, std::greater<int>> ipq_;
};

int main()
{
  vector<int> ivec = {4, 5, 8, 2};
  KthLargest k(3, ivec);
  cout << k.add(3) << endl;
  cout << k.add(5) << endl;
  cout << k.add(10) << endl;
  cout << k.add(9) << endl;
  cout << k.add(4) << endl;
  return 0;
}
