#include <memory>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  int val;
  TreeNode *left;
  TreeNode *right;
};

class BFS
{
public:
  BFS(const vector<int>& ivec): nodes_(ivec.size())
  {
    for (size_t i = 0; i < ivec.size(); ++i)
      nodes_[i].reset(ivec[i] == -1 ? nullptr : new TreeNode(ivec[i]));

    if(ivec.size() <= 1)
      return;
    
    queue<TreeNode*> nq;
    nq.push(nodes_[0].get());
    size_t count = 1;
    while(true)
    {
      bool quit = false;
      size_t size = nq.size();
      for(size_t i=0; i<size; ++i)
      {
        TreeNode* curr = nq.front();
        nq.pop();
        if(curr)
        {
          curr->left = nodes_[count++].get();
          if(count == ivec.size())
          {
            quit = true;
            break;
          }
          nq.push(curr->left);
          curr->right = nodes_[count++].get();
          if(count == ivec.size())
          {
            quit = true;
            break;
          }
          nq.push(curr->right);
        }
        else
        {
          count++;
          if(count == ivec.size())
          {
            quit = true;
            break;
          }
          count++;
          if(count == ivec.size())
          {
            quit = true;
            break;
          }
        }
      }
      if(quit)
        break;
    }
  }
  TreeNode* root()
  {
    if(nodes_.size())
      return nodes_[0].get();
    return nullptr;
  }
private:
  vector<unique_ptr<TreeNode>> nodes_;
};