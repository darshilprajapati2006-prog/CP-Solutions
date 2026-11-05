class Solution {
  public:
  
    vector<int> fibonacciNumbers(int n) {
        if(n==1) return {0};
        if(n==2) return{0,1};
        
        vector<int> res = fibonacciNumbers(n-1);
        int s = res.size();
        res.push_back(res[s-1]+res[s-2]);
        return res;
    }
};