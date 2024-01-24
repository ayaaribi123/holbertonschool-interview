#include "sandpiles.h"
#include <stdio.h>

static void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d%s", grid[i][j], j < 2 ? " " : "\n");
    }
}

void copy(int scr[3][3], int des[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            des[i][j] = scr[i][j];
}

int check(int grid[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] > 3)
                return 0;
    return 1;
}

void sum(int grid1[3][3], int grid2[3][3]) {
    int referenceGrid[3][3];
    int type = 0;

    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            grid1[x][y] += grid2[x][y];

    type = check(grid1);
    if (type == 1) return;

    printf("=\n");
    print_grid(grid1);

    while (type == 0) {
        copy(grid1, referenceGrid);

        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (referenceGrid[x][y] > 3) {
                    grid1[x][y] -= 4;
                    for (int i = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            if (i || j)
                                if (x + i >= 0 && x + i < 3 && y + j >= 0 && y + j < 3)
                                    grid1[x + i][y + j]++;
                }

        type = check(grid1);
        if (type == 1) break;

        printf("=\n");
        print_grid(grid1);
    }
}
