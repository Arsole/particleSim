#ifndef _LIST_H
#define _LIST_H
#include <particle.h>
struct node
{
    struct node * next;
    particle * type;
};
typedef struct node node;
struct list
{
    node * head;
};
typedef struct list list;
#endif // _LIST_H
