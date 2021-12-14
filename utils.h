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
    BFS(const vector<int> &ivec)
    {
        if (!ivec.size())
            return;
        nodes_.push_back(unique_ptr<T>(new T(ivec[0]))); // root
        queue<T *> tq;
        tq.push(nodes_[0].get());
        size_t count = 0;
        while (tq.size())
        {
            size_t size = tq.size();
            for (size_t i = 0; i < size; ++i)
            {
                T *curr = tq.front();
                tq.pop();
                if (count + 1 < ivec.size() && ivec[count + 1] != -1)
                {
                    nodes_.push_back(unique_ptr<T>(new T(ivec[count + 1])));
                    tq.push(nodes_.back().get());
                    curr->left = tq.back();
                    count++;
                }
                else
                    count++;
                if (count + 1 < ivec.size() && ivec[count + 1] != -1)
                {
                    nodes_.push_back(unique_ptr<T>(new T(ivec[count + 1])));
                    tq.push(nodes_.back().get());
                    curr->right = tq.back();
                    count++;
                }
                else
                    count++;
            }
        }
    }

    void print() const
    {
        if (!nodes_.size() || !nodes_[0])
            return;
        queue<T *> tq;
        tq.push(nodes_[0].get());

        vector<int> row;
        row.push_back(nodes_[0]->val);
        while (tq.size())
        {
            bool quit = true;
            for (size_t i = 0; i < row.size(); ++i)
            {
                if (row[i] != -1)
                {
                    quit = false;
                    break;
                }
            }
            if (quit)
                break;

            row.clear();
            size_t size = tq.size();
            for (size_t i = 0; i < size; ++i)
            {
                T *curr = tq.front();
                tq.pop();
                if (curr)
                    cout << curr->val << " ";
                else
                    cout << -1 << " ";

                if (curr)
                {
                    tq.push(curr->left);
                    if (curr->left)
                        row.push_back(curr->left->val);
                    else
                        row.push_back(-1);
                }
                else
                    tq.push(nullptr);

                if (curr)
                {
                    tq.push(curr->right);
                    if (curr->right)
                        row.push_back(curr->right->val);
                    else
                        row.push_back(-1);
                }
                else
                    tq.push(nullptr);
            }
            cout << endl;
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