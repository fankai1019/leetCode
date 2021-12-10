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

struct Node
{
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next = nullptr) : val(x), left(left), right(right), next(next) {}
    int val;
    Node *left;
    Node *right;
    Node *next;
};

template <typename T>
class BFS
{
public:
    BFS(const vector<int> &ivec) : nodes_(ivec.size())
    {
        if (!ivec.size())
            return;

        for (size_t i = 0; i < ivec.size(); ++i)
            if (ivec[i] != -1)
                nodes_[i].reset(new T(ivec[i]));

        // check whether first node is null or not
        if (!nodes_[0])
            return;

        queue<T *> nq;
        nq.push(nodes_[0].get());
        size_t count = 1;
        bool quit = false;
        while (true)
        {
            size_t size = nq.size();
            for (size_t i = 0; i < size; ++i)
            {
                T *curr = nq.front();
                nq.pop();
                if (curr)
                {
                    if (count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                    curr->left = nodes_[count++].get();
                    nq.push(curr->left);
                    if (count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                    curr->right = nodes_[count++].get();
                    nq.push(curr->right);
                    if (count + 1 > ivec.size())
                    {
                        quit = true;
                        break;
                    }
                }
                else
                {
                    count += 2;
                }
            }
            if (quit)
                break;
        }
    }
    T *root()
    {
        if (nodes_.size())
            return nodes_[0].get();
        return nullptr;
    }

private:
    vector<unique_ptr<T>> nodes_;
};

template <typename T>
void printVec(const vector<T> &t_vec)
{
    for (size_t i = 0; i < t_vec.size(); ++i)
    {
        cout << t_vec[i];
        if (i != t_vec.size() - 1)
            cout << " ";
    }
    cout << endl;
}

template <typename T>
void printVecVec(const vector<vector<T>> &t_vec_vec)
{
    for (size_t i = 0; i < t_vec_vec.size(); ++i)
    {
        for (size_t j = 0; j < t_vec_vec[i].size(); ++j)
        {
            cout << t_vec_vec[i][j];
            if (j != t_vec_vec[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }
}