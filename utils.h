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
    BFS(const vector<int> &ivec) : nodes_(ivec.size())
    {
        if(!ivec.size())
            return;

        for (size_t i = 0; i < ivec.size(); ++i)
            if(ivec[i] != -1)
                nodes_[i].reset(new TreeNode(ivec[i]));

        // check whether first node is null or not
        if(!nodes_[0])
            return;

        queue<TreeNode *> nq;
        nq.push(nodes_[0].get());
        size_t count = 1;
        bool quit = false;
        while(true)
        {
            size_t size = nq.size();
            for(size_t i=0; i<size; ++i)
            {
                TreeNode* curr = nq.front();
                nq.pop();
                if(curr)
                {
                    if(count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                    curr->left = nodes_[count++].get();
                    nq.push(curr->left);
                    if(count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                    curr->right = nodes_[count++].get();
                    nq.push(curr->right);
                    if(count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                }
                else
                {
                    count+= 2;
                }
            }
            if(quit)
                break;
        }
    }
    TreeNode *root()
    {
        if (nodes_.size())
            return nodes_[0].get();
        return nullptr;
    }

private:
    vector<unique_ptr<TreeNode>> nodes_;
};