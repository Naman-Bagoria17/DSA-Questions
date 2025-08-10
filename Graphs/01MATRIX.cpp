class Solution {
public:
    vector<vector<int>> dir{{0,1},{-1,0},{1,0},{0,-1}};
    //Think Reverse Order
    //hint-shortest-path, use BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        set<pair<int,int>> visited;
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>> ans(rows,vector<int> (cols,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited.insert({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            visited.insert({i,j});//mark current cell visited
            for(int d=0;d<4;d++){
                int newRow=i+dir[d][0];//neighbour row
                int newCol=j+dir[d][1];//neighbour column
                if(newRow<0 || newRow>=rows || newCol<0 || newCol>=cols)continue;//if out of the grid
                if(visited.count({newRow,newCol}))continue;//if cell is already visited
                q.push({newRow,newCol});//else mark the current cell visietd
                ans[newRow][newCol]=min(ans[newRow][newCol],ans[i][j]+1);//so that distance dont get updated with larger value
            }
        }
        return ans;
    }
};