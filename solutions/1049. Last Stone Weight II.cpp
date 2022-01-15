int dp[40][50000];
class Solution {
public:
    int n;
    int func(int i,int a,vector<int>&arr){
        if(i==n)
            return abs(a);
        if(dp[i][a+6000]!=INT_MAX)
            return dp[i][a+6000];
        return dp[i][a+6000]=min(func(i+1,a+arr[i],arr),func(i+1,a-arr[i],arr));
    }
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        for(int i=0;i<40;i++)
            for(int j=0;j<50000;j++)
                dp[i][j]=INT_MAX;
        return func(0,0,stones);
    }
};
