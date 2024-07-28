#include <stdlib.h>

#include "algorithms/dynamic-arrays/array-based/vector_array.h"

/* --- utility function prototypes --- */

// double the size of the data array in the provided vector_array
// iff vector->index == vector->size
// parameters: vector_array *
// returns: 0 if array stayed the same / grew, 1 if unable to grow array
int try_bigger_vector_array(vector_array *);

// set size of vector array to vector->index * 2 iff vector->index is 30% of vector->size
// normally this sets the array size to about 60%, but in some cirumstances it can be less
// parameters: vector_array *
// returns: 0 if array stayed the same / shrank, 1 if unable to shrink array
int try_smaller_vector_array(vector_array *);

// shift all cells after and including the index to the right
// the value in the parameters section is what the array is inflated around
// NOTE: vector->index is incremented at the end of this call
// parameters: vector_array *, unsigned int index, long value
// returns: nothing
void inflate_vector_array(vector_array *, unsigned int, long);

// shift all cells after the index to the left
// thus this function removes the value at the index
// NOTE: vector->index is decremented at the end of this call
// parameters: vector_array *, unsigned int index
// returns: nothing
void shrink_vector_array(vector_array *, unsigned int);

/* --- header functions --- */

vector_array * create_vector_array(void){

    vector_array * vector = malloc(sizeof(vector_array));
    if(vector == NULL) return NULL;
    
    vector->data = malloc(sizeof(long));
    vector->size = 1;
    vector->index = 0;

    if(vector->data == NULL){
        free(vector);
        return NULL;
    }

    return vector;
}

vector_array * create_sized_vector_array(unsigned int size){

    vector_array * vector = malloc(sizeof(vector_array));
    if(vector == NULL) return NULL;
    
    vector->data = malloc(sizeof(long) * size);
    vector->size = size;
    vector->index = 0;

    if(vector->data == NULL){
        free(vector);
        return NULL;
    }

    return vector;
}

int insert_in_vector_array(vector_array * vector, long value){

    vector->data[vector->index++] = value;

    return try_bigger_vector_array(vector);
}

int insert_at_vector_array(vector_array * vector, unsigned int index, long value){

    if(index > vector->index) return 1;

    inflate_vector_array(vector, index, value);

    return try_bigger_vector_array(vector);
}

int delete_in_vector_array(vector_array * vector, long value){

    for(unsigned int i = 0; i < vector->index; i++){
        if(vector->data[i] == value){
            shrink_vector_array(vector, i);
            return try_smaller_vector_array(vector);
        }
    }

    return 1;
}

int delete_all_in_vector_array(vector_array * vector, long value){

    // this works backwards since with multiple deletions the
    // performance should be better
    int flag = 1;
    for(unsigned int i = vector->index - 1; i != 0; i--){
        if(vector->data[i] == value){
            shrink_vector_array(vector, i);
            flag = 0;
        }
    }

    // index 0 needs to be checked manually
    if(vector->data[0] == value){
        shrink_vector_array(vector, 0);
        flag = 0;
    }

    return try_smaller_vector_array(vector) + flag;
}

int delete_at_vector_array(vector_array * vector, unsigned int index){

    if(index >= vector->index) return 1;

    shrink_vector_array(vector, index);

    return try_smaller_vector_array(vector);
}

void delete_vector_array(vector_array * vector){

    free(vector->data);
    free(vector);
}

int clear_vector_array(vector_array * vector){

    free(vector->data);

    vector->size = 1;
    vector->index = 0;

    vector->data = malloc(sizeof(long));

    if(vector->data == NULL) return 10;
    else return 0;
}

int replace_in_vector_array(vector_array * vector, long value_to_replace, long value){

    for(unsigned int i = 0; i < vector->index; i++){
        if(vector->data[i] == value_to_replace){
            vector->data[i] = value;
            return 0;
        }
    }

    return 1;
}

int replace_all_in_vector_array(vector_array * vector, long value_to_replace, long value){

    int flag = 1;
    for(unsigned int i = 0; i < vector->index; i++){
        if(vector->data[i] == value_to_replace){
            vector->data[i] = value;
            flag = 0;
        }
    }

    return flag;
}

int replace_at_vector_array(vector_array * vector, unsigned int index_to_replace, long value){

    if(index_to_replace >= vector->index) return 1;

    vector->data[index_to_replace] = value;

    return 0;
}

long find_in_vector_array(vector_array * vector, long value){

    for(unsigned int i = 0; i < vector->index; i++){
        if(vector->data[i] == value) return i;
    }

    return -1;
}

unsigned int count_amount_in_vector_array(vector_array * vector, long value){

    unsigned int count = 0;

    for(unsigned int i = 0; i < vector->index; i++){
        if(vector->data[i] == value) count++;
    }

    return count;
}

unsigned int size_of_vector_array(vector_array * vector){

    return vector->index;
}

/* --- utility functions --- */

int try_bigger_vector_array(vector_array * vector){

    // do not need a bigger vector array
    if(vector->index < vector->size) return 0;

    long * replacement_array = malloc(sizeof(long) * vector->size * 2);
    if(replacement_array == NULL) return 10;

    for(unsigned int i = 0; i < vector->size; i++) replacement_array[i] = vector->data[i];

    vector->size *= 2;

    free(vector->data);
    vector->data = replacement_array;

    return 0;
}

int try_smaller_vector_array(vector_array * vector){

    // do not need a smaller vector array
    if(vector->index > vector->size * .3) return 0;

    long * replacement_array = malloc(sizeof(long) * vector->index * 2);
    if(replacement_array == NULL) return 10;

    for(unsigned int i = 0; i < vector->index; i++) replacement_array[i] = vector->data[i];

    vector->size = vector->index * 2;

    free(vector->data);
    vector->data = replacement_array;

    return 0;
}

void inflate_vector_array(vector_array * vector, unsigned int index, long value){

    long temp1 = vector->data[index];
    long temp2;
    vector->data[index] = value;

    // there is only 1 value to shift
    if(index + 1 == vector->index){
        vector->data[index + 1] = temp1;
        vector->index++;
        return;
    }

    // this shifts two cells per iteration to save an operation
    unsigned int temp_index = index + 1;
    while(temp_index < vector->index){
        temp2 = vector->data[temp_index];
        vector->data[temp_index] = temp1;

        temp_index++;
        temp1 = vector->data[temp_index];
        vector->data[temp_index] = temp2;

        temp_index++;
    }

    // off by one, so copy temp1 to vector->data[vector->index]
    if(++temp_index == vector->index) vector->data[vector->index] = temp1;

    vector->index++;
}

void shrink_vector_array(vector_array * vector, unsigned int index){

    // the item to shrink past is at the end. so simply decrement the main index
    if(vector->index - 1 == index){
        vector->index--;
        return;
    }

    unsigned int temp_index = vector->index - 1;
    long temp1 = vector->data[temp_index];
    long temp2;

    // this shifts two cells per iteration to save an operation
    temp_index--;

    // because index is unsigned the while loop can wrap the temp_index to a max
    // value which results in an out of bounds access, this only happens when the
    // index == 0 though
    if(index == 0){
        while(temp_index > 1){
            temp2 = vector->data[temp_index];
            vector->data[temp_index] = temp1;

            temp_index--;
            temp1 = vector->data[temp_index];
            vector->data[temp_index] = temp2;

            temp_index--;
        }

        // two values left
        if(temp_index == 1){
            temp2 = vector->data[temp_index];
            vector->data[temp_index] = temp1;

            temp_index--;
            temp1 = vector->data[temp_index];
            vector->data[temp_index] = temp2;

            temp_index--;
        }
        // one value left
        else{
            vector->data[index] = temp1;
        }
    }
    else{
        while(temp_index > index){
            temp2 = vector->data[temp_index];
            vector->data[temp_index] = temp1;

            temp_index--;
            temp1 = vector->data[temp_index];
            vector->data[temp_index] = temp2;

            temp_index--;
        }

        // off by one, so copy temp1 to vector->data[index]
        if(temp_index == index) vector->data[index] = temp1;
    }

    vector->index--;
}
