// praktika_3_islamov.cpp 
//var 8, Дана действительная квадратная матрица 
//порядка 2n.Найти наибольшее из значений
//элементов, расположенных в заштрихованной части матрицы

#include <iostream>
#include <math.h>
#include <stdio.h>

const int R(10), N(10);
int main()
{
	system("chcp 1251");
	system("cls");
 
    srand(time(NULL));
    int i, j, arr[R][N], x, max = -19999;
    for (i = 0; i < R; i++)
        for (j = 0; j < R; j++)
            arr[i][j] = rand() % 1000;
    for (i = 0; i < R; i++) {
        for (j = 0; j <R; j++)
            printf("%d\t", arr[i][j]);
        printf("\n\n");
    }
    for (i = 1; i < N; ++i)
    {
        for (j = 1; j < N; ++j)
            if (i > j && i + i<N - 1 && arr[i][j]>max)
                max = arr[i][j];
            else if (i<j && i + i>N - 1 && arr[i][j] > max)
                max = arr[i][j];
    }
    printf("%d", max);
    return 0;
   
}

