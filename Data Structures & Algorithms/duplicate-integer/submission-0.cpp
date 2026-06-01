class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) return true;
            else continue;
        }

        return false;
    }
};