class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        sort(arr.begin(),arr.end(),greater<int>());
        deque<int> d;
        d.push_back(arr[0]);
        for(int i=1;i<n;i++){
            // cout<<arr[i]<<" ";
            // for(auto i:d){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            d.push_front(d.back());
            d.pop_back();
            d.push_front(arr[i]);
        }
        for( auto i:d){
            ans.push_back(i);
        }
        return ans;
    }
};
