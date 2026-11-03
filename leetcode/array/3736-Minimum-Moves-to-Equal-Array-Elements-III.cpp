class Solution {
public:
    int minMoves(vector<int>& v) {
        int n = v.size(); 
        return ((*max_element(v.begin(),v.end()) * n) - accumulate(v.begin(),v.end(),0LL));
    }
};