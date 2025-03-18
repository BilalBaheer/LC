/* Approach
In my approach, we are going to use hash maps because it's a bit easier. We will have a reference map, where it's noted which word and how many times it should be repeated.

The next step is to iterate through s as many times as the length of each string in words with different word offset. Let me illustrate this with an example.
Imagine we have a string "abbarfoofoobarthe" and words are ["foo", "bar", "the"]. The length of eache word is 3, so we need 3 iterations. They symbolize the splits we make in the string s:

abb arf oof oob art he
a bba rfo ofo oba rth e
ab bar foo foo bar the
This way, in the inner cycle, we can iterate with bigger steps and use a sliding window.
The last step is to use a sliding window. Here is how it's going to work:

We define a hash map to keep track of how many times we have seen each word.
We define a sliding window size to keep track of how many words from the words array we have managed to use in our sliding window so far.
We assume that the sliding window is valid; as soon as we find any condition that makes it invalid, we deal with it.
On each iteration, we take a slice of s from the current index and check if this word exists in the reference map; if it does not, we clear our window and move on.
If the candidate word exists in the reference map, we increment the number of occurrences of this word in our seen map.
If we check this amount against the reference, and if it's bigger, we need to shrink our window from the left until the condition is satisfied.
Naturally, the sliding window will grow to the right, so when its size reaches the size of the words array, we have found the correct position, and we record the left side of the window to the result array.

*/

class Solution {
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        unsigned int length = words[0].size();

        map.clear();
        for (const std::string& word : words)
            map[word]++;

        for (unsigned int offset = 0; offset < length; ++offset) {
            unsigned int size = 0;
            std::unordered_map<std::string, unsigned int> seen;
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                std::string sub = s.substr(i, length);

                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[sub];
                ++size;
                while (seen[sub] > itr->second) {
                    std::string first = s.substr(i - (size - 1) * length, length);
                    --seen[first];
                    --size;
                }
                
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};


