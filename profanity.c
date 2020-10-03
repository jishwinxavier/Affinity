#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  I have two text files
    1. tweet.txt - contains tweets (hardcoded)
    2. slur.txt - contains racial slurs (hardcode)
    Assumption is that all the words in my slur.txt is considered as racial slurs
*/

void main()
{
    int count=0,i;
    char tweet[100];
    char slur[100];
    char dot;

    FILE *fp1,*fp2,fp3;
    fp1=fopen("tweet.txt","r");
    fp2=fopen("slur.txt","r");

    while(!feof(fp1))
    {
        fscanf(fp1,"%s",tweet);
        while(!feof(fp2))
        {
            fscanf(fp2,"%s",slur);
            if(strcmp(tweet,".")!=0)
            {
                if(strcmp(tweet,slur)==0)
                    count++;
            }
            else if(strcmp(tweet,".")==0)
            {
                printf("The degree of profanity is:%d",count);
                printf("\n");
                count=0;
                break;
            }
        }
        fclose(fp2);
        fp2=fopen("slur.txt ","r");
    }

    //printf("The no of times racial words occuring: %d",count);


    fclose(fp1);
    fclose(fp2);
}
