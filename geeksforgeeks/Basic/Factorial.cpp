class Solution {
  public:
    int factorial(int n) {
        int p = 1;
        for(int i=2;i<=n;i++){
            p *= i;
        }
        return p;
    }
};