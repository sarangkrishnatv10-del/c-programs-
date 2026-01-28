#include<stdio.h> 
#include<conio.h> 
void main(){ 
int a[100],i,n; 
clrscr(); 
printf("Enter the number of elements :"); 
scanf("%d",&n); 
printf("Enter the elements :"); 
for(i=0;i<n;i++){ 
scanf("%d",&a[i]); 
} 
printf("The elements in reverse : "); 
for(i=n-1;i>=0;i--){ 
printf("%d ",a[i]); 
} 
getch(); 
} 
    return 0;
}
