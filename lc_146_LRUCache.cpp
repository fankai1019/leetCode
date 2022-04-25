#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(1): get and put are O(1) due to the use of hash map on iterators and doubly linked list
// SC: O(n): store required elements
class LRUCache
{
public:
  LRUCache(int capacity) : size(capacity)
  {
  }

  int get(int key)
  {
    if (!kv.count(key))
      return -1;
    updateLRU(key);
    return kv[key];
  }

  void put(int key, int value)
  {
    if (!kv.count(key) && kv.size() == size)
      evict();
    updateLRU(key);
    kv[key] = value;
  }

  void print() const
  {
    for (list<int>::const_iterator iter = lru.cbegin(); iter != lru.cend(); ++iter)
      cout << "[" << *iter << ", " << kv.at(*iter) << "] ";
    cout << endl;
  }

private:
  void updateLRU(int key)
  {
    if (kv.count(key))
      lru.erase(ki[key]); // doubly linked list O(1)
    lru.push_front(key);
    ki[key] = lru.begin();
  }

  void evict()
  {
    kv.erase(lru.back());
    ki.erase(lru.back());
    lru.pop_back();
  }

  int size;
  list<int> lru;
  unordered_map<int, int> kv;
  unordered_map<int, list<int>::iterator> ki;
};

int main()
{
  LRUCache lru(2);
  lru.put(1, 1);
  lru.print();
  lru.put(2, 2);
  lru.print();
  cout << lru.get(1) << endl;
  lru.print();
  lru.put(3, 3);
  lru.print();
  cout << lru.get(2) << endl;
  lru.put(4, 4);
  lru.print();
  return 0;
}
