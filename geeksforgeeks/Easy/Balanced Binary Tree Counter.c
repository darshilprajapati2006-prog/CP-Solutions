class Solution {
  public:
    int countBT(int h) {
        long long MOD = 1e9 + 7;
        if(h<=1) return 1;
        
        long long t_minus_2 = 1;
        long long t_minus_1 = 1;
        long long current = 0;
        
        if(h>1){
            for (int i = 2; i <= h; ++i) {
                current = (t_minus_1 * t_minus_1 + 2 * t_minus_1 * t_minus_2) % MOD;
                    t_minus_2 = t_minus_1;
                    t_minus_1 = current;
                }
            return t_minus_1;
        }
    }
};