#include <bits/stdc++.h>
using namespace std;
// place k knights on a m*n chessboard
bool canPlace(vector<vector<char>> &board, int m, int n, int r, int c)
{
    //sirf uper check krna hai
    if (r - 2 >= 0 and c - 1 >= 0 and board[r - 2][c - 1] == 'K')
        return false;
    if (r - 2 >= 0 and c + 1 < n and board[r - 2][c + 1] == 'K')
        return false;
    if (r - 1 >= 0 and c - 2 >= 0 and board[r - 1][c - 2] == 'K')
        return false;
    if (r - 1 >= 0 and c + 2 < n and board[r - 1][c + 2] == 'K')
        return false;
    return true;
}
void place_k_knights(vector<vector<char>> &board, int m, int n, int k, int i, int j)
{
    if (k == 0)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "***" << endl << endl;
        return;
    }
    if (i == m)
    { // all placed
        return;
    }
    if (j == n)
    {   //move to next row
        place_k_knights(board, m, n, k, i + 1, 0);
        return;
    }
    // basically i,j are denoting ki unse pehle jo cells hai saare uper bhi aur left bhi vo saare me hum Knights rkh chuke hai jaha bhi possible tha. Ab hume current jo Knight hai isko bache hue jitne bhi possibilites hai right me aur niche vaha sb me rkh ke dekhna hai. That's why using for loop
    for (int r = i; r < m; r++)
    {
        // qki if you are in ith row to us row me aap pichhe to ni place kroge bcz those cells are already visited and if row i se niche vaali hai then 0th col se start krna pdega
        for (int c = (r == i ? j : 0); c < n; c++)
        {
            if (canPlace(board, m, n, r, c))
            {
                board[r][c] = 'K';
                place_k_knights(board, m, n, k - 1, r, c + 1);
                board[r][c] = '.';
            }
        }
    }
}

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<char>> board(m, vector<char>(n, '.'));
    place_k_knights(board, m, n, k, 0, 0);
}