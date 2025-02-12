#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

int main(int argc, char *argv[])
{
int value;
linklink H;
H=list_create();
printf("please input:\n");
while(1){
scanf("%d",&value);
if(value==-1)
{
break;
}
list_bottominsert(H, value);
printf("please input:\n");
}
list_showall(H);
list_insert(H,2,5);
list_showall(H);
list_order(H);
list_showall(H);
return 0;
}
