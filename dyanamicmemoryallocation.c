#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
int *ptr;
printf("Enetr the value of n :");
scanf("%d",&n);
ptr = malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    printf("%d\n",ptr[i]);
}

    return 0;
}
