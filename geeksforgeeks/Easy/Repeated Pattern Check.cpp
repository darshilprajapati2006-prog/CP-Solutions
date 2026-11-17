
class Solution {
public:
    bool findPattern(string &s) {
        int n = s.size();
        int i = 0;

        while (i < n) {

            // Count consecutive x
            int cntX = 0;

            while (i < n && s[i] == 'x') {
                cntX++;
                i++;
            }

            // Count consecutive y
            int cntY = 0;

            while (i < n && s[i] == 'y') {
                cntY++;
                i++;
            }

            // Validate current pattern
            if (cntX == 0 || cntX != cntY) {
                return false;
            }
        }

        return true;
    }
};
