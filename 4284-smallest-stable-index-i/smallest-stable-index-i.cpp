class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int score,m = INT_MAX;
        bool re = false;
        for(int i = 0;i<nums.size();i++){
            int mini = INT_MAX,maxi = INT_MIN;
            for(int j=0;j<=i;j++){
                maxi = max(nums[j],maxi);
            }
            for(int l = i;l<nums.size();l++){
                mini = min(nums[l],mini);
            }
            score = maxi-mini;
            if(score <= k){
                 re = true;
                
                 m = min(m,i);
            }
        }
        if(re)
              return m;
        return -1;
        
    }
};