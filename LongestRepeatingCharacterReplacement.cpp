class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0; int maxCount = 0; 
    unordered_map<char, int> charCount; 
    for (int right = 0; right < s.size(); right++) {
        charCount[s[right]]++; // [A: 1] -> [A : 1], [B,1]
        maxCount = max(maxCount, charCount[s[right]]);
// Calculate the size of the current window, 
        if (right - left + 1 - maxCount > k) {
            charCount[s[left]]--; // remove left char from map
            left++; }
    }
// Also check for the left boundary position
    return s.size() - left;    }
};
