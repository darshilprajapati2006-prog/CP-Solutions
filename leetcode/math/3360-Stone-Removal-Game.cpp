class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int turn = 0;
        while (n >= take) {
            n -= take;
            take--;
            turn++;
        }
        return turn % 2 == 1;
    }
};