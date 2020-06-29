#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argv[2]!=NULL){
    char a, buf;
    int num=atoi(argv[2]); //num - смещение

    FILE *input = fopen(argv[3], "r");
    FILE *output = fopen(argv[4], "w+");

    if(input==NULL)
        printf("Error in input\n");
    if(output==NULL)
        printf("Error in output\n");

    //printf("It's alive!\n");



    if(strcmp(argv[1],"-encode")==0){
        printf("Encoding...\n");
        while (!feof(input)){
            a = fgetc(input);
            //printf("read: %c (%d)  ", a,a);
            if(feof(input)){
                //printf("\nEnd of input file!\n");
                fclose(input);
                fclose(output);
                return 0;
            }
            buf=a;
            //printf("buf before if = %c\n", buf);
            if((buf>='A' && buf<='Z') || (buf>='a' && buf<'z')){
                //printf("Odnako\n");
                for (int i=0; i<num; i++){
                    buf=buf+1;
                    if(buf>'Z' && buf<'a')
                        buf='A';
                    if(buf>'z' && buf<'~')
                        buf='a';
                }
            }
            fputc(buf, output);
            //printf("\twrite: %c(%d)\n", buf, buf);
        }
        //printf("Done!");
    }

    if(strcmp(argv[1],"-decode")==0){
        //printf("Decoding...\n");
        while (!feof(input)){
        //printf("Decoding...\n");
        a = fgetc(input);
        if(feof(input)){
            //printf("End of input file!\n");
            fclose(input);
            fclose(output);
            return 0;
        }
        buf=a;
        if((buf>='A' && buf<='Z') || (buf>='a' && buf<'z')){
            for (int i=0; i<num; i++){
                buf=buf-1;
                if(buf>'=' && buf<'A')
                    buf='Z';
                if(buf>']' && buf<'a')
                    buf='z';
            }
            fputc(buf, output);
        } else
            fputc(a, output);
        }
        //printf("Done!");
    }
    //fputc('#', output);
    fclose(input);
    fclose(output);
    } else{
        if(strcmp(argv[1],"-help")==0){
            printf(" To encode file use : -encode *number* file_1.txt file_2.txt\n To decode file use : -decode *number* file_1.txt file_2.txt\n Where *number* is shift, file_1 is a file you want to encode/decode,\n file_2 is a file where an encoded/decoded text will be placed\n");
        }
    }
    return 0;
}
