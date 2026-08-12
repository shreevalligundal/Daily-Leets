class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element to the window
            freq[nums[right]]++;

            // If current window becomes invalid,
            // shrink it from the left
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Current window is valid
            int currentLength = right - left + 1;

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};