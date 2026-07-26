class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int>ans;
        int st=0,end=numbers.size()-1;
        while(end>st){
            if(numbers[st]+numbers[end]==target){
                ans.push_back(st+1);
                ans.push_back(end+1);
                return ans;

            }
            else if(numbers[st]+numbers[end]<target){
                st++;
            }
            else
            end--;
        }
        return ans;

        
    }
};