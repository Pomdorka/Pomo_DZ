#include <stdio.h>
#include <stdlib.h>

struct STACK{
    int num1[100];
    int size;
};

int push(int a, struct STACK * st){
    if(st->size==100){
        return 1;
    } else{
        st->num1[st->size++]=a;
        return 0;
    }
}
int pop(struct STACK * st, int * b){
    if(st->size==0){
        return 1;
    } else{
        *b = st->num1[st->size-- -1];
        return 0;
    }
}

void print(struct STACK * st){
    int i=0;
    while (st->size-i!=0){
        i++;
        printf("\t%d\n", st->num1[st->size-i]);
    }
}

int main(int argc, char *argv[]){
    struct STACK stack_1;
    int value, number;
    char oper;
    stack_1.size=0;
    printf("'+[num]' to push element\n'-' to pop element\n'=' to print stack\n'x' to exit\n");
        while(1){
            printf(":");
            scanf(" %c", &oper);
            switch(oper){
                case '+':
                    //printf("enter number: ");
                    scanf("%d", &number);
                    if(push(number, &stack_1)){
                        printf("\toverflow\n");
                    };
                    break;
                case '-':

                    if(pop(&stack_1, &value)){
                        printf("\tunderflow\n");
                    } else{
                        printf("\t%d\n", value);
                    }

                    break;
                case '=':
                    print(&stack_1);
                    break;
                case 'x':
                    printf("\tEnd of input");
                    return 0;
                default :
                    printf("\tincorrect operation");
                    break;
            }
        }


    return 0;
}
