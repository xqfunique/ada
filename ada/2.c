#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h> 
#include <time.h> 
void fnGenRandInput(int [], int); 
void fnDispArray( int [], int); 
void fnMerge(int [], int ,int ,int); 
void fnMergeSort(int [], int , int); 
/******************************************************************************
*Function : main 
*Input parameters: 
* int argc - no of commamd line arguments 
* char **argv - vector to store command line argumennts 
*RETURNS : 0 on success 
******************************************************************************/
int main( int argc, char **argv) 
{ 
FILE *fp; 
struct timeval tv; 
double dStart,dEnd; 
int iaArr[500000],iNum,iPos,iKey,i,iChoice; 
 for(;;) 
 { 
 printf("\n1.Plot the Graph\n2.MergeSort\n3.Exit"); 
 printf("\nEnter your choice\n"); 
 scanf("%d",&iChoice); 
 switch(iChoice) 
 { 
 case 1: 
 fp = fopen("MergePlot.dat","w"); 
 for(i=100;i<100000;i+=100) 
 { 
 fnGenRandInput(iaArr,i); 
 gettimeofday(&tv,NULL); 
 dStart = tv.tv_sec + (tv.tv_usec/1000000.0); 
Prabodh C P, Dept of CSE, SIT, Tumkur
 fnMergeSort(iaArr,0,i-1); 
 gettimeofday(&tv,NULL); 
 dEnd = tv.tv_sec + (tv.tv_usec/1000000.0); 
 fprintf(fp,"%d\t%lf\n",i,dEnd-dStart); 
 } 
 fclose(fp); 
 printf("\nData File generated and stored in file < 
MergePlot.dat >.\n Use a plotting utility\n"); 
 break; 
 case 2: 
 printf("\nEnter the number of elements to sort\n"); 
 scanf("%d",&iNum); 
 printf("\nUnsorted Array\n"); 
 fnGenRandInput(iaArr,iNum); 
 fnDispArray(iaArr,iNum); 
 fnMergeSort(iaArr,0,iNum-1); 
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
*Function : fnMerge 
*Description : Function to merge two sorted arrays 
*Input parameters: 
* int a[] - iaArray to hold integers 
* int low - start index of the subiaArray to be sorted 
* int mid - mid index of the subiaArray to be sorted 
* int right - end index of the subiaArray to be sorted 
*RETURNS : no value 
******************************************************************************/
void fnMerge(int a[], int low,int mid,int high) 
{ 
int i,k,j,b[500000]; 
i=k=low; 
j=mid+1; 
while(i<=mid && j<=high) 
{ 
if(a[i]<a[j]) 
b[k++]=a[i++]; 
else 
b[k++]=a[j++]; 
} 
while(i<=mid) 
b[k++]=a[i++]; 
while(j<=high) 
b[k++]=a[j++]; 
Prabodh C P, Dept of CSE, SIT, Tumkur
for(i=low;i<k;i++) 
a[i]=b[i]; 
} 
/******************************************************************************
*Function : fnMergeSort 
*Description : Function to sort elements in an iaArray using Quick Sort 
*Input parameters: 
* int a[] - iaArray to hold integers 
* int low - start index of the array to be sorted 
* int high- end index of the array to be sorted 
*RETURNS : no value 
******************************************************************************/
void fnMergeSort(int a[],int low,int high) 
{ 
int mid; 
if(low<high) 
{ 
mid=(low+high)/2; 
fnMergeSort(a,low,mid); 
fnMergeSort(a,mid+1,high); 
fnMerge(a,low,mid,high); 
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
Prabodh C P, Dept of CSE, SIT, Tumkur
/******************************************************************************
gnuplot> plot "./MergePlot.txt" 
gnuplot> plot "./MergePlot.txt" with lines 
gnuplot> plot "./MergePlot.txt" with linespoints 
******************************************************************************/
MergePlot.gpl
# Gnuplot script file for plotting data in file "MergePlot.dat" 
# This file is called MergePlot.gpl 
set terminal png font arial 
set title "Time Complexity for Merge Sort" 
set autoscale 
set xlabel "Size of Input" 
set ylabel "Sorting Time (microseconds)" 
set grid 
set output "MergePlot.png"