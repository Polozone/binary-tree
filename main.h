#ifndef MAIN_H
#define MAIN_H

typedef struct t_node t_node;

struct t_node{
    int value;
    t_node* left;
    t_node* right;
};

#endif