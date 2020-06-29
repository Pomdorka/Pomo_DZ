#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size;
    //printf("%s", argv[1]);
    FILE *input = fopen(argv[1], "r");
    //printf("Start");
    if(input==NULL){
        printf("Error");
    }
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    rewind(input);
    char stack[size];
    char temp;
    int i=0, t=0;
    //printf("Begin");
    //FILE *input = (argv[1], 'r');

    while(!feof(input)){
        temp = fgetc(input);
        //printf("Read %c\n", temp);
        switch(temp){
            case '"' :
                t=1-t;
                break;
            case '(' :
            case '[' :
            case '{' :
                if(t==0){
                    stack[i]=temp;
                    i++;
                }
                break;
            case ')':
                if(t==0){
                    if(stack[i-1]=='('){
                        i--;
                    } else{
                        printf("unbalanced )");
                        return 1;
                    }
                }
                break;
            case ']':
                if(t==0){
                    if(stack[i-1]=='['){
                        i--;
                    } else{
                        printf("unbalanced ]");
                        return 1;
                    }
                }
                break;
            case '}':
                if(t==0){
                    if(stack[i-1]=='{'){
                        i--;
                    } else{
                        printf("unbalanced }");
                        return 1;
                    }
                }
                break;
            }
    }
    if(i>0){
        printf("Unbalanced %c", stack[i]);
    } else{
        printf("No mistakes");
    }

    //printf("Hello world!\n");
    return 0;
}
