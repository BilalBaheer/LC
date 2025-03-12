//3. Longest Substring Without Repeating Characters (Medium)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int ans = 0;
        int left = 0;
        for(int right = 0; right<s.size(); right++){
            while(charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
 
/*
// another possible solution
int lengthOfLongestSubstring(string s) {
    int i = 0;  // Left pointer for the sliding window
    int ans = 0; // Variable to store the maximum length of the substring
    int cnt[128] = {}; // Array to track character occurrences (ASCII size 128)
    for (int j = 0; j < s.size(); j++) {
        cnt[s[j]]++; // Increment count of the current character
        // If a character appears more than once, move the left pointer (i)
        while (cnt[s[j]] > 1) {
            cnt[s[i]]--; // Decrease count of the leftmost character
            i++; // Move the left pointer forward
        }
        // Update the maximum length found so far
        ans = max(ans, j - i + 1);
    }
    return ans;
}

*/
