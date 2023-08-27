#ifndef LIFO_H
#define LIFO_H

#include "main.h"

typedef struct node node;
typedef struct stack stack;

struct node{
    t_node* data;
    node*   next;
};

struct stack{
    node* top;
};


#endif