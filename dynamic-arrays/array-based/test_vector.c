#include <stdio.h>

#include "algorithms/dynamic-arrays/array-based/vector_array.h"

void print_vector(vector_array *);

int main(void){

    printf("--- create vectors\n");

    vector_array * vector1 = create_vector_array();
    vector_array * vector2 = create_sized_vector_array(100);

    printf("\nexpected: empty\n");
    print_vector(vector1);
    print_vector(vector2);

    printf("--- insert_in 1, 2, 4\n");

    printf("%d, ", insert_in_vector_array(vector1, 1));
    printf("%d, ", insert_in_vector_array(vector1, 2));
    printf("%d\n", insert_in_vector_array(vector1, 4));

    printf("%d, ", insert_in_vector_array(vector2, 1));
    printf("%d, ", insert_in_vector_array(vector2, 2));
    printf("%d\n", insert_in_vector_array(vector2, 4));

    printf("\nexpected: 1, 2, 4\n");
    print_vector(vector1); // 1, 2, 4
    print_vector(vector2); // 1, 2, 4

    printf("--- insert_at (4, 3)[incorrect], (2, 3), (4, 5)\n");

    printf("%d, ", insert_at_vector_array(vector1, 4, 3)); // out of bounds
    printf("%d, ", insert_at_vector_array(vector1, 2, 3)); // correct
    printf("%d\n", insert_at_vector_array(vector1, 4, 5)); // on edge, but correct

    printf("%d, ", insert_at_vector_array(vector2, 4, 3)); // out of bounds
    printf("%d, ", insert_at_vector_array(vector2, 2, 3)); // correct
    printf("%d\n", insert_at_vector_array(vector2, 4, 5)); // on edge, but correct

    printf("\nexpected: 1, 2, 3, 4, 5\n");
    print_vector(vector1); // 1, 2, 3, 4, 5
    print_vector(vector2); // 1, 2, 3, 4, 5

    printf("--- delete_in 6 [incorrect], 5, 1\n");

    printf("%d, ", delete_in_vector_array(vector1, 6)); // does not exist
    printf("%d, ", delete_in_vector_array(vector1, 5)); // correct, but on edge
    printf("%d\n", delete_in_vector_array(vector1, 1)); // correct, but on edge

    printf("%d, ", delete_in_vector_array(vector2, 6)); // does not exist
    printf("%d, ", delete_in_vector_array(vector2, 5)); // correct, but on edge
    printf("%d\n", delete_in_vector_array(vector2, 1)); // correct, but on edge

    printf("\nexpected: 2, 3, 4\n");
    print_vector(vector1); // 2, 3, 4
    print_vector(vector2); // 2, 3, 4

    insert_in_vector_array(vector1, 2);
    insert_in_vector_array(vector2, 2);

    printf("\nexpected: 2, 3, 4, 2\n");
    print_vector(vector1); // 2, 3, 4, 2
    print_vector(vector2); // 2, 3, 4, 2

    printf("--- delete_all 2, 5[incorrect]\n");

    printf("%d, ", delete_all_vector_array(vector1, 2)); // correct
    printf("%d\n", delete_all_vector_array(vector1, 5)); // incorrect

    printf("%d, ", delete_all_vector_array(vector2, 2)); // correct
    printf("%d\n", delete_all_vector_array(vector2, 5)); // incorrect

    printf("\nexpected: 3, 4\n");
    print_vector(vector1); // 3, 4
    print_vector(vector2); // 3, 4

    insert_in_vector_array(vector1, 1);
    insert_in_vector_array(vector1, 2);
    insert_in_vector_array(vector1, 4);

    insert_in_vector_array(vector2, 1);
    insert_in_vector_array(vector2, 2);
    insert_in_vector_array(vector2, 4);

    printf("\nexpected: 3, 4, 1, 2, 4\n");
    print_vector(vector1); // 3, 4, 1, 2, 4
    print_vector(vector2); // 3, 4, 1, 2, 4

    printf("--- delete_at 1, 5[incorrect]\n");

    printf("%d, ", delete_at_vector_array(vector1, 1)); // correct
    printf("%d\n", delete_at_vector_array(vector1, 5)); // incorrect

    printf("%d, ", delete_at_vector_array(vector2, 1)); // correct
    printf("%d\n", delete_at_vector_array(vector2, 5)); // incorrect

    printf("\nexpected: 3, 1, 2, 4\n");
    print_vector(vector1); // 3, 1, 2, 4
    print_vector(vector2); // 3, 1, 2, 4

    printf("--- replace_in (3, 0), (5, 0)[incorrect]\n");

    printf("%d, ", replace_in_vector_array(vector1, 3, 0)); // correct
    printf("%d\n", replace_in_vector_array(vector1, 5, 0)); // incorrect

    printf("%d, ", replace_in_vector_array(vector2, 3, 0)); // correct
    printf("%d\n", replace_in_vector_array(vector2, 5, 0)); // incorrect

    printf("\nexpected: 0, 1, 2, 4\n");
    print_vector(vector1); // 0, 1, 2, 4
    print_vector(vector2); // 0, 1, 2, 4

    insert_in_vector_array(vector1, 1);
    insert_in_vector_array(vector2, 1);

    printf("\nexpected: 0, 1, 2, 4, 1\n");
    print_vector(vector1); // 0, 1, 2, 4, 1
    print_vector(vector2); // 0, 1, 2, 4, 1

    printf("--- replace_all (1, 5), (3, 5)[incorrect]\n");

    printf("%d, ", replace_all_in_vector_array(vector1, 1, 5)); // correct
    printf("%d\n", replace_all_in_vector_array(vector1, 3, 5)); // incorrect

    printf("%d, ", replace_all_in_vector_array(vector2, 1, 5)); // correct
    printf("%d\n", replace_all_in_vector_array(vector2, 3, 5)); // incorrect

    printf("\nexpected: 0, 5, 2, 4, 5\n");
    print_vector(vector1); // 0, 5, 2, 4, 5
    print_vector(vector2); // 0, 5, 2, 4, 5

    printf("--- replace_at (1, 1), (5, 5)[incorrect]\n");

    printf("%d, ", replace_at_vector_array(vector1, 1, 1)); // correct
    printf("%d\n", replace_at_vector_array(vector1, 5, 5)); // incorrect

    printf("%d, ", replace_at_vector_array(vector2, 1, 1)); // correct
    printf("%d\n", replace_at_vector_array(vector2, 5, 5)); // incorrect

    printf("\nexpected: 0, 1, 2, 4, 5\n");
    print_vector(vector1); // 0, 1, 2, 4, 5
    print_vector(vector2); // 0, 1, 2, 4, 5

    printf("--- find_in 5, 6[incorrect]\n");

    printf("%li, ", find_in_vector_array(vector1, 5)); // correct
    printf("%li\n", find_in_vector_array(vector1, 6)); // incorrect

    printf("%li, ", find_in_vector_array(vector2, 5)); // correct
    printf("%li\n", find_in_vector_array(vector2, 6)); // incorrect

    printf("\nexpected: 0, 1, 2, 4, 5\n");
    print_vector(vector1); // 0, 1, 2, 4, 5
    print_vector(vector2); // 0, 1, 2, 4, 5
    
    insert_in_vector_array(vector1, 0);
    insert_in_vector_array(vector2, 0);

    printf("--- count_amount 0, 6[incorrect]\n");

    printf("%d, ", count_amount_in_vector_array(vector1, 0)); // correct
    printf("%d\n", count_amount_in_vector_array(vector1, 6)); // incorrect

    printf("%d, ", count_amount_in_vector_array(vector2, 0)); // correct
    printf("%d\n", count_amount_in_vector_array(vector2, 6)); // incorrect

    printf("\nexpected: 0, 1, 2, 4, 5, 0\n");
    print_vector(vector1); // 0, 1, 2, 4, 5, 0
    print_vector(vector2); // 0, 1, 2, 4, 5, 0

    printf("--- size_of\n");

    printf("%d\n", size_of_vector_array(vector1));
    printf("%d\n", size_of_vector_array(vector2));

    printf("--- clear_vector\n");

    printf("%d\n", clear_vector_array(vector1));
    printf("%d\n", clear_vector_array(vector2));

    printf("\nexpected: empty\n");
    print_vector(vector1); // empty
    print_vector(vector2); // empty

    printf("making sure size cant be set to 0\n");
    printf("insert in 1, insert in 1, delete all 1\n");

    insert_in_vector_array(vector1, 1);
    insert_in_vector_array(vector1, 1);
    delete_all_vector_array(vector1, 1);

    insert_in_vector_array(vector2, 1);
    insert_in_vector_array(vector2, 1);
    delete_all_vector_array(vector2, 1);

    printf("\nexpected: size is 1\n");
    print_vector(vector1); // empty
    print_vector(vector2); // empty

    delete_vector_array(vector1);
    delete_vector_array(vector2);

    return 0;
}

void print_vector(vector_array * vector){

    printf("size: %u\tindex: %u\n", vector->size, vector->index);

    if(size_of_vector_array(vector) >= 2){
        for(unsigned int i = 0; i <= vector->index - 2; i++)
            printf("%li, ", vector->data[i]);
        printf("%li\n\n", vector->data[vector->index - 1]);
    }
    else if(size_of_vector_array(vector) == 1){
        printf("%li\n\n", vector->data[0]);
    }
    else if(size_of_vector_array(vector) == 0){
        printf("no items\n\n");
    }
}
