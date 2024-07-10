/* Problem 22: numbers Scores
 * Sort numbers.txt into alphabetical order, then determine the alphabetical
 * value for each name and multiply this value by its alphabetical
 * position in the list to obtain a name score.
 * 
 * Ex: COLIN in this list is worth 3 + 15 + 12 + 9 + 14 = 53 * 938th place,
 * which means its name score is 49714.
 * 
 * What is the total of all the numbers scores in the file?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

void quicksort(int *, int, int);

int main(void){

    FILE * data = fopen("numbers.txt", "r");
    if(data == NULL){
        printf("error reading file");
        return 1;
    }

    // determine amount of numbers
    int amount = 0;

    int temp;
    while(fscanf(data, "%d,", &temp) == 1)
        amount++;

    // store all numbers
    int * numbers = malloc(sizeof(int) * amount);
    long position = 0;

    rewind(data);
    while(fscanf(data, "%d,", &numbers[position]) == 1)
        position += 1;

    fclose(data);

    for(int i = 0; i < amount; i++)
        printf("%d,", numbers[i]);
    printf("\n=======================\n");

    // sort all numbers
    quicksort(numbers, 0, amount - 1);

    for(int i = 0; i < amount; i++)
        printf("%d,", numbers[i]);
    printf("\n");

    free(numbers);
    return 0;
}

void quicksort(int * numbers, int left_pos, int right_pos){

    // already sorted
    if(right_pos <= left_pos)
        return;

    int left_pos_initial = left_pos;
    int right_pos_initial = right_pos;

    // find median-of-three pivot
    int pivot;
    if(numbers[(left_pos + right_pos) / 2] < numbers[left_pos]){
        pivot = numbers[left_pos];
        numbers[left_pos] = numbers[(left_pos + right_pos) / 2];
        numbers[(left_pos + right_pos) / 2] = pivot;
    }
    if(numbers[right_pos] < numbers[left_pos]){
        pivot = numbers[right_pos];
        numbers[right_pos] = numbers[left_pos];
        numbers[left_pos] = pivot;
    }
    if(numbers[(left_pos + right_pos) / 2] < numbers[right_pos]){
        pivot = numbers[right_pos];
        numbers[right_pos] = numbers[(left_pos + right_pos) / 2];
        numbers[(left_pos + right_pos) / 2] = pivot;
    }
    pivot = numbers[right_pos];

    // move elements to correct sides
    while(1){
        // seek invertible pair
        while(numbers[left_pos] <= pivot && left_pos < right_pos)
            left_pos++;
        while(numbers[right_pos] >= pivot && right_pos > left_pos)
            right_pos--;

        // elements are on correct sides
        if(left_pos >= right_pos)
            break;

        // swap elements
        int temp = numbers[right_pos];
        numbers[right_pos] = numbers[left_pos];
        numbers[left_pos] = temp;
    }

    // move pivot to center
    if(pivot <= numbers[right_pos]){
        int temp = numbers[right_pos];
        numbers[right_pos] = pivot;
        numbers[right_pos_initial] = temp;
    }
    else{
        int temp = numbers[right_pos + 1];
        numbers[right_pos + 1] = pivot;
        numbers[right_pos_initial] = temp;
    }

    // recurse left
    quicksort(numbers, left_pos_initial, left_pos - 1);
    // recurse right
    quicksort(numbers, right_pos + 1, right_pos_initial);
}
