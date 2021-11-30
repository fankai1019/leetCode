#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
using namespace std;

// TC:
//  buildDict: O(n*m), where n is the number of strings and m is the average string length
//  search: O(26*m)
// SC: O(K) linear space to store all strings
// TODO: optimize it with backtracking search?
class MagicDictionary
{
public:
    struct Node
    {
        Node() : is_word(false), children(26, nullptr) {}
        ~Node()
        {
            for (size_t i = 0; i < children.size(); ++i)
                if (children[i])
                    delete children[i];
        }
        bool is_word;
        vector<Node *> children;
    };

    MagicDictionary() : root_(new Node()) {}

    void buildDict(const vector<string> &dictionary)
    {
        for (const string &str : dictionary)
        {
            Node *p = root_.get();
            for (const char c : str)
            {
                int pos = c - 'a';
                if (!p->children[pos])
                    p->children[pos] = new Node();
                p = p->children[pos];
            }
            p->is_word = true;
        }
    }

    bool search(string str) const
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            char c = str[i];
            for (size_t j = 0; j < 26; ++j)
            {
                char new_c = j + 'a';
                if (c == new_c)
                    continue;
                str[i] = new_c;
                if (helper(str))
                    return true;
                str[i] = c;
            }
        }
        return false;
    }

private:
    bool helper(const string &str) const
    {
        const Node *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';
            p = p->children[pos];
            if (!p)
                return false;
        }
        return p->is_word;
    }

    unique_ptr<Node> root_;
};

int main()
{
    MagicDictionary m_dict;
    m_dict.buildDict({"hello", "leetcode"});
    cout << m_dict.search("hello") << endl;
    cout << m_dict.search("leetcode") << endl;
    cout << m_dict.search("hhllo") << endl;
    cout << m_dict.search("hell") << endl;
    cout << m_dict.search("leetcoded") << endl;
    return 0;
}