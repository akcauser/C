#include <stdio.h>
#include <string.h>

#define INT 1
#define FLOAT 2
#define STRING 3
#define SIZE 3

struct stackelement
{
    int etype;
    union {
        int ival;
        float fval;
        char str[20];
    }element;
};

struct stackelement se,tmp;
struct stackelement items[SIZE];


int main()
{
    items[0].etype=FLOAT;
    items[0].element.fval=1.4;
    
    items[1].etype=INT;
    items[1].element.ival=5;
    
    items[2].etype=STRING;
    strcpy(items[2].element.str, "C Programming");

    int i;
    for(i=0;i<SIZE;i++) {
        tmp=items[i];
        switch(tmp.etype){
            case INT : printf("%d\n",tmp.element.ival); break;
            case FLOAT : printf("%f\n",tmp.element.fval); break;
            case STRING : printf("%s\n",tmp.element.str); break;
        }
    }
    
    return 0;
}


