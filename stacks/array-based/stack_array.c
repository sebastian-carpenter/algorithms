#include <stdlib.h>

#include "algorithms/stacks/array-based/stack_array.h"

/* --- utility function prototypes --- */

// double the size of the data array in the provided stack_array
// iff stack->top == stack->size
// parameters: stack_array *
// returns: 0 if array stayed the same / grew, 10 if unable to grow array
int try_bigger_stack_array(stack_array *);

// set size of stack array to stack->top * 2 iff stack->top is 30% of stack->size
// this sets the array size to about 60%
// parameters: stack_array *
// returns: 0 if array stayed the same / shrank, 10 if unable to shrink array
int try_smaller_stack_array(stack_array *);

/* --- header functions --- */

stack_array * create_stack_array(void){

    stack_array * stack = malloc(sizeof(stack_array));
    if(stack == NULL) return NULL;

    stack->data = malloc(sizeof(long));
    if(stack->data == NULL){
        free(stack);
        return NULL;
    }

    stack->size = 1;
    stack->top = 0;
    stack->error = 0;

    return stack;
}

stack_array * create_sized_stack_array(unsigned int size){

    stack_array * stack = malloc(sizeof(stack_array));
    if(stack == NULL) return NULL;

    stack->data = malloc(sizeof(long) * size);
    if(stack->data == NULL){
        free(stack);
        return NULL;
    }

    stack->size = size;
    stack->top = 0;
    stack->error = 0;

    return stack;
}

void delete_stack_array(stack_array * stack){

    free(stack->data);
    free(stack);
}

int clear_stack_array(stack_array * stack){

    stack->size = 1;
    stack->top = 0;

    long * replacement_array = malloc(sizeof(long));

    if(replacement_array == NULL) return 10;

    free(stack->data);
    stack->data = replacement_array;

    return 0;
}

int push_stack_array(stack_array * stack, long value){

    stack->data[stack->top++] = value;

    return try_bigger_stack_array(stack);
}

int duplicate_top_stack_array(stack_array * stack){

    // stack is empty, exception would occur
    if(stack->top == 0) return 1;

    return push_stack_array(stack, stack->data[stack->top - 1]);
}

long pop_stack_array(stack_array * stack){

    // nothing to pop, underflow would occur
    if(stack->top == 0){
        stack->error = 1;
        return 0;
    }

    long returnable = stack->data[--(stack->top)];
    
    // could not shrink array, memory allocation error
    if(try_smaller_stack_array(stack) > 0){
        stack->error = 10;
        return returnable;
    }
    // array was able to shrink
    else{
        return returnable;
    }
}

long peek_stack_array(stack_array * stack){

    // nothing to peek, exception would occur
    if(stack->top == 0){
        stack->error = 1;
        return 0;
    }

    return stack->data[stack->top - 1];
}

int swap_stack_array(stack_array * stack){

    // not enough elements to perform swap
    if(stack->top < 2) return 1;

    long temp_value = stack->data[stack->top - 1];
    stack->data[stack->top - 1] = stack->data[stack->top - 2];
    stack->data[stack->top - 2] = temp_value;

    return 0;
}

unsigned int count_stack_array(stack_array * stack){

    return stack->top;
}

int is_empty_stack_array(stack_array * stack){

    if(stack->top == 0) return 0;
    else return 1;
}

int check_error_stack_array(stack_array * stack){

    int error_value = stack->error;
    
    stack->error = 0;

    return error_value;
}

/* --- utility functions --- */

int try_bigger_stack_array(stack_array * stack){

    // do not need a bigger stack array
    if(stack->top < stack->size) return 0;

    long * replacement_array = malloc(sizeof(long) * stack->size * 2);
    if(replacement_array == NULL) return 10;

    for(unsigned int i = 0; i < stack->size; i++) replacement_array[i] = stack->data[i];

    stack->size *= 2;

    free(stack->data);
    stack->data = replacement_array;

    return 0;
}

int try_smaller_stack_array(stack_array * stack){

    // do not need a smaller stack array
    // NOTE: >= is to prevent redundant creation of size 1 arrays
    if(stack->top >= stack->size * .3) return 0;

    // don't want a size 0 array
    if(stack->top == 0){
        long * replacement_array = malloc(sizeof(long));
        if(replacement_array == NULL) return 10;

        stack->size = 1;

        free(stack->data);
        stack->data = replacement_array;

        return 0;
    }
    // general array creation method
    else{
        long * replacement_array = malloc(sizeof(long) * stack->top * 2);
        if(replacement_array == NULL) return 10;

        for(unsigned int i = 0; i < stack->top; i++) replacement_array[i] = stack->data[i];

        stack->size = stack->top * 2;

        free(stack->data);
        stack->data = replacement_array;

        return 0;
    }
}
