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
    int left = 0;  
    int ans = 0; // Variable to store the maximum length of the substring
    int cnt[128] = {}; // track character occurrences (ASCII size 128)
    for (int right = 0; right < s.size(); right++) {
        cnt[s[right]]++; // Increment count of the current character
        // If a character appears more than once, move the left pointer 
        while (cnt[s[right]] > 1) {
            cnt[s[left]]--; // Decrease count (remove) of the leftmost character
            left++; // Move the left pointer forward
        }
        // Update the maximum length found so far
        ans = max(ans, right - left + 1);
    }
    return ans;
}}

*/
