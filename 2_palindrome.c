#include<stdio.h> 
#include<conio.h> 
void main(){ 
int r,n,sum=0,temp; 
clrscr(); 
printf("Enter the number: "); 
scanf("%d",&n); 
temp=n; 
while(n>0){ 
r=n%10; 
sum=(sum*10)+r; 
n=n/10; 
} 
if(temp==sum){ 
printf("%d is a palindrome",temp); 
}else{ 
printf("%d is not a palindrome",temp); 
} 
getch(); 
}
