class Solution {
public:
    int maxProfit(vector<int>& arr, int c) {
        int n=arr.size();
        if(n==0)
            return 0;
        int cash=0,hold=-arr[0];
        for(int i=1;i<n;i++){
            cash=max(cash,hold+arr[i]-c);
            hold=max(cash-arr[i],hold);
        }
        return cash;
    }
};
