#include <stdio.h>
#include <string.h>
#include <limits.h>

struct node{
    char val[100];
    char path[10][100];
    char hidden_path[10][100];
    int lim;
    int hidden_lim;
};

struct node nodes[100];
int N;

void swap(char *a1, char *a2){
    //printf("swap");
    char *temp;
    temp=*a1;
    *a1=*a2;
    *a2=temp;
}


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
        if(strcmp(nodes[n1].path[j], nodes[n2].val)==0){
            printf("Path already exists: %s -- %s\n", nodes[n1].val, nodes[n2].val);
            return 1;
        }
    }
    return 0;
}

void addPath(int n1, int n2){
    //if(nodes[n1].lim!=0){

        strcpy(nodes[n1].path[nodes[n1].lim], nodes[n2].val);
        strcpy(nodes[n2].hidden_path[nodes[n2].hidden_lim], nodes[n1].val);
        nodes[n1].lim++;
        nodes[n2].hidden_lim++;
    //}
}

void dump(){
    printf("graph{\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<nodes[i].lim; j++){
                printf("%s -- %s;\n", nodes[i].val, nodes[i].path[j]);
        }
    }
    printf("}\n");

    /*FILE *ptrFile = fopen("file.dot", "w+");
    fputs("graph{\n", ptrFile);
    for(int i=0; i<N; i++){
        for(int j=0; j<nodes[i].lim; j++){
                //if(nodes[i].lim==1){
                //    fputs(nodes[i].val, ptrFile);
                //    fputs(";\n", ptrFile);
                //}
                //else{
                    fputs(nodes[i].val, ptrFile);
                    fputs(" -- ", ptrFile);
                    fputs(nodes[i].path[j], ptrFile);
                    fputs(";\n", ptrFile);
                //}
        }
    }
    fputs("}\n", ptrFile);*/
}

void check_svyaz(){
    int count;
    for(int i=0; i<N; i++){
        count+=nodes[i].lim;
    }
    if(count>((N-1)*(N-2)/2)){
        printf("Svyazanniy\n");
    }
    else{
        printf("Ne svyazanniy\n");
    }
}

void check_stepen(){
    int min_lim=INT_MAX, min_index[100], j=0;
    for(int i=0; i<N; i++){
        if(nodes[i].lim+nodes[i].hidden_lim<min_lim){
            min_lim=nodes[i].lim+nodes[i].hidden_lim;
            //min_index=i;
            //printf("min: %d, min_index: %d \n", min, min_index);
        }
    }
    for(int i=0; i<N; i++){
        if(nodes[i].lim + nodes[i].hidden_lim == min_lim){
            min_index[j]=i;
            j++;
            //min_index=i;
            //printf("min: %d, min_index: %d \n", min, min_index);
        }
    }
    //printf("min: %s\n", nodes[min_index].val);
    //printf("hidden_path:\n");
    //printf("j= %d, nodes[min_index[k]]=%d\n", j, nodes[min_index[j]].val);
    for(int k=0; k<j; k++){
        printf("Node: %s\n", nodes[min_index[k]].val);
        for(int i=0; i<nodes[min_index[k]].lim+nodes[min_index[k]].hidden_lim; i++){
            if(nodes[min_index[k]].lim != 0)
                printf("%s -- %s;\n", nodes[min_index[k]].val, nodes[min_index[k]].path[i]);
            if(nodes[min_index[k]].hidden_lim != 0)
                printf("%s -- %s;\n", nodes[min_index[k]].val, nodes[min_index[k]].hidden_path[i]);
        }
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
        //printf("a=%s, b=%s \n", a, b);
        if(strcmp(a,b)>=0)
            swap(&a, &b);
        int n1=findOrCreate(a);
        int n2=findOrCreate(b);
        //if(!findPath(n1, n2) && !findPath(n2, n1)){
            addPath(n1, n2);
        //}
    }
    //check_svyaz();
    check_stepen();
    //dump();
    //system("cd C:\Users\Àíäðåé\Desktop\Inf_DZ\Graph");
    //system("dot -Tpng C:\Users\Àíäðåé\Desktop\Inf_DZ\Graph\file.dot -o demo_dot.png");

    return 0;
}
