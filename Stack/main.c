#include <stdio.h>
#include <stdlib.h>

struct my_stack{
    int num1[100];
    int size;
};

int push(int a, struct my_stack * st){
    if(st->size==100){
        return 1;
    } else{
        st->num1[st->size++]=a;
        return 0;
    }
}

int pop(struct my_stack * st, int * b){
    if(st->size==0){
        return 1;
    } else{
        *b = st->num1[st->size-- -1];
        return 0;
    }
}

void print(struct my_stack * st){
    for(int i=0; i<st->size; i++){
        printf("\t%d\n", st->num1[st->size-i-1]);
    }
}

int main(int argc, char * argv[]){
    struct my_stack stack_1;
    int value, number;
    char oper;
    stack_1.size=0;
    printf("'+[num]' to push element\n'-' to pop element\n'=' to print stack\n'x' to exit\n");
        while(1){
            printf(":");
            scanf(" %c", &oper);
            switch(oper){
                case '+':
                    scanf("%d", &number);
                    if(push(number, &stack_1)){
                        printf("\tOverflow\n");
                    };
                    break;
                case '-':
                    if(pop(&stack_1, &value)){
                        printf("\tUnderflow\n");
                    } else{
                        printf("\t%d\n", value);
                    }
                    break;
                case '=':
                    print(&stack_1);
                    break;
                case 'x':
                    printf("\tExit");
                    return 0;
                default :
                    printf("\tIncorrect operation");
                    break;
            }
        }
    return 0;
}
