// Bubble sort

#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp = a; a=b; b = temp;

typedef struct{
    int iterations;
    int comparisons;
}sort_value;

sort_value bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{

    int arr[SIZE] = {11,99,33,44,55,66};
    printf("\n Before sort :\n");
    display(arr);
    sort_value value = bubble_sort(arr);
    printf("\n After sort :\n");
    bubble_sort(arr);
    display(arr);
    printf("\nIterations = %d Comparisons = %d\n",value.iterations, value.comparisons);
    
    return 0;
}

sort_value bubble_sort(int arr[SIZE])
{
    int its,pos;
    sort_value value = {0,0};
    for(its = 0;its < SIZE-1; its++)
    {
        value.iterations++;
        for(pos=0;pos < SIZE-1-its;pos++)
        {
            value.comparisons++;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);

            }
        }
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

// Efficient bubble sort

/*void Efficient_Bubble_Sort(int arr[SIZE])
{
    int its,pos;
    int iterations = 0, comparisons = 0,flag;
    for(its = 0;its < SIZE-1; its++)
    {
        flag = 0;
        iterations++;
        for(pos=0;pos < SIZE-1-its;pos++)
        {
            comparisons++;
            if(arr[pos] > arr[pos+1])
            {
                // swap
                SWAP(arr[pos],arr[pos+1]);
                flag = 1;

            }
        }
        if(flag == 0)
            break;
    }
    printf("\n Iterations = %d comparisons = %d\n",iterations,comparisons);
}*/