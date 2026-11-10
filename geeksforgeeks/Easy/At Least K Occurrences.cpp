
class Solution {
public:
    int firstElementKTime(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[a[i]]++;
            if(m[a[i]] == k) {
                return a[i];
            }
        }
        return -1;
    }
};
