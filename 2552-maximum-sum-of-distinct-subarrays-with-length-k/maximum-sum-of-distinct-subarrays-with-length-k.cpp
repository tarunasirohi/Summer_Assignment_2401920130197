class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

       long long st = 0,end = 0,sum = 0,maxi = INT_MIN;
        bool re = false;
    
        unordered_map<int,int> mpp;
        while(end < nums.size()){
        
            sum += nums[end];
            mpp[nums[end]]++;
            
            
            while(mpp[nums[end]] > 1){
                mpp[nums[st]] -= 1;
                sum = sum-nums[st];
                st++;
            }
            
            if((end-st+1 == k)){
                 re = true;
                maxi = max(maxi,sum);
                sum = sum - nums[st];
                mpp[nums[st]]--;
                st++;
            }
            
            
            end++;
        }
        if(re == false)
          return 0;

        return maxi;
    }
    
};