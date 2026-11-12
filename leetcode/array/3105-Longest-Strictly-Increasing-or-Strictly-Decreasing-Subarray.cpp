class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int n = v.size();
        int inc = 1, dec = 1, ans = 1;
        for(int i=0;i<n-1;i++){
            if(v[i]<v[i+1]){
                inc++;
                dec = 1;
            }
            else if(v[i]>v[i+1]){
                dec++;
                inc = 1;
            }
            else{
                inc = 1;
                dec = 1;
            }
            ans = max(ans,max(inc,dec));
        }
        return ans;
    }
};