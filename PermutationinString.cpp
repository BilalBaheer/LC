 bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        for(char c : s1) {
            s1Count[c - 'a']++;
        }
        for(int i = 0; i<s1.length(); i++) {
            windowCount[s2[i] - 'a']++;
        }
        if(s1Count == windowCount) {
            return true;
        }
        for (int i = s1.length(); i < s2.length(); i++) {
            windowCount[s2[i] - 'a']++;
            windowCount[s2[i - s1.length()] - 'a']--;
            if(s1Count == windowCount) return true;
        }
        return false;
    }
