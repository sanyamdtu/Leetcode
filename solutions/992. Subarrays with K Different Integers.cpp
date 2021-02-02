class Solution {
public:
    int subarraysWithKDistinct(vector<int>&s, int k) {
        unordered_map<int, int> m;
        int c = 0, n = s.size();
        int i = 0, j = 0, ans = 0, p = 0;
        while (j < n)
        {
            m[s[j]]++;
            if (m[s[j]] == 1)
                c++;
            while (c > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    c--;
                p = 0;
                i++;
            }
            while (m[s[i]] > 1)
            {
                m[s[i]]--;
                i++;
                p++;
            }
            if (c == k)
                ans += p + 1;
            j++;
        }
        return ans;
    }
};
