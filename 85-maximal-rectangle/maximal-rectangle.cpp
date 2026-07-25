class Solution {
public:
    int rectangle(vector<int>& he){
        stack<int> st;
        int n = he.size();
        int ar = 0;
        int idx;
        for(int i = 0;i<n;i++){
            while(st.size() > 0 && he[st.top()] > he[i])
                {
                         idx = st.top();
                         st.pop();
                         if(! st.empty())
                           ar = max(ar,he[idx]*(i-st.top()-1));
                           else
                           ar = max(ar,he[idx]*i);
                }
                st.push(i);
                       }
                       while(! st.empty()){
                        idx = st.top();
                          st.pop();
                           if(! st.empty())
                           ar = max(ar,he[idx]*(n-st.top()-1));
                           else
                           ar = max(ar,he[idx]*n);
                       }
                       return ar;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ht(col,0);
          for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == '0')
                    ht[j] = 0;
                    else
                      ht[j] += 1;

            }
            ans = max(ans,rectangle(ht));
          }
          return ans;

        
    }
};