class Solution {
  public:
    int subarrayXor(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        if(n%2 == 0) return 0;
        for(int i=0;i<n;i+=2) ans ^= v[i];
        return ans;
    }
};

/*
APPROCH :
Steps:
1. Element arr[i] appears in (i+1) * (n-i) subarrays.
2. By the XOR rule (a ^ a = 0), an element with an even count cancels out; an odd count keeps it once.
3. The count is odd only when i is even and n is odd.
4. If n is even, return 0.
5. If n is odd, XOR all elements at even indices (0, 2, 4, ...) and return it.

Time Complexity : O(n)
Space Complexity : O(1)

note: Brute force would generate all O(n^2) subarrays; the counting trick avoids that completely.
*/
