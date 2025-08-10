#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<vector<string>> board,int row,int col){
    for (int i = row - 1; i >= 0;i--){
        if(board[i][col]=="Q")
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
        if(board[i][j]=="Q")
            return false;    
    }
    for (int i = row - 1, j = col + 1; i >= 0 and j < board.size(); i--, j++){
        if(board[i][j]=="Q")
            return false;    
    }
    return true;
}
void nQueen(vector<vector<string>> &board,int n,int currRow){
    if(n==currRow){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n;col++){
        if(canPlace(board,currRow,col)){
            board[currRow][col] = "Q";
            nQueen(board, n, currRow + 1);
            board[currRow][col] = ".";         
        }
    }
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n, "."));
    nQueen(board, n, 0);
}