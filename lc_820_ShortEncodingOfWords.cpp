#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// TC: O(max(nlogn, mn)): n is the num of words, m is the average
// word length
//  nlogn is for the sort, mn is for all of trie inserts
// SC: O(mn), basically linear, and worst case is that we need to
// store all words in the trie.
class Trie
{
public:
    struct Node
    {
        Node() : children(26, nullptr) {}
        vector<Node *> children;
    };

    Trie() : root_(new Node()) {}

    bool insert(const string &str)
    {
        Node *p = root_.get();
        bool is_new_word = false;
        for (size_t i = str.size() - 1; i < str.size(); --i)
        {
            Node *&child = p->children[str[i] - 'a'];
            if (!child)
            {
                // check whether this is a new word or no
                if (!is_new_word)
                    is_new_word = true;
                child = new Node();
            }
            p = child;
        }
        return is_new_word;
    }

private:
    unique_ptr<Node> root_;
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Trie trie;
        int sum = 0;
        sort(words.begin(), words.end(),
             [](const string &a, const string &b)
             { return a.size() > b.size(); });
        for (string &word : words)
        {
            bool is_new_word = trie.insert(word);
            // if it is a new word, increase sum by word.size() + 1(for '#')
            if (is_new_word)
                sum += word.size() + 1;
        }
        return sum;
    }
};

// TC: O(mn)
// SC: O(mn)
// no sort solution

// class Trie
// {
// public:
//     struct Node
//     {
//         Node()
//             : children(26, nullptr), is_word(false), has_children(false),
//               removed(false), depth(0) {}
//         vector<Node *> children;
//         bool is_word;
//         bool has_children;
//         bool removed;
//         int depth;
//     };

//     Trie() : root_(new Node()) {}

//     void insert(const string &str, int &sum)
//     {
//         Node *p = root_.get();
//         for (size_t i = str.size() - 1; i < str.size(); --i)
//         {
//             Node *&child = p->children[str[i] - 'a'];
//             if (!child)
//             {
//                 p->has_children = true;
//                 child = new Node();
//             }
//             // if previous one is a word and depth has not been subtracted from sum,
//             // do it.
//             if (p->is_word && !p->removed)
//             {
//                 sum -= p->depth + 1;
//                 p->removed = true;
//             }
//             p = child;
//         }

//         // mark it as a word only when it is a leaf
//         if (!p->is_word && !p->has_children)
//         {
//             p->is_word = true;
//             p->depth = str.size();
//             sum += p->depth + 1;
//         }
//     }

// private:
//     unique_ptr<Node> root_;
// };

// class Solution
// {
// public:
//     int minimumLengthEncoding(vector<string> &words)
//     {
//         Trie trie;
//         int sum = 0;
//         for (string &word : words)
//         {
//             trie.insert(word, sum);
//         }
//         return sum;
//     }
// };

int main()
{
    vector<string> str_vec{"time", "me", "bell"};
    Solution s;
    int result = s.minimumLengthEncoding(str_vec);
    cout << result << endl;
    return 0;
}