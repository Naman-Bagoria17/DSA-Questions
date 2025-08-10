#include<bits/stdc++.h>
using namespace std;
int x[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int i, int j, vector<vector<int>>& board,int N)
{
    return (i >= 0 && i < N && j >= 0 && j < N && board[i][j] == -1);
}

bool knightTour(int i, int j, int cnt, int N, vector<vector<int>>& board)
{
    if (cnt == N * N)
    {
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cout << board[r][c] << "\t";
            }
            cout << endl;
        }
        return true;
    }

    for (int d = 0; d < 8; d++)
    {
        int nr = i + x[d];
        int nc = j + y[d];
        if (isSafe(nr, nc, board,N))
        {
            board[nr][nc] = cnt;
            if (knightTour(nr, nc, cnt + 1,N, board))
            {
                return true;
            }
            board[nr][nc] = -1;
        }
    }

    return false;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0;
    knightTour(0, 0, 1, N, board);
    return 0;
}
