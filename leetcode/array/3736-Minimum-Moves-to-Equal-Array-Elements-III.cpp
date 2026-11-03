class Solution {
public:
    int minMoves(vector<int>& v) {
        int n = v.size(); 
        return ((*max_element(v.begin(),v.end()) * n) - accumulate(v.begin(),v.end(),0LL));
    }
};

/*
APPROCH :
Steps:
1. Find the maximum element of the array using max_element.
2. Every element can only be increased by 1 per move, so all elements must become equal to the maximum value.
3. The total value of the array after making all elements equal is max * n.
4. Find the current sum of the array using accumulate (with 0LL to avoid int overflow).
5. Return (max * n) - sum, which is the total number of increments needed.

Time Complexity : O(n)
Space Complexity : O(1)
note: Answer = (max * n) - sum. Using 0LL in accumulate keeps the sum in long long.
*/
