class Solution {
public:
    long long minTime(int n, int s1, int s2) {
        long long lo = 1, hi = (long long)min(s1, s2) * n;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (mid / s1 + mid / s2 >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};