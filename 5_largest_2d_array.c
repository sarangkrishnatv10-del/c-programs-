#include<stdio.h> 
#include<conio.h> 
void main() { 
int i,j,r,c,a[100][100],lar=0; 
clrscr(); 
printf("Enter the number of rows :"); 
scanf("%d",&r); 
printf("enter the number of columns :"); 
scanf("%d",&c); 
printf("Enter each numbers :"); 
for(i=0;i<=r;i++){ 
for(j=0;j<=c;j++) { 
printf("[%d][%d]",i,j); 
scanf("%d",&a[i][j]); 
} 
} 
for(i=0;i<=r;i++){ 
for(j=0;j<=c;j++){ 
printf("%d \t",a[i][j]); 
} 
printf("\n\n"); 
} 
for(i=0;i<=r;i++){ 
for(j=0;j<=c;j++){ 
if(a[i][j] > lar){ 
lar= a[i][j]; 
} 
} 
} 
printf("The largest here is : %d",lar); 
getch(); 
}
    return 0;
}
