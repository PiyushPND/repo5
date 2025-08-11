#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
void to_lowercase(char*str)
{   for(int i=0;str[i];i++){str[i]=tolower(str[i]);}}
int main()
{   char paragraph[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int freq[MAX_WORDS]={0};
    int word_count=0;
    printf("Enter a paragraph:\n\n");
    fgets(paragraph,sizeof(paragraph),stdin);
    paragraph[strcspn(paragraph,"\n")]=0;
    char*token=strtok(paragraph," ");
    while(token!=NULL)
    {   int len=strlen(token);
        while(len>0&&ispunct(token[len-1]))
        {   token[len-1]='\0';
            len--;}
        while(len>0&&ispunct(token[0]))
        {   memmove(token,token+1,len);
            len--;}
        to_lowercase(token);
        int found=0;
        for(int i=0;i< word_count;i++)
        {   if(strcmp(words[i],token)==0)
            {   freq[i]++;
                found=1;
                break;}}
        if(!found&&len>0)
        {   strcpy(words[word_count],token);
            freq[word_count]=1;
            word_count++;}
        token=strtok(NULL," ");}
    printf("\nWord Frequencies:\n");
    for(int i=0;i< word_count;i++){printf("%s:\t%d\n",words[i],freq[i]);}
    return 0;}
