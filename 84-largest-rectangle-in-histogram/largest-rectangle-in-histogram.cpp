class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        vector<int> right(n,0);
        for(int i = n-1;i>=0;i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i])
                 st.pop();
               if(st.empty())
                  right[i] = n;
                  else
                     right[i] = st.top();
                     st.push(i);  

        }
        while(!st.empty())
          st.pop();
          vector<int> left(n,0);
          for(int i =0;i<n;i++){
             while(st.size() > 0 && heights[st.top()] >= heights[i])
                 st.pop();
               if(st.empty())
                  left[i] = -1;
                  else
                     left[i] = st.top();
                     st.push(i);  


          }
          int answer = 0;
          for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            int currarea = heights[i]*width;
            answer = max(answer,currarea);          
            }
            return answer;
        
        
    }
};