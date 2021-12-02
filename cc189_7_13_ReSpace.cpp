#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

// TC: worse case for reSpace function O(L^2), where n is num of sentence length {"a"}, "aaaaaaaaj"
// SP: linear
// TODO: memo + minimizing the number of unrecognized characters
class Solution
{
public:
    struct Node
    {
        Node() : is_word(false), children(26, nullptr) {}
        ~Node()
        {
            for (const Node *child : children)
                if (child)
                    delete child;
        }

        int is_word;
        vector<Node *> children;
        string word;
    };

    Solution() : root_(new Node) {}

    void insert(const string &word)
    {
        Node *p = root_.get();
        for (const char c : word)
        {
            size_t i = c - 'a';
            if (!p->children[i])
                p->children[i] = new Node();
            p = p->children[i];
        }
        p->is_word = true;
        p->word = word;
    }

    bool reSpace(const vector<string> &str_vec, const string &sentence)
    {
        for (const string &str : str_vec)
            insert(str);
        vector<string> words;
        bool result = helper(sentence, 0, words);
        string new_sentence;
        for (size_t i = words.size() - 1; i < words.size(); --i)
            new_sentence += words[i] + ' ';
        new_sentence.pop_back();
        cout << new_sentence << endl;
        return result;
    }

private:
    bool helper(const string &sentence, size_t j, vector<string> &words)
    {
        if (j == sentence.size())
            return true;
        const Node *p = root_.get();
        for (size_t i = j; i < sentence.size(); ++i)
        {
            char c = sentence[i];
            p = p->children[c - 'a'];
            if (!p)
                return false;
            if (p->is_word)
                if (p->is_word && helper(sentence, i + 1, words))
                {
                    words.push_back(p->word);
                    return true;
                }
        }
        return false;
    }
    unique_ptr<Node> root_;
};

int main()
{
    vector<string> str_vec = {"jess", "jes", "looked", "just", "liked", "like", "tim", "he", "her", "brother"};
    string str = "jesslookedjustliketimherbrother";
    Solution s;
    cout << s.reSpace(str_vec, str) << endl;
    return 0;
}
