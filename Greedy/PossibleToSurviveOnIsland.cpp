int minimumDays(int S, int N, int M)
{
    if ((7 * M > 6 * N and S > 6) or N < M)
        return -1;
    return (S * M + N - 1) / N;
}
