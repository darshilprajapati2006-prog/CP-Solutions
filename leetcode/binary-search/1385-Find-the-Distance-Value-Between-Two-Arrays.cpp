class Solution {
public:
    int findTheDistanceValue(vector<int>& v1, vector<int>& v2, int d) {
        int n1 = v1.size();
        int n2 = v2.size();
        int ans = 0;
        for(int i=0;i<n1;i++){
            int count = 0;
            for(int j=0;j<n2;j++){
                if(abs(v2[j]-v1[i])>d) count++;
            }
            if(count == n2) ans++;
        }
        return ans;
    }
};