class Solution {
  public:
    int maximumSubarray(vector<int>& a) {
        int n = a.size();
        int dp0 = a[0];
        int dp1 = 1LL * a[0] * a[0];
        int ans = max(dp0,dp1);
        
        for(int i=1;i<n;i++){
            int x = a[i];
            int sq = x * x;
            int new0 = max(x,dp0+x);
            int new1 = max(sq,max(dp0+sq,dp1+x));
            
            dp0 = new0;
            dp1 = new1;
            ans = max(ans,max(dp0,dp1));
        }
        return ans;
    }
};