class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k =  k % (m*n) ;
        vector<vector<int>> ans = grid;
        while(k>0){
            for(int i=0 ; i<m ; i++){
                for(int j=0 ; j< n ; j++){
                    if(i == 0 && j==0){
                        ans[i][j] = grid[m-1][n-1];
                    }else if(i != 0 && j==0){
                        ans[i][j] = grid[i-1][n-1];
                    }else{
                        ans[i][j] = grid[i][j-1];
                    }
                }
            }
            grid = ans;
            k--;
        }
        return ans;
    }
};