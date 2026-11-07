
class Solution {
public:
    vector<string> generateUsernames(vector<string> a) {
        unordered_set<string> used;
        unordered_map<string, int> cnt;
        for (string x : a) {
            used.insert(x);
        }

        for (int i = 0; i < a.size(); i++) {
            string x = a[i];

            if (cnt[x] == 0) {
                cnt[x]++;
                continue;
            }

            int k = 1;
            string candidate;

            do {
                candidate = x + to_string(k);
                k++;
            } 
            while (used.count(candidate));

            a[i] = candidate;
            used.insert(candidate);
            cnt[x]++;
        }

        return a;
    }
};

