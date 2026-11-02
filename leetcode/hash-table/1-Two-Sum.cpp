class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        int t = target;
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<s;i++){
            int r = t-nums[i];
            if(m.find(r)!=m.end()){
                v.push_back(i);
                v.push_back(m[r]);
            }
            else{
                m[nums[i]] = i;
            }
        }
    return v;
    }
};

/*
APPROCH :
Steps:
1. Create an unordered_map to store (value -> index) of elements seen so far.
2. For each element nums[i], find its complement: r = target - nums[i].
3. If r is already in the map, we found the pair.
   Return {i, m[r]}.
4. Otherwise, store the current element in the map: m[nums[i]] = i.
5. Move to the next element.

Time Complexity  : O(n)  (one pass, map lookup/insert is O(1) on average)
Space Complexity : O(n)  (map stores up to n elements)

note: don't use two nested loops (O(n^2)), use hash map to find the complement in O(1).
*/
