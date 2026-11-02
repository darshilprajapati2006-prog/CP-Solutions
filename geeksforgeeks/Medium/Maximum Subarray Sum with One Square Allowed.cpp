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

/*
APPROACH: Kadane + 2-state DP

dp0 = best subarray sum ending at i, no square used yet
dp1 = best subarray sum ending at i, one square already used
For x = a[i], sq = x*x:
  new0 = max(x, dp0 + x)
  new1 = max(sq, dp0 + sq, dp1 + x)
Answer = max of dp0 and dp1 over all i.
Init: dp0 = a[0], dp1 = a[0]^2, loop from i = 1.
Time: O(N), Space: O(1)

Note: Don't find the best subarray first and then square one element,
because squaring can change which subarray is best.
*/
