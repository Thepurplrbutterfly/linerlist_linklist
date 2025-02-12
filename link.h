#include <stdio.h>
typedef int data_t;
typedef struct node{
data_t data;
struct node *next;
} linklist, *linklink;

linklink list_create();
int list_bottominsert(linklink H, data_t value);
int list_showall(linklink H);
linklink list_locate(linklink H, int pos);
int list_insert(linklink H, data_t value, int pos);
int list_delete(linklink H, int pos);
int list_freelist(linklink H);
int list_inverse(linklink H);
linklink list_summost(linklink H);
int list_mergeorder(linklink H1, linklink H2);
int list_order(linklink H);
