class Solution {
  public:
    int largestSumCycle(vector<int> &edge) {

        int n = edge.size();
        vector<int> walkId(n, -1);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (walkId[i] != -1) continue;

            int node = i;
            while (node != -1 && walkId[node] == -1) {
                walkId[node] = i;
                node = edge[node];
            }

            if (node != -1 && walkId[node] == i) {
                int sum = node;
                int cur = edge[node];
                while (cur != node) {
                    sum += cur;
                    cur = edge[cur];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};


        /*
        APPROCH :
        Steps:
        1. Create a walkId[] array (all -1) and set ans = -1.
        2. For every cell i, if walkId[i] == -1, start a new walk with id = i.
        3. Move along the edges, setting walkId[node] = i for every node visited.
        4. Stop if edge[node] == -1 (dead end) or the next node has an older walk id (no new cycle).
        5. If the next node has walkId == i, a cycle is found.
        6. Starting from that node, travel around the cycle once and add all indices to get the sum.
        7. Update ans = max(ans, sum). Return ans at the end.

        Time Complexity : O(n)
        Space Complexity : O(n)

        note: Each cell has at most one outgoing edge, so a cell can be part of only one cycle.
        Only the nodes from the repeated node back to itself are summed, not the tail before the cycle.
        */