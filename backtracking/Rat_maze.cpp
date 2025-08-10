#include<bits/stdc++.h>
using namespace std;
bool canWeGo(vector<vector<int>> &maze,int i,int j){
    return i < maze.size() and j < maze.size() and i >= 0 and j >= 0 and maze[i][j] == 1;
    //all above conditions must be true if you want to visit any cell
}
int total_paths(vector<vector<int>> &maze,int i,int j){
    if(i==maze.size()-1 && j==maze.size()-1){
        return 1;
    }
    int ans = 0;
    maze[i][j] = 2;
    if(canWeGo(maze,i-1,j)){//up
        ans+=total_paths(maze, i - 1,j);
    }
    if(canWeGo(maze,i,j+1)){//right
        ans+=total_paths(maze, i, j + 1);
    }
    if(canWeGo(maze,i+1,j)){//down
        ans+=total_paths(maze, i + 1, j);
    }
    if(canWeGo(maze,i,j-1)){//left
        ans+=total_paths(maze, i, j - 1);
    }

    maze[i][j] = 1;  //after checking all possibilties from a cell

    return ans;
}
int main(){
    vector<vector<int>> maze = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1}};
    cout << "Total number of paths are: " << total_paths(maze, 0, 0) << endl;
    return 0;
}