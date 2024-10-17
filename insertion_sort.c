#include<stdio.h>

#define SIZE 6

typedef struct{
    int iterations;
    int comparisons;
}sort_value;

sort_value insertion_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
    int arr[SIZE] = {55,44,22,66,11,33};
     printf("\n Before sort :\n");
    display(arr);
    sort_value value = insertion_sort(arr);
    printf("\n After sort :\n");
    insertion_sort(arr);
    display(arr);
    printf("\nIterations = %d Comparisons = %d\n",value.iterations, value.comparisons);

    
    display(arr);    

    return 0;
}

sort_value insertion_sort(int arr[SIZE])
{
    int i,j,temp;
    sort_value value = {0, 0};

    for(i=1; i< SIZE; i++)
    {
        value.iterations++;
        temp = arr[i];
        for(j = i-1;j>=0 && temp < arr[j] ;j--)
        {
            value.comparisons++;
            // 1) shift arr[j] to j+1 index
            arr[j+1] = arr[j];
        }

        arr[j+1] = temp;
    }
    return value;
}

void display(int arr[SIZE])
{
    for(int i =0; i< SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}