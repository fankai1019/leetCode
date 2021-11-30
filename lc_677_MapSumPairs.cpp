#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
using namespace std;

// Trie, recursive function
// TC:
//  insert: O(K), where K is key length
//  sum: O(K), O(start_with + rest letters)
// SP: O(n), linear in the size of total input
class MapSum1
{
public:
    struct Node
    {
        Node() : value(0), children(26, nullptr) {}
        ~Node()
        {
            for (const Node *child : children)
                if (child)
                    delete child;
        }
        int value;
        vector<Node *> children;
    };

    MapSum1() : root_(new Node())
    {
    }

    void insert(const string &key, int val)
    {
        Node *p = root_.get();
        for (const char c : key)
        {
            int pos = c - 'a';
            if (!p->children[pos])
                p->children[pos] = new Node();
            p = p->children[pos];
        }
        p->value = val;
    }

    const Node *startsWith(const string &prefix) const
    {
        const Node *p = find(prefix);
        return p;
    }

    int sum(const string &prefix)
    {
        return sum_recursive(startsWith(prefix));
    }

private:
    int sum_recursive(const Node *p)
    {
        if (!p)
            return 0;
        int sum = p->value;
        for (size_t i = 0; i < 26; ++i)
            sum += sum_recursive(p->children[i]);
        return sum;
    }

    const Node *find(const string &str) const
    {
        const Node *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';
            p = p->children[pos];
            if (!p)
                break;
        }
        return p;
    }
    unique_ptr<Node> root_;
};

// Trie, hasmap
// TC:
//  insert: O(K), where K is key length
//  sum: O(K), O(start_with + rest letters)
// SP: O(n), linear in the size of total input
class MapSum2
{
public:
    struct Node
    {
        Node() : sum(0), children(26, nullptr) {}
        ~Node()
        {
            for (const Node *child : children)
                if (child)
                    delete child;
        }
        int sum;
        vector<Node *> children;
    };

    MapSum2() : root_(new Node())
    {
    }

    void insert(const string &key, int val)
    {
        int diff = val - old_val_map_[key];
        Node *p = root_.get();
        for (const char c : key)
        {
            int pos = c - 'a';
            if (!p->children[pos])
                p->children[pos] = new Node();
            p = p->children[pos];
            p->sum += diff;
        }
        old_val_map_[key] = val;
    }

    const Node *startsWith(const string &prefix) const
    {
        const Node *p = find(prefix);
        return p;
    }

    int sum(const string &prefix)
    {
        const Node *p = startsWith(prefix);
        if (p)
            return p->sum;
        return 0;
    }

private:
    const Node *find(const string &str) const
    {
        const Node *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';
            p = p->children[pos];
            if (!p)
                break;
        }
        return p;
    }
    unique_ptr<Node> root_;
    unordered_map<string, int> old_val_map_;
};

int main()
{
    // MapSum1 map_sum;
    MapSum2 map_sum;
    map_sum.insert("apple", 3);
    cout << map_sum.sum("ap") << endl;
    map_sum.insert("app", 2);
    cout << map_sum.sum("ap") << endl;
    return 0;
}