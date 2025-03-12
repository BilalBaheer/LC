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
 
