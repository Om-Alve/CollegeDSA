#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  FILE *pf = fopen("hello.txt","r");
  char buffer[255];
  float arr[4];
  fgets(buffer,255,pf);
  char* token = strtok(buffer,",");
  for(int i=0;i<4;i++){
    arr[i] = atof(token);
    token = strtok(NULL,",");
  }
  for(int i=0;i<4;i++)
  printf("%.2f ",arr[i]);
  fclose(pf);
  return 0;
}
