class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k == 1){
            return subarraysWithAtMostK(nums, k);
        }
        else {
            return subarraysWithAtMostK(nums, k) - subarraysWithAtMostK(nums, k - 1);
        }
    }

    int subarraysWithAtMostK(vector<int>& nums, int k){
        int count = 0;
        unordered_map<int, int> freq;
        for(int left = 0, right = 0; right < nums.size(); right++){
            freq[nums[right]]++;
            while(freq.size() > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
