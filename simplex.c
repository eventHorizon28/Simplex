#include<stdio.h>
#include<stdlib.h>

//this program calculates the optimal solution given the correct values from the simplex tableau

double** input_arr;

int main(int argc, char** argv)
{
    FILE* fp = NULL;
    int num_cols = -1, num_rows = -1;
    int i = -1, j = -1;
    double input_nums;
    if(argc != 2)
    {
        printf("enter 1 file name\n")
        return 0;
    }
    
    //opening file and getting num_rows and num_cols
    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &num_rows);
    fscanf(fp, "%d", &num_cols);
    
    //malloced: num_eqs = num_rows, num_vars = num_cols
    input_arr = (double**)malloc(num_rows*sizeof(double*));
    for(i = 0; i < num_rows; ++i)
    {
        input_arr[i] = (double*)malloc(num_cols*sizeof(double));
    }
    
    i = 0;
    while(i < num_rows)
    {
        for(j = 0; j < num_cols; ++j)
        {
            fscanf(fp, "%f", &input_nums);
            input_arr[i][j] = input_nums;
        }
        ++i;
    }
}
