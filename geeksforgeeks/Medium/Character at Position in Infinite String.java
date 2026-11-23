class Solution {
public:
    char posInfinite(string &s, int pos) {
        vector<long long> len;
        len.push_back(s.size());

        int i = 1;
        while (len.back() < pos) {
            long long L = len.back();
            len.push_back(2 * L + i);
            i++;
        }

        int level = len.size() - 1;
        for (int i = level; i >= 1; i--) {
            long long L = len[i - 1];

            if (pos <= L) {
            }
            else if (pos <= L + i) {
                return '$';
            }
            else {
                long long q = pos - (L + i);
                pos = L - q + 1;
            }
        }
        return s[pos - 1];
    }
};