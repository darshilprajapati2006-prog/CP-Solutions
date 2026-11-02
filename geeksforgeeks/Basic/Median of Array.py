class Solution {
  public:
    double findMedian(vector<int> &v) {
        int n = v.size();
        sort(v.begin(),v.end());
        double odd = v[n/2];
        double even = (v[(n/2)-1] + v[n/2])/2.0;
        if(n%2 != 0) return odd;
        else return even;
    }
};