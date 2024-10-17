#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp = a; a=b; b=temp;

typedef struct{
    int iterations;
    int comparisons;
}sort_value;



sort_value selection_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
   // int arr[SIZE] = {30,20,60,50,10,40};
   int arr[SIZE] = {11,34,33,88,55,66};
    printf("\n Before sort :\n");
    display(arr);
    sort_value value = selection_sort(arr);
    printf("\n After sort :\n");
    display(arr);
    printf("\nIterations = %d Comparisons = %d\n",value.iterations, value.comparisons);

    return 0;
}

sort_value selection_sort(int arr[SIZE])
{
    int sel_pos,pos;
    sort_value value = {0, 0};

    // Iterations
    for(sel_pos = 0;sel_pos < SIZE-1; sel_pos++)
    {
        value.iterations++;
        for(pos = sel_pos+1; pos < SIZE; pos++)
        {
            value.comparisons++;
            if(arr[sel_pos] > arr[pos])
            {
                // swap
                SWAP(arr[sel_pos],arr[pos]);
                /*
                    int temp = arr[sel_pos];
                    arr[sel_pos] = arr[pos];
                    arr[pos] = temp;
                
                */
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