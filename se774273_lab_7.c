#include <stdio.h>

int main()
{
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = 9; // size of the array

    int swaparray[]={0,0,0,0,0,0,0,0,0};

    bubbleSort(arr, n,swaparray);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n",swaparray[i]);
    }
    return 0;
}

void bubbleSort(int arr[], int n,int swaparray[])
{

    int i, j, temp;
    for (i = 0; i < n ; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaparray[j]++;
            }
            
        }
    }
}