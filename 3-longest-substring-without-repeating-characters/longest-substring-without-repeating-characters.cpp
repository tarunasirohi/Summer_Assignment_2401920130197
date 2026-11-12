class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s == "")
          return 0;
      unordered_map<char,bool> mpp;
      int st = 0,end = 0;
      int m = INT_MIN;
      while(end < s.size()){
        while(mpp[s[end]] == true){
            mpp[s[st]] = false;
            st++;
        }
        mpp[s[end]] = true;
        m = max(m,end-st+1);
        end++;
      }
      return m;
    
    }
};