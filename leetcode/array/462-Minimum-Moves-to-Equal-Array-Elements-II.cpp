class Solution {
public:
    int minMoves2(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int med= v[n/2];
        int ans = 0;
        for(int x : v){
            ans += abs(x-med);
        }
        return ans;
    }
};

/*
APPROCH :
Steps:
1. Sort the array.
2. Take median = v[n/2].
3. Sum up |v[i] - med| for all i.
4. Return the sum.

Time Complexity  : O(n log n)  (sorting)
Space Complexity : O(1)        (ignoring sort's internal stack)

note: don't find mean then solve que.
*/
