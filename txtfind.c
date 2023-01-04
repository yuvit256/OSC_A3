#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getword(char w[]);

int similar (char *s, char *t, int n);

void print_similar_words(char *str);

int getLine(char s[]);

int substring( char *str1, char *str2);

void print_lines(char *str);

int main(){
    char word[WORD];
    char option;
    getword(word);
    scanf(" %c\n", &option);
    if(option == 'a'){
        print_lines(word);
    }
    else if(option == 'b'){
        print_similar_words(word);
    }
    return 0;
}

int getword(char w[])
{
    int i=0;
    while(i<WORD)
    {
        if (scanf("%c", &w[i]) == EOF)
        {
            w[i] = '\0';
            return i;
        }
        if((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' ')){
            w[i] = '\0';
            return i;
        }
        i++;
    }
    if (i == WORD)
        w[i - 1] = '\0';
    return i;
}

int similar (char *s, char *t, int n){
    int sLength = strlen(s), tLength = strlen(t);
    int i = 0, j = 0;
    if (sLength - tLength != n){return 0;}
    while ((i < sLength) && (j < tLength))
    {
        if (*(s + i) == *(t + j))
            j++;
        i++;
    }
    if(tLength == j)
        return 1;
    return 0;
}

void print_similar_words(char *str) {
    char simWord[WORD] = {0};
    while(getword(simWord) != 0)
    {
        if (similar(simWord, str, 1) || similar(simWord, str, 0))
            printf("%s\n", simWord);
    }
}

int getLine(char s[])
{
    int i = 0;
    while(i<LINE)
    {
        if (scanf("%c", &s[i]) == EOF)
        {
            s[i] = '\0';
            return i;
        }
        if(s[i] == '\n'){
            s[i] = '\0';
            return i;
        }
        i++;
    }
    if (i == LINE)
        s[i - 1] = '\0';
    return i;
}

int substring( char *str1, char *str2)
{
    char *p1, *p2, *p3;
    int i=0,j=0;
    p1 = str1;
    p2 = str2;
    for(i = 0; i<strlen(str1); i++)
    {
        if(*p1 == *p2)
        {
            p3 = p1;
            for(j = 0;j<strlen(str2);j++)
            {
                if(*p3 == *p2)
                {
                    p3++;p2++;
                } 
                else
                    break;
            }
            p2 = str2;
            if(j == strlen(str2))
            {
                return 1; //Substring found
            }
        }
        p1++; 
    }
    return 0; //Substring NOT found
}

void print_lines(char *str)
{
    char line[LINE] = {0};
    while(getLine(line) != 0)
    {
        if (substring(line, str) != 0)
            printf("%s\n", line);
    }
}