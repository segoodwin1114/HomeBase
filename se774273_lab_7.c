#include <stdio.h>
#include <stdlib.h>

int main (){
    int array[10] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size = 9;
    int swaps = 0;
      for(int i = 0; i < size - 1; i++){

        for(int j = 0; j < size - i - 1; j++){

            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps++;
            }
        }
    }
    printf("The amount of total swaps is: %d", swaps);
}



