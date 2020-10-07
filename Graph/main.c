#include <stdio.h>
#include <string.h>

struct node{
    char val[100];
    char path[10][100];
    int lim;
};

struct node nodes[100];
int N;

int findOrCreate(char *val){
    for(int i=0; i<N; i++){
        if(strcmp(nodes[i].val, val)==0){
            return i;
        }
    }
    strcpy(nodes[N].val, val);
    N++;
    return (N-1);
}

int findPath(int n1, int n2){
    for(int j=0; j<nodes[n1].lim; j++){
        /*if(strcmp(nodes[n1].path[j], nodes[n2].val)==0){
            printf("Path already exists: %s -- %s\n", nodes[n1].val, nodes[n2].val);
            return 1;
        }*/
    }
    return 0;
}

void addPath(int n1, int n2){
    //if(nodes[n1].lim!=0){

        strcpy(nodes[n1].path[nodes[n1].lim], nodes[n2].val);
        nodes[n1].lim++;
    //}
}

void dump(){
    /*printf("graph{\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<nodes[i].lim; j++){
                printf("%s -- %s;\n", nodes[i].val, nodes[i].path[j]);
        }
    }
    printf("}\n");*/

    FILE *ptrFile = fopen("file.dot", "w+");
    fputs("graph{\n", ptrFile);
    for(int i=0; i<N; i++){
        for(int j=0; j<nodes[i].lim; j++){
                if(nodes[i].lim==1){
                    fputs(nodes[i].val, ptrFile);
                    fputs(";\n", ptrFile);
                }
                else{
                    fputs(nodes[i].val, ptrFile);
                    fputs(" -- ", ptrFile);
                    fputs(nodes[i].path[j], ptrFile);
                    fputs(";\n", ptrFile);
                }
        }
    }
    fputs("}\n", ptrFile);
}

void check(){
    int count, err=0;
    for(int i=0; i<N; i++){
        count+=nodes[i].lim;
        if(nodes[i].lim==1) err=1;
    }
    if(count>((N-1)*(N-2)/2) && err==0){
        printf("Svyazanniy\n");
    }
    else{
        printf("Ne svyazanniy\n");
    }
}

int main(int argc, char *argv[]){
    char *a, *b, tmp[256];
    for (int i=0; i<100; i++){
        nodes[i].lim=0;
    }
    printf("Paths: \n");

    while(1){
        scanf("%s", tmp);
        if(tmp[0]=='!')
            break;
        a = strtok(tmp, "-");
        b = strtok(NULL, "-");
        int n1=findOrCreate(a);
        int n2=findOrCreate(b);

        if(!findPath(n1, n2) && !findPath(n2, n1)){
            addPath(n1, n2);
        }
    }
    check();
    dump();
    //system("cd C:\DZ_2");
    //system("dot -Tpng C:\DZ_2\file.dot -o demo_dot.png");

    return 0;
}
