#include "lifo.h"

stack*    createStack()
{
    stack* stack = malloc(sizeof(stack));
    stack->top = NULL;
    return stack;
}

void    push(stack* stack, t_node *data)
{
    node *toAdd = malloc(sizeof(node));
    toAdd->data = data;
    toAdd->next = stack->top;
    stack->top = toAdd;
}

t_node*    pop(stack *stack)
{
    if (stack->top == NULL){
        return (NULL);
    }
    t_node *data = stack->top->data;
    node *tmp = stack->top;
    stack->top = stack->top->next;
    // free(tmp);
    return (data);
}