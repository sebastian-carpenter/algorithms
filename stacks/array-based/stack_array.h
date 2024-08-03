#ifndef STACK_H
#define STACK_H

typedef struct stack_array{
    unsigned int size;
    unsigned int top;
    long * data;

    // this field is reserved for functions which lack the
    // ability to return an error themselves
    // 0 == no error
    // 1 == general error
    // 10 == memory error
    // 11 == general + memory error
    int error;
} stack_array;

// allocate a new array-based stack
// parameters: nothing
// returns: pointer to a new stack_array, NULL if allocation failed
stack_array * create_stack_array(void);

// allocate a new array-based stack of a particular size
// NOTE: performing a pop operation before 30% of this stacks' capacity is used
// will result in it shrinking prematurely, thus removing the advantage of this function
// parameters: unsigned int size
// returns: pointer to a new stack_array, NULL if allocation failed
stack_array * create_sized_stack_array(unsigned int);

// deallocate an array-based stack
// parameters: stack_array *
// returns: nothing
void delete_stack_array(stack_array *);

// resets the stacks' data array to an empty one
// parameters: stack_array *
// returns: 0 if successful, 10 if data array could not shrink properly
//          (memory allocation error) though the size and top index will
//          still be reset
int clear_stack_array(stack_array *);

// add a value to the top of the stack
// parameters: stack_array *, long value
// returns: 0 if successful, 10 if data array could not grow (memory
//          allocation error)
int push_stack_array(stack_array *, long);

// push a copy of the top item to the top of the stack
// parameters: stack_array *
// returns: 0 if successful, 1 if stack is empty,
//          10 if data array could not grow (memory allocation error)
int duplicate_top_stack_array(stack_array *);

// remove a value from the top of the stack and return it
// parameters: stack_array *
// returns: value at top of stack, 0 if stack is empty (sets error to 1),
//          value at top even if data array could not shrink (sets error to 10 (memory allocation error))
long pop_stack_array(stack_array *);

// return the value on top of the stack
// parameters: stack_array *
// returns: value at top of stack, 0 if stack is empty (sets error to 1)
long peek_stack_array(stack_array *);

// swap top two values of stack
// parameters: stack_array *
// returns: 0 if successful, 1 if stack size < two elements
int swap_stack_array(stack_array *);

// returns the number of elements in the stack
// parameters: stack_array *
// returns: unsigned int number of elements in the stack
unsigned int count_stack_array(stack_array *);

// returns value representing whether the stack is empty or not
// parameters: stack_array *
// returns: 0 if empty, 1 if not empty
int is_empty_stack_array(stack_array *);

// returns current error status and resets the field to 0
// parameters: stack_array *
// returns: current error status
int check_error_stack_array(stack_array *);

#endif
