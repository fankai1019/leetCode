#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// struct Node
// {
//     Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
//     Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
//     Node(int x, Node *left, Node *right, Node *next = nullptr) : val(x), left(left), right(right), next(next) {}
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;
// };

// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(n): in worst case you need to hold all vertices in the queue
class Solution1
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return 0;

        queue<Node *> tq;
        tq.push(root);
        while (tq.size())
        {
            size_t size = tq.size();
            for (size_t i = 0; i < size; ++i)
            {
                Node *curr = tq.front();
                tq.pop();
                if (i != size - 1)
                    curr->next = tq.front();
                if (curr->left)
                    tq.push(curr->left);
                if (curr->right)
                    tq.push(curr->right);
            }
        }
        return root;
    }
};

// TC: O(n): every node is pushed and poped once, so 2n
// SC: O(1): use existing next pointer for storage
class Solution2
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return 0;

        unique_ptr<Node> new_head(new Node());
        new_head->next = root;

        while (new_head->next)
        {
            Node *tail = new_head.get();
            Node *n = new_head->next;
            new_head->next = nullptr;
            for (; n != nullptr; n = n->next)
            {
                if (n->left)
                {
                    tail->next = n->left;
                    tail = tail->next;
                }
                if (n->right)
                {
                    tail->next = n->right;
                    tail = tail->next;
                }
            }
        }
        return root;
    }
};

void print(Node *root)
{
    if (!root)
        return;
    queue<Node *> nq;
    nq.push(root);
    while (nq.size())
    {
        size_t size = nq.size();
        for (size_t i = 0; i < size; ++i)
        {
            Node *curr = nq.front();
            if (curr->next)
                cout << curr->next->val << " ";
            else
                cout << "n ";
            nq.pop();
            if (curr->left)
                nq.push(curr->left);
            if (curr->right)
                nq.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, -1, 7};
    BFS<Node> bfs(ivec);
    // Solution1 s;
    Solution2 s;
    Node *result = s.connect(bfs.root());
    print(result);
    return 0;
}
