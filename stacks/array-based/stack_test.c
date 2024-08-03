#include <stdio.h>

#include "algorithms/stacks/array-based/stack_array.h"

void print_stack(stack_array *);

int main(void){

    printf("--- create stacks\n");

    stack_array * stack1 = create_stack_array();
    stack_array * stack2 = create_sized_stack_array(100);

    if(stack1 == NULL || stack2 == NULL){
        printf("1 or more stacks have a NULL pointer\n");
        return 1;
    }

    printf("test is_empty (0)\n");

    printf("%d\n", is_empty_stack_array(stack1));
    printf("%d\n", is_empty_stack_array(stack2));

    printf("test count (0)\n");

    printf("%u\n", count_stack_array(stack1));
    printf("%u\n", count_stack_array(stack2));

    printf("error should be 0\n");

    printf("%d\n", check_error_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack2));

    printf("test peek (0) [error == 1]\n");

    printf("%li, ", peek_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", peek_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("error should now be reset to 0\n");

    printf("%d\n", check_error_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack2));

    printf("test pop (0) [error == 1]\n");

    printf("%li, ", pop_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", pop_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("test swap (1)\n");

    printf("%d\n", swap_stack_array(stack1));
    printf("%d\n", swap_stack_array(stack2));

    printf("test duplicate (1)\n");

    printf("%d\n", duplicate_top_stack_array(stack1));
    printf("%d\n", duplicate_top_stack_array(stack2));

    printf("--- test push (0)\n");

    printf("%d\n", push_stack_array(stack1, 1));
    printf("%d\n", push_stack_array(stack2, 1));

    printf("test is_empty (1)\n");

    printf("%d\n", is_empty_stack_array(stack1));
    printf("%d\n", is_empty_stack_array(stack2));

    printf("test count (1)\n");

    printf("%u\n", count_stack_array(stack1));
    printf("%u\n", count_stack_array(stack2));

    printf("test peek (1) [error == 0]\n");

    printf("%li, ", peek_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", peek_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("test pop (1) [error == 0]\n");

    printf("%li, ", pop_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", pop_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("push 1\n");

    push_stack_array(stack1, 1);
    push_stack_array(stack2, 1);

    printf("test swap (1)\n");

    printf("%d\n", swap_stack_array(stack1));
    printf("%d\n", swap_stack_array(stack2));

    printf("--- test duplicate (0)\n");

    printf("%d\n", duplicate_top_stack_array(stack1));
    printf("%d\n", duplicate_top_stack_array(stack2));

    printf("test swap (0)\n");

    printf("%d\n", swap_stack_array(stack1));
    printf("%d\n", swap_stack_array(stack2));

    printf("test is_empty (1)\n");

    printf("%d\n", is_empty_stack_array(stack1));
    printf("%d\n", is_empty_stack_array(stack2));

    printf("test count (2)\n");

    printf("%u\n", count_stack_array(stack1));
    printf("%u\n", count_stack_array(stack2));

    printf("test peek (1) [error == 0]\n");

    printf("%li, ", peek_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", peek_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("test pop (1) [error == 0]\n");

    printf("%li, ", pop_stack_array(stack1));
    printf("%d\n", check_error_stack_array(stack1));

    printf("%li, ", pop_stack_array(stack2));
    printf("%d\n", check_error_stack_array(stack2));

    printf("clear stack\n");

    clear_stack_array(stack1);
    clear_stack_array(stack2);

    printf("test is_empty (0)\n");

    printf("%d\n", is_empty_stack_array(stack1));
    printf("%d\n", is_empty_stack_array(stack2));

    push_stack_array(stack1, 1);
    push_stack_array(stack1, 2);

    push_stack_array(stack2, 1);
    push_stack_array(stack2, 2);

    printf("peek (2)\n");

    printf("%li\n", peek_stack_array(stack1));
    printf("%li\n", peek_stack_array(stack2));

    printf("swap (0)\n");

    printf("%d\n", swap_stack_array(stack1));
    printf("%d\n", swap_stack_array(stack2));

    printf("peek (1)\n");

    printf("%li\n", peek_stack_array(stack1));
    printf("%li\n", peek_stack_array(stack2));

    delete_stack_array(stack1);
    delete_stack_array(stack2);

    return 0;
}

void print_stack(stack_array * stack){

    printf("size: %u\ttop: %u\n", stack->size, stack->top);

    if(count_stack_array(stack) >= 2){
        for(unsigned int i = 0; i <= stack->top - 2; i++)
            printf("%li, ", stack->data[i]);
        printf("%li\n", stack->data[stack->top - 1]);
    }
    else if(count_stack_array(stack) == 1){
        printf("%li\n", stack->data[0]);
    }
    else if(count_stack_array(stack) == 0){
        printf("no items\n");
    }
}
