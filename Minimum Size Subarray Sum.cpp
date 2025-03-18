class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currSum = 0;
        int ans = INT_MAX;
        for(int r = 0; r<nums.size(); r++) {
            currSum += nums[r];
            while(currSum >= target) {
                ans = min(ans, r-left+1);
                currSum -= nums[left];
                left++;
            }
        }
      // If the condition (ans == INT_MAX) is true, it returns 0 esle answer
        return (ans == INT_MAX) ? 0 : ans;
        }
};
        
