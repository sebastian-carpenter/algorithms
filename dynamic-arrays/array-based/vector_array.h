/* dynamic array following a fairly standard implementation
 * growth size is 2
 * based on an array rather than a linked list
 */

#ifndef VECTOR_ARRAY_H
#define VECTOR_ARRAY_H

typedef struct vector_array{
    long * data;
    unsigned int size;
    unsigned int index; // this refers to the next index to fill
} vector_array;

// returns a pointer to a new vector array
// parameters: none
// returns: vector_array *, NULL if not successful
vector_array * create_vector_array(void);

// returns a pointer to a new vector array of specified size
// NOTE: performing a delete operation before 30% of this vectors capacity is used
// will result in it shrinking prematurely, thus removing the advantage of this function
// parameters: unsigned int for size of starting array
// returns: vector_array *, NULL if not successful
vector_array * create_sized_vector_array(unsigned int);

// inserts value at end of vector array
// parameters: vector_array *, long value to add
// returns: 0 if successful, 10 could not grow data array
int insert_in_vector_array(vector_array *, long);

// inserts value at specified index in vector array
// parameters: vector_array *, unsigned int index to add at, long value to add
// returns: 0 if successful, 1 if outside bounds, 10 could not grow data array
int insert_at_vector_array(vector_array *, unsigned int, long);

// deletes first occurrence of value in vector array
// parameters: vector_array *, long value to remove
// returns: 0 if successful, 1 if item did not exist, 10 could not shrink data array
int delete_in_vector_array(vector_array *, long);

// deletes all occurrences of value in vector array
// parameters: vector_array *, long value to remove
// returns: 0 if successful, 1 if item did not exist, 10 could not shrink data array,
//          11 if both issues exist
int delete_all_vector_array(vector_array *, long);

// deletes value at specified index in vector array
// parameters: vector_array *, unsigned int index to delete at
// returns: 0 if successful, 1 if outside bounds, 10 could not shrink data array
int delete_at_vector_array(vector_array *, unsigned int);

// deallocates memory for array, thus deleting it indirectly
// parameters: vector_array *
// returns: none
void delete_vector_array(vector_array *);

// reallocates new memory for an empty data array, thus clearing the stored data
// parameters: vector_array *
// returns: 0 if successful, 10 could not allocate new data array
int clear_vector_array(vector_array *);

// replace the first matching value of the first parameter with
// the value in the second parameter
// parameters: vector_array *, long to be replaced, long to replace with
// returns: 0 if successful, 1 if item does not exist / not successful
int replace_in_vector_array(vector_array *, long, long);

// replace every value matching the first parameter with the value of
// the second parameter
// parameters: vector_array *, long to be replaced, long to replace with
// returns: 0 if successful, 1 if item does not exist / not successful
int replace_all_in_vector_array(vector_array *, long, long);

// replace value at specified index with the value of the second parameter
// parameters: vector_array *, index to be update, long to update with
// returns: 0 if successful, 1 if item is out of bounds / not successful
int replace_at_vector_array(vector_array *, unsigned int, long);

// search for a specified value in the vector array starting from index 0
// NOTE: return type is long so that a negative value can be returned or
// any number encased within unsigned int
// parameters: vector_array *, long value to search for
// returns: index of value if it exists, -1 if it does not exist
long find_in_vector_array(vector_array *, long);

// count number of occurences of value in vector array
// parameters: vector_array *, long value to compare with
// returns: number of found values
unsigned int count_amount_in_vector_array(vector_array *, long);

// return number of values stored in vector array
// parameters: vector_array *
// returns: number of values
unsigned int size_of_vector_array(vector_array *);

#endif
