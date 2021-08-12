Question 4a
Obtain the Topological ordering of vertices in a given digraph.
/******************************************************************************
*File : TopologicalSorting.c 
*Description : Program to find Topological ordering of nodes in a DAG 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : 11 Nov 2013 
******************************************************************************/
#include <stdio.h> 
const int MAX = 10; 
void fnTopological(int a[MAX][MAX], int n); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int a[MAX][MAX],n; 
int i,j; 
printf("Topological Sorting Algorithm -\n"); 
printf("\nEnter the number of vertices : "); 
scanf("%d",&n); 
printf("Enter the adjacency matrix -\n"); 
for (i=0; i<n; i++) 
for (j=0; j<n; j++) 
scanf("%d",&a[i][j]); 
fnTopological(a,n); 
printf("\n"); 
return 0; 
} 
/******************************************************************************
*Function : fnTopological 
*Description : Function to find Topological ordering of nodes in a DAG 
*Input parameters: 
* int a[MAX][MAX] - adjacency matrix of the input graph 
* int n - no of vertices in the graph 
*RETURNS : no value 
******************************************************************************/
void fnTopological(int a[MAX][MAX], int n) 
{ 
int in[MAX], out[MAX], stack[MAX], top=-1; 
int i,j,k=0; 
for (i=0;i<n;i++) 
{ 
in[i] = 0; 
for (j=0; j<n; j++) 
if (a[j][i] == 1) 
in[i]++; 
} 
Prabodh C P, Dept of CSE, SIT, Tumkur
while(1) 
{ 
for (i=0;i<n;i++) 
{ 
if (in[i] == 0) 
{ 
stack[++top] = i; 
in[i] = -1; 
} 
} 
if (top == -1) 
break; 
out[k] = stack[top--]; 
for (i=0;i<n;i++) 
{ 
if (a[out[k]][i] == 1) 
in[i]--; 
} 
k++; 
} 
printf("Topological Sorting (JOB SEQUENCE) is:- \n"); 
for (i=0;i<k;i++) 
printf("%d ",out[i] + 1); 
} 


//////////////////////////////////////////////

Question 4b
Sort a given set of elements using Insertion sort method.
/******************************************************************************
*File : InsertionSort.c 
*Description : Program to sort an array using Insertion Sort 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : 22 Nov 2013 
******************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h> 
#include <time.h> 
void fnGenRandInput(int [], int); 
void fnDispArray( int [], int); 
void fnInsertionSort(int [], int); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
FILE *fp; 
struct timeval tv; 
double dStart,dEnd; 
int iaArr[100000],iNum,iPos,iKey,i,iChoice; 
 for(;;) 
 { 
 printf("\n1.Plot the Graph\n2.InsertionSort\n3.Exit"); 
 printf("\nEnter your choice\n"); 
 scanf("%d",&iChoice); 
 switch(iChoice) 
 { 
 case 1: 
 fp = fopen("InsertionPlot.dat","w"); 
 for(i=100;i<10000;i+=100) 
 { 
 fnGenRandInput(iaArr,i); 
 gettimeofday(&tv,NULL); 
 dStart = tv.tv_sec + (tv.tv_usec/1000000.0); 
 fnInsertionSort(iaArr,i); 
 gettimeofday(&tv,NULL); 
 dEnd = tv.tv_sec + (tv.tv_usec/1000000.0); 
 fprintf(fp,"%d\t%lf\n",i,dEnd-dStart); 
 } 
 fclose(fp); 
Prabodh C P, Dept of CSE, SIT, Tumkur
 printf("\nData File generated and stored in file < 
InsertionPlot.dat >.\n Use a plotting utility\n"); 
 break; 
 case 2: 
 printf("\nEnter the number of elements to sort\n"); 
 scanf("%d",&iNum); 
 printf("\nUnsorted Array\n"); 
 fnGenRandInput(iaArr,iNum); 
 fnDispArray(iaArr,iNum); 
 fnInsertionSort(iaArr,iNum); 
 printf("\nSorted Array\n"); 
 fnDispArray(iaArr,iNum); 
 break; 
 case 3: 
 exit(0); 
 } 
 } 
 return 0; 
} 
/******************************************************************************
*Function : fnInsertionSort 
*Description : Function to sort an array using Insertion Sort 
*Input parameters: 
* int A[] - iaArray to hold integers 
* int n - no of elements in the array 
*RETURNS : no value 
******************************************************************************/
void fnInsertionSort(int A[], int n) 
{ 
 int i, j, iKey; 
 for(i=1;i<n;i++) 
 { 
 iKey = A[i]; 
 j = i-1; 
 while(j>=0 && A[j] > iKey) 
 { 
 A[j+1] = A[j]; 
 j--; 
 } 
 A[j+1] = iKey; 
 } 
} 
/******************************************************************************
*Function : GenRandInput 
*Description : Function to generate a fixed number of random elements 
*Input parameters: 
* int X[] - array to hold integers 
* int n - no of elements in the array 
*RETURNS :no return value 
******************************************************************************/
void fnGenRandInput(int X[], int n) 
{ 
int i; 
srand(time(NULL)); 
for(i=0;i<n;i++) 
Prabodh C P, Dept of CSE, SIT, Tumkur
{ 
X[i] = rand()%10000; 
} 
} 
/******************************************************************************
*Function : DispArray 
*Description : Function to display elements of an array 
*Input parameters: 
* int X[] - array to hold integers 
* int n - no of elements in the array 
*RETURNS : no return value 
******************************************************************************/
void fnDispArray( int X[], int n) 
{ 
int i; 
for(i=0;i<n;i++) 
printf(" %5d \n",X[i]); 
}
/****************************************************************************
InsertionPlot.gpl
# Gnuplot script file for plotting data in file "InsertionPlot.dat" 
# This file is called InsertionPlot.gpl 
set terminal png font arial 
set title "Time Complexity for Insertion Sort" 
set autoscale 
set xlabel "Size of Input" 
set ylabel "Sorting Time (microseconds)" 
set grid 
set output "InsertionPlot.png" 
plot "InsertionPlot.dat" t 'Insertion Sort' with lines
Execution
$gnuplot InsertionPlot.gpl
******************************************************************************/
