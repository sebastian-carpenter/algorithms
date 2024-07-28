#ifndef RED-BLACK-TREE_H
#define RED-BLACK-TREE_H

#include <stdio.h>
#include <stdlib.h>

enum color_t {BLACK, RED};

typedef struct node{
    enum color_t color;
    long data;
    struct node * left;
    struct node * right;
} node;

// create a root node and return a pointer to it
// parameters: long data
// returns: node * to root node (node is null on failure)
node * create_root(long);

// insert a node at the appropriate spot
// this may require shifting nearby nodes to maintain
// a balanced tree
// parameters: node * to root node, long data
// returns: 0 on failure, 1 on success
int insert_node(node *, long);

// delete a node based on its stored data
// parameters: node * to root node, long data
// returns: 0 on failure, 1 on success
int delete_node(node *, long);

// delete the entire tree
// parameters: node * to root node
// returns: 0 on failure, 1 on success
int delete_tree(node *);

// search for a specified value
// parameters: node * to root node, long data
// returns: 0 on failure, 1 on success
int search_tree(node *, long);

#endif
