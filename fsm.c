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

int checkAoperator(char **lexeme_Begin)
{
    char *lexeme_forward;
    lexeme_forward=*lexeme_Begin;
    if(*lexeme_forward==43){
        lexeme_forward++;
        if(*lexeme_forward==43){
            lexeme_forward++;
            *lexeme_Begin=lexeme_forward;
            return PLUS_PLUS;
        }
        *lexeme_Begin=lexeme_forward;
        return PLUS;
    }
    else if(*lexeme_forward==45){
        lexeme_forward++;
        if(*lexeme_forward==45){
            lexeme_forward++;
            *lexeme_Begin=lexeme_forward;
            return MINUS_MINUS;
        }
        *lexeme_Begin=lexeme_forward;
        return MINUS;
    }
    else if(*lexeme_forward==42){
        lexeme_forward++;
        *lexeme_Begin=lexeme_forward;
        return MULT;
    }
    else if(*lexeme_forward==47){
        lexeme_forward++;
        *lexeme_Begin=lexeme_forward;
        return DIV;
    }
    return 0;
}

int checkRoperator(char **lexeme_Begin)
{
    char *lexeme_forward;
    lexeme_forward=*lexeme_Begin;
    if(*lexeme_forward==60){
        lexeme_forward++;
        if(*lexeme_forward==61){
            lexeme_forward++;
            *lexeme_Begin=lexeme_forward;
            return LESS_EQ;
        }
        *lexeme_Begin=lexeme_forward;
        return GREATER;
    }
    else if(*lexeme_forward==61){
        lexeme_forward++;
        if(*lexeme_forward==61){
            lexeme_forward++;
            *lexeme_Begin=lexeme_forward;
            return EQ_EQ;
        }
        lexeme_forward++;
        return EQ;
    }
    else if(*lexeme_forward==62){
        lexeme_forward++;
    }

}

int checkinteger(char **lexeme_begin,attrType *token)
{
    int i=0;
    char *lexeme_forward;
    lexeme_forward=*lexeme_begin;
    token->string=(char*)malloc(strlen(*lexeme_begin)*sizeof(char));
    if(*lexeme_forward==45||*lexeme_forward==43||(*lexeme_forward>=48&&*lexeme_forward<=57)){
        *(token->string+i)=*lexeme_forward;
        lexeme_forward++;
        i++;
    }
    while(*lexeme_forward!='0')
    {
        if(*lexeme_forward>=48&&*lexeme_forward<=57){
            *(token->string+i)=*lexeme_forward;
            lexeme_forward++;
            i++;
        }
        else if(*lexeme_forward==45||*lexeme_forward==43){
            return -1;
        }
    }
}

int checkkeyword(char *string)
{
    int i;
    char keyword[24][10]={"short","int","float","double","bool","char","signed","unsigned","for","while","do","return","struct","const", "void", "switch","break", "case", "continue","goto","long","static","union","default"};
    int id[24]={SHORT,INT,FLOAT,DOUBLE,BOOL,CHAR,SIGNED,UNSIGNED,FOR,WHILE,DO,RETURN,STRUCT,CONST,VOID,SWITCH,BREAK ,CASE ,CONTINUE,GOTO,LONG,STATIC,UNION, DEFAULT};
    for(i=0;i<24;i++){
        if(!strcmp(keyword[i],string)){
            return id[i];
        }
    }
    return -1;
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
