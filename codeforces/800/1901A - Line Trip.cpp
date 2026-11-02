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