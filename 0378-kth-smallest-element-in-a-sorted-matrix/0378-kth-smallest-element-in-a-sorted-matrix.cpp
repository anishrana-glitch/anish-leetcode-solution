class Solution {
public:
int fun(vector<vector<int>> &matrix, int m, int n, int guess){
    int row=m-1;
    int col=0;
    int count=0;
    while(row>=0 and col<n){
        if(matrix[row][col]<=guess){
            count=count+row+1;
            col++;
        }
        else
        row--;
    }
    return count;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m= matrix.size();
        int n=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[m-1][n-1];
        int res=-1;
        while (low<=high)
        {
            int guess=low+(high-low)/2;
            int ans=fun(matrix,m,n,guess);
            if(ans<k)
            low=guess+1;
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};