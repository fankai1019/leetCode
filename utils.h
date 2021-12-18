#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// debug print
#define dp(x) std::cout << #x " = " << x << std::endl

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

    // find the first node that has value == a
    // order: 0 pre order, 1 in order, 2 post order
    // if not found, return null ptr
    T *find(int a, int order = 0) const
    {
        if (!nodes_.size() || !nodes_[0])
            return nullptr;

        // a stack of pair of nodes and whether they are visited
        stack<pair<T *, bool>> ns;
        ns.push(make_pair(nodes_[0].get(), false));
        while (ns.size())
        {
            pair<T *, bool> curr = ns.top();
            ns.pop();
            if (!curr.first)
                continue;
            if (!curr.second) // not visited
            {
                if (order == 0)
                {
                    ns.push(make_pair(curr.first->right, false));
                    ns.push(make_pair(curr.first->left, false));
                    ns.push(make_pair(curr.first, true));
                }
                else if (order == 1)
                {
                    ns.push(make_pair(curr.first->right, false));
                    ns.push(make_pair(curr.first, true));
                    ns.push(make_pair(curr.first->left, false));
                }
                else
                {
                    ns.push(make_pair(curr.first, true));
                    ns.push(make_pair(curr.first->right, false));
                    ns.push(make_pair(curr.first->left, false));
                }
            }
            else
            {
                if (curr.first->val == a)
                    return curr.first;
            }
        }
        return nullptr;
    }

    static void print(TreeNode *root)
    {
        if (!root)
            return;
        queue<T *> tq;
        tq.push(root);

        vector<int> row;
        row.push_back(root->val);
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