#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ans.push_back(v[0]-0);
    for(int i=0;i<n-1;i++){
        ans.push_back(v[i+1]-v[i]);
    }
    ans.push_back(2*(x-v[n-1]));
    cout<< *max_element(ans.begin(),ans.end()) <<'\n';
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t = 1;
cin >> t; 
while (t--) solve();
return 0;
}

/*
APPROCH :
Steps:
1. Read n, x and the gas station positions into a vector v (sorted already).
2. The tank capacity must cover the longest stretch driven without refuelling,
   so compute all such stretches and take their maximum.
3. First gap: distance from start to the first station = v[0] - 0.
4. Middle gaps: distance between consecutive stations = v[i+1] - v[i].
5. Last gap: the car must go from the last station to x and come back to the
   same station (there is no station at x), so the gap is 2 * (x - v[n-1]).
6. Answer = maximum of all these gaps.

Time Complexity  : O(n)  (single pass over the stations)
Space Complexity : O(1)  (only a running maximum is kept; O(n) if you store all gaps in a vector)

note: the return trip is the trick. The last gap is doubled because the car
cannot refuel at x, so it must cover x and back in one go.
*/
