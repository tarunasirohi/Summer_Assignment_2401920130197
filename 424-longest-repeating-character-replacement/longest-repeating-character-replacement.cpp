class Solution {
public:
    int characterReplacement(string s, int k) {

        int st = 0,end = 0,maxc = INT_MIN,maxi = INT_MIN;
        unordered_map<char,int> mpp;
        while(end < s.size()){
            mpp[s[end]]++;
            maxc = max(maxc,mpp[s[end]]);
            if((end-st+1)-maxc > k){
                mpp[s[st]]--;
                st++;
            }
            maxi = max(maxi,end-st+1);
            end++;
        }

        return maxi;
        
    }
};