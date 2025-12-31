#include <stdio.h>
#include <stdlib.h>

int find(int a[], int f, int p)
{
    for (int i = 0; i < f; i++)
        if (a[i] == p)
            return i;
    return -1;
}

int main()
{
    int n, f;
    scanf("%d", &f);
    scanf("%d", &n);
    int *ref = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &ref[i]);
    int *frame = malloc(f * sizeof(int));
    int *recent = malloc(f * sizeof(int));
    for (int i = 0; i < f; i++)
    {
        frame[i] = -1;
        recent[i] = 0;
    }
    int time = 0, faults = 0;
    for (int i = 0; i < n; i++)
    {
        int p = ref[i];
        time++;
        int idx = find(frame, f, p);
        if (idx != -1)
        {
            recent[idx] = time;
        }
        else
        {
            int empty = -1;
            for (int j = 0; j < f; j++)
                if (frame[j] == -1)
                {
                    empty = j;
                    break;
                }
            if (empty != -1)
            {
                frame[empty] = p;
                recent[empty] = time;
            }
            else
            {
                int victim = 0;
                for (int j = 1; j < f; j++)
                    if (recent[j] < recent[victim])
                        victim = j;
                frame[victim] = p;
                recent[victim] = time;
            }
            faults++;
        }
    }
    printf("LRU page faults: %d\n", faults);
    free(ref);
    free(frame);
    free(recent);
    return 0;
}
