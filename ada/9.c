Question 9a
Implement All Pair Shortest paths problem using Floyd's algorithm.
/*************************************************************************** 
*File : Floyd.c 
*Description: Program to implement Floyd's Algorithm 
*Author : Prabodh C P 
*Compiler : gcc compiler, Ubuntu 12.04 
*Date : 20 November 2013 
***************************************************************************/ 
#include <stdio.h> 
#include <stdlib.h> 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int iN, i, j, k; 
int iaFloyd[10][10], iaCost[10][10]; 
printf("\n*********************************************************"); 
printf("\n*\tPROGRAM TO IMPLEMENT FLOYD'S ALGORITHM\t*\n"); 
printf("*********************************************************"); 
printf("\nEnter the iNber of vertices\n"); 
scanf("%d",&iN); 
printf("\nEnter the Cost adjacency Matrix\n"); 
for(i=0;i<iN;i++) 
for(j=0;j<iN;j++) 
scanf("%d",&iaCost[i][j]); 
printf("\nInput Graph\n"); 
for(i=0;i<iN;i++) 
{ 
for(j=0;j<iN;j++) 
{ 
printf("%d\t",iaCost[i][j]); 
} 
printf("\n"); 
} 
printf("\n"); 
for(i=0;i<iN;i++) 
{ 
for(j=0;j<iN;j++) 
{ 
iaFloyd[i][j] = iaCost[i][j]; 
} 
} 
for(k=0;k<iN;k++) 
{ 
for(i=0;i<iN;i++) 
{ 
Prabodh C P, Dept of CSE, SIT, Tumkur
for(j=0;j<iN;j++) 
{ 
iaFloyd[i][j] = (iaFloyd[i][j] < (iaFloyd[i][k] + 
iaFloyd[k][j]))? (iaFloyd[i][j]):(iaFloyd[i][k] + iaFloyd[k][j]); 
} 
} 
} 
printf("\nAll Pair Shortest Path Matrix\n"); 
for(i=0;i<iN;i++) 
{ 
for(j=0;j<iN;j++) 
{ 
printf("%d\t",iaFloyd[i][j]); 
} 
printf("\n"); 
} 
printf("\n"); 
return 0; 
} 
/*************************************************************************** 
Compiling instructions 
$ gcc filename.c -o FLOYD.x 
Execution 
$./FLOYD.x 
OUTPUT 
SAMPLE 1 
Input Graph 
0 9999 3 9999 
2 0 9999 9999 
9999 7 0 1 
6 9999 9999 0 
All Pair Shortest Path Matrix 
0 10 3 4 
2 0 5 6 
7 7 0 1 
6 16 9 0 
SAMPLE 2 
Input Graph 
0 15 10 9999 45 9999 
9999 0 15 9999 20 9999 
20 9999 0 20 9999 9999 
9999 10 9999 0 35 9999 
9999 9999 9999 30 0 9999 
9999 9999 9999 4 9999 0 
All Pair Shortest Path Matrix 
0 15 10 30 35 9999 
35 0 15 35 20 9999 
20 30 0 20 50 9999 
45 10 25 0 30 9999 
75 40 55 30 0 9999 
49 14 29 4 34 0 
***************************************************************************/ 
Prabodh C P, Dept of CSE, SIT, Tumkur
Question 9b
Find the Binomial Co­efficient using Dynamic Programming.
/
*******************************************************************************
* 
*File : BinomialCoeff.cpp 
*Description : Program to find Binomial Coefficient 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : Friday 22 November 2013 
*******************************************************************************
*/ 
#include <iostream> 
using namespace std; 
const int MAXSIZE = 10; 
int fnBinomialCoefficient(int n, int k); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int n, k; 
cout << "Binomial Coefficients\n"; 
cout << "Calculates the value of nCk\n"; 
cout << "Enter the value of n : "; 
cin >> n; 
cout << "Enter the value of k : "; 
cin >> k; 
if (n<k) 
cout << "\nInvalid Input n should be larger than k!\n"; 
else 
cout << "\nThe value of " << n << "C" << k << " is " << 
fnBinomialCoefficient(n, k) << endl; 
 return 0; 
} 
/******************************************************************************
*Function : fnBinomialCoefficient 
*Description : Function to find Binomial Coefficient 
*Input parameters: 
* int n - no of elements 
* int k - no of elements chosen out of n elements 
*RETURNS : value of nCk 
******************************************************************************/
int fnBinomialCoefficient(int n, int k) 
{ 
int c[MAXSIZE][MAXSIZE]; 
int i,j; 
for (i=0; i<=n; i++) 
{ 
c[i][0] = 1; 
Prabodh C P, Dept of CSE, SIT, Tumkur
c[i][i] = 1; 
} 
for (i=1; i<=n; i++) 
for (j=1; j<i; j++) 
c[i][j] = c[i-1][j-1] + c[i-1][j]; 
cout << "\nThe Binomial matrix is :" << endl << "\t"; 
for (i=0; i<=n; i++) 
cout << i << "\t"; 
cout << endl; 
for (i=0; i<=n+1; i++) 
cout<<"========"; 
cout << endl; 
for (i=0; i<=n; i++) 
{ 
cout << "i=" << i << "\t"; 
for (j=0; j<=i; j++) 
{ 
cout << c[i][j] << "\t"; 
} 
cout << endl; 
} 
cout << endl; 
return c[n][k]; 
} 
/******************************************************************************
Sample 1: 
Binomial Coefficients 
Calculates the value of nCk 
Enter the value of n : 4 
Enter the value of k : 6 
Invalid Input n should be larger than k! 
Sample 2: 
Binomial Coefficients 
Calculates the value of nCk 
Enter the value of n : 6 
Enter the value of k : 2 
The Binomial matrix is : 
0 1 2 3 4 5 6
================================================================ 
i=0 1
i=1 1 1
i=2 1 2 1
i=3 1 3 3 1
i=4 1 4 6 4 1
i=5 1 5 10 10 5 1
i=6 1 6 15 20 15 6 1
The value of 6C2 is 15 
******************************************************************************