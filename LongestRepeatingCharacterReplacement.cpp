#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;            // Left boundary of the sliding window
        int maxCount = 0;        // Stores the max frequency of any character in the current window
        unordered_map<char, int> charCount; // HashMap to count occurrences of each character
        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); right++) {
            charCount[s[right]]++; // Increment the count of the character at 'right' pointer
            
            // Update maxCount to track the highest frequency character in the current window
            maxCount = max(maxCount, charCount[s[right]]);
            /*
             * The condition (right - left + 1 - maxCount > k) checks if the window is invalid.
             * right - left + 1 gives the size of the window.
             * maxCount represents the highest occurring character's count in this window.
             * If the number of characters we need to replace (window size - maxCount) is greater than k,
             * it means we have exceeded the allowed replacements and need to shrink the window from the left.
             */
            if (right - left + 1 - maxCount > k) {
                charCount[s[left]]--; // Reduce the count of the character at 'left'
                left++; // Shrink the window by moving the left pointer forward
            }
        }
        /*
         * Since we never shrink the window if it is valid, the final window size 
         * (right - left) represents the longest valid substring we could achieve.
         */
        return s.size() - left;  
    }
};


