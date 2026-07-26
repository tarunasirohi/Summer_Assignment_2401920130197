class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int st = 0,end = 0,sum = 0,maxi = INT_MIN;
        while(end < fruits.size()){
            mpp[fruits[end]]++;
            sum++;
            if(mpp.size() <= 2){
                if(maxi < sum)
                  maxi = sum;
            }
           
            while(mpp.size() > 2){
                mpp[fruits[st]]--;
                sum--;
                if(mpp[fruits[st]] == 0)
                mpp.erase(fruits[st]);

                st++;
            }
          
            end++;
        }
        return maxi;
    }
};