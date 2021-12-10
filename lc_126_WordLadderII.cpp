#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// TC: O(26nm^2), the most inner loop has string comparison which takes m, we do it 26 times for each letter of a word (26m^2), worst case needs to loop over all n words
// SC: O(nm), need a queue and unordered_set
class Solution
{
public:
    vector<vector<string>> findLadders(string begin_word, string end_word, vector<string> &word_list)
    {
        vector<vector<string>> result;
        if (!word_list.size())
            return result;

        unordered_set<string> word_dict(word_list.begin(), word_list.end());
        queue<vector<string>> path_queue;
        path_queue.push({begin_word});

        unordered_set<string> visited;
        while (path_queue.size())
        {
            size_t size = path_queue.size();
            // for each loop we have all elements in the layer at this line
            for (size_t i = 0; i < size; ++i)
            {
                vector<string> curr_path = path_queue.front();
                string word = curr_path[curr_path.size() - 1];
                path_queue.pop();
                visited.insert(word);
                for (size_t j = 0; j < word.size(); ++j)
                {
                    char word_j = word[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (word[j] == c)
                            continue;
                        word[j] = c;
                        if (word_dict.count(word))
                        {
                            visited.insert(word);
                            vector<string> new_path(curr_path);
                            new_path.push_back(word);
                            path_queue.push(new_path);
                            if (word == end_word)
                            {
                                result.push_back(new_path);
                                break;
                            }
                        }
                    }
                    word[j] = word_j;
                }
            }
            for (const auto &str : visited)
                word_dict.erase(str);
            visited.clear();
        }

        return result;
    }
};

int main()
{
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    vector<vector<string>> result = s.findLadders(begin_word, end_word, word_list);
    for (const vector<string> &str_vec : result)
    {
        for (const string &str : str_vec)
            cout << str << " ";
        cout << endl;
    }

    return 0;
}