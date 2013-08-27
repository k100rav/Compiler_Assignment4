#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "def.h"

FILE *file;

//void updateSymbolTable(int n,char *string)
//{
//    char *value;
//    while(fscanf(file,"%s",value)!=EOF){
//        printf("file sys %s %d %d\n",value,value==string,strcmp(value,string));
//        if(value==string)
//            return;
//        fscanf(file,"%s",value);
//    }
//    //printf("file %d\n",fscanf(file,"%s",value));
//    //file=fopen("symbol_table_1.out","w");
//    fprintf(file,"%s %d\n",string,n);
//}


int checkkeyword(char *string)
{
    int i;
    char keyword[25][10]={"short","sizeof","int","float","double","bool","char","signed","unsigned","for","while","do","return","struct","const", "void", "switch","break", "case", "continue","goto","long","static","union","default"};
    for(i=0;i<25;i++){
        if(!strcmp(keyword[i],string)){

            return to(keyword[i]);
        }
    }
    return IDNTIFIER;

}


int checkidentifiers(char **lexeme,attrType *token)
{
    int i=0;
    token->string=(char*)malloc(strlen(*lexeme)*sizeof(char));
    if((**lexeme>=65&&**lexeme<=90)||(**lexeme>=97&&**lexeme<=122)||**lexeme==95)
    {
        *(token->string+i)=**lexeme;
        (*lexeme)++;
        i++;
        if(**lexeme==95)
            return 0;
    }
    else
        return 0;
    while(**lexeme!='\0'){
        if(!((**lexeme>=65&&**lexeme<=90)||(**lexeme>=97&&**lexeme<=122)||(**lexeme>=48&&**lexeme<=57)||**lexeme==122))
        {
//            printf("lexeme %s\n",token->string);
    //      updateSymbolTable(1,token->string);
            checkkeyword(token->string);
            return 0;
        }
        *(token->string+i)=**lexeme;
        (*lexeme)++;
        i++;
    }
//    printf("lexeme %s\n",token->string);
    //updateSymbolTable(1,token->string);
    checkkeyword(token->string);
    return IDNTIFIER;
}

int main()
{
    file=fopen("symbol_table_1.out","r+");
    char input,*lexeme;
    lexeme = (char*)malloc(100*sizeof(char));
    attrType Token;
    while(scanf("%s",lexeme)!=EOF){
        checkidentifiers(&lexeme,&Token);
//        if(checkidentifiers(&lexeme,&Token)!=0){
//            //printf("lexeme %s\n",Token.string);
//            int i;
//        }/*
//        else
//            //printf("no lexeme %s\n",lexeme);
//            int i;*/
    }
    fclose(file);
}
