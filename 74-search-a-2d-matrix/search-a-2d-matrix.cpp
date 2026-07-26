class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row=matrix.size();
        int col=matrix[0].size();
        int st=0;
        int end=row*col-1;
        
        while(st<=end){
            int mid=(st+end)/2;

            int row_index=mid/col;
            int col_index=mid%col;
            if(matrix[row_index][col_index]==target)
            return true;
            else if(matrix[row_index][col_index]<target)
               st=mid+1;
               else
                 end=mid-1;
        }
        return false;
        
    }
};