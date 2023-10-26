#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc,char *argv[])
{
    FILE  *fp1 = NULL, *fptr_out = NULL;
    char nline[256];
    int i = 0 ;
    int j = 0 ;
    char* input1[1024] ;
    int len = 0;
    char * temp ;
    if(argc <=1 )
        {
            puts("usage app.exe filename");
            exit(EXIT_FAILURE);
        }
        


 fp1 = fopen( argv[1], "r" );
  if ( ! fp1 )
    {
      printf("Error opening file %s\n", argv[1]);
    }


    
  while ( (fgets(nline, MAXLINE, fp1) != NULL))
        {
        
            input1[i++] =  strdup(nline) ;
            len++;
           
        }
 
 
for(j = 1;j < len;j++)
{
    temp = strdup(input1[j]);
    i = j -1 ;
    while( i > -1 && strlen(input1[i]) > strlen(temp))
    {
        input1[i + 1] = strdup(input1[i]);
        i--;
    }
    input1[i + 1] = strdup(temp);
}

for(i = 0;i < len;i++){
    printf("%s \n",input1[i]);
    
}


 fclose(fp1);
 fclose(fptr_out);

}