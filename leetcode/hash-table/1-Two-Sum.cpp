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