#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int rectangleSize;
    int *rectangleColSize;
    int **rectangle;

} SubrectangleQueries;

SubrectangleQueries *subrectangleQueriesCreate(int **rectangle, int rectangleSize, int *rectangleColSize)
{
    SubrectangleQueries *obj = (SubrectangleQueries *)malloc(rectangleSize * *rectangleColSize * (sizeof **rectangle));
    obj->rectangle = rectangle;
    obj->rectangleColSize = rectangleColSize;
    obj->rectangleSize = rectangleSize;
    return obj;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries *obj, int row1, int col1, int row2, int col2, int newValue)
{
}

int subrectangleQueriesGetValue(SubrectangleQueries *obj, int row, int col)
{
    return *(*(obj->rectangle + row) + col);
}

void subrectangleQueriesFree(SubrectangleQueries *obj)
{
}

int my_randi()
{
    return (rand() % 10) + 1;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int row = 4;
    int col = 3;
    int **arr2d;
    arr2d = (int **)malloc(row * (sizeof *arr2d));
    unsigned int i;
    unsigned int j;
    for (i = 0; i < row; i++)
    {
        *(arr2d + i) = (int *)malloc(col * (sizeof *(arr2d + i)));
        for (j = 0; j < col; j++)
        {
            *(*(arr2d + i) + j) = my_randi();
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", *(*(arr2d + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < row; i++)
        free(*(arr2d + i));

    free(arr2d);

    return 0;
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
 
 * int param_2 = subrectangleQueriesGetValue(obj, row, col);
 
 * subrectangleQueriesFree(obj);
*/