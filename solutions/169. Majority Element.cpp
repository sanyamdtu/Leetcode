class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int val=arr[0],c=0;
        for(auto i:arr){
            if(i==val)
                c++;
            else{
                if(c==0)
                {
                    val=i;
                    c++;
                }
                else
                    c--;
            }
                
        }
        return val;
        
    }
};
