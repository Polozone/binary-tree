#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "lifo.h"
#include "lifo.c"

t_node* getNewNode(int value){
    t_node* newNode = malloc(sizeof(t_node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printPath(t_node **head, char* path)
{
    t_node *tmp;
    int i = 0;

    tmp = *head;
    while (tmp != NULL && path[i])
    {
        if (path[i] == 'L'){
            tmp = tmp->left;
        }
        else if (path[i] == 'R'){

            tmp = tmp->right;
        }
        i++;
    }
}

void addNode(t_node **head, t_node* toAdd){
    t_node  *tmp;
    int     check = 0;
    int     i = 0;

    tmp = *head;
    while (check == 0){
        if (toAdd->value < tmp->value)
        {
            if (tmp->left == NULL){
                tmp->left = toAdd;
                check = 1;
            }
            else{
                tmp = tmp->left;
            }
        } else {
            if (tmp->right == NULL){
                tmp->right = toAdd;
                check = 1;
            } else {
                tmp = tmp->right;
            }
        }
        i++;
    }
}

int    readTree(t_node **actual, stack *stack, int size)
{
    t_node *tmp = *actual;
    printf("%d\n", tmp->value);

    if (tmp->left && tmp->right)
        push(stack, tmp);

    if (tmp->left)
        readTree(&tmp->left, stack, size + 1);
    else if (tmp->right){
        readTree(&tmp->right, stack, size + 1);
    }
    else {
        t_node *toSend = pop(stack);
        if (toSend != NULL)
            readTree(&toSend->right, stack, size + 1);
        else{
            printf("fin lecture...\n");
            return size;
        }
    }
}

t_node*     findValue(t_node **root, int value){
    size_t i = 0;
    t_node *tmp = *root;
    if (tmp == NULL){
        return NULL;
    }

    while (tmp != NULL)
    {
        if (tmp->value == value){
            printf("found on %ld try\n", i);
            return tmp;
        }
        else if (tmp->value < value)
            tmp = tmp->right;
        else
            tmp = tmp->left;
        i++;
    }
    return NULL;
}

int     checkTreeBalance(t_node **root)
{
    t_node *tmp_root = *root;
    stack *stack = createStack();

    int     leftSize = readTree(&tmp_root->left, stack, 0);
    int     rightSize = readTree(&tmp_root->right, stack, 0);

    return (leftSize - rightSize);
}

int main(void){
    t_node *racine = getNewNode(20);
    t_node *toAdd0 = getNewNode(30);
    t_node *toAdd = getNewNode(10);
    t_node *toAdd2 = getNewNode(5);
    t_node *toAdd3 = getNewNode(1);
    t_node *toAdd4 = getNewNode(3);
    t_node *toAdd5 = getNewNode(15);
    t_node *toAdd6 = getNewNode(14);
    // t_node *toAdd7 = getNewNode(160);
    // t_node *toAdd8 = getNewNode(1600);
    // t_node *toAdd9 = getNewNode(-106);
    // t_node *toAdd10 = getNewNode(10006);
    // t_node *toAdd11 = getNewNode(16065);
    addNode(&racine, toAdd);
    addNode(&racine, toAdd0);
    addNode(&racine, toAdd2);
    addNode(&racine, toAdd3);
    addNode(&racine, toAdd4);
    addNode(&racine, toAdd5);
    addNode(&racine, toAdd6);
    // addNode(&racine, toAdd7);
    // addNode(&racine, toAdd8);
    // addNode(&racine, toAdd9);
    // addNode(&racine, toAdd10);
    // addNode(&racine, toAdd11);

    stack *stack = createStack();

    t_node *tmp = findValue(&racine, 5);

    // int size = readTree(&racine, stack, 0);
    int treeBalance = checkTreeBalance(&racine);
    printf("treeBalance = %d\n", treeBalance);

    return 0;
}
