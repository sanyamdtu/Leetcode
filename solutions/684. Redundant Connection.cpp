/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
​
// @lc code=start
​
class Solution
{
    int func(int pa[], int k)
    {
        if (pa[k] == k)
            return k;
        return func(pa, pa[k]);
    }
​
public:
    vector<int> findRedundantConnection(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int par[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            par[i] = i;
        }
        vector<int> ans;
        for (auto i : arr)
        {
            // cout << func(par, i[0]) << " " << func(par, i[1]) << endl;
            if (func(par, i[0]) == func(par, i[1]))
            {
                ans = i;
            }
            else
            {
                par[func(par, i[0])] = func(par, i[1]);
            }
        }
        return ans;
    }
};
// @lc code=end
​
