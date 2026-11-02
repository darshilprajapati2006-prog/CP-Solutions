class Solution {
  public:
    int countSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<n;i++){
            if(i*i < n) v.emplace_back(i);
        }
        return v.size();
    }
};