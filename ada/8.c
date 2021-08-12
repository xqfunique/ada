Question 8a
Implement  0/1 Knapsack   problem   using   dynamic  programming.
/******************************************************************************
*File : knapSack.cpp 
*Description: Program to solve 0/1 Knapsack problem using dynamic programming. 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : 11 Nov 2013 
******************************************************************************/
#include <iostream> 
#include <cstdlib> 
using namespace std; 
const int MAX = 10; 
inline int max(int a, int b); 
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]); 
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int i, j, totalProfit; 
int weight[MAX]; 
int profit[MAX]; 
int capacity; 
int num; 
int loaded[MAX]; 
int table[MAX][MAX]; 
cout << "Enter the maxium number of objects : "; 
cin >> num; 
cout << "Enter the weights : \n"; 
for (i=1; i<=num; i++) 
{ 
 cout << "\nWeight " << i << ": "; 
cin >> weight[i]; 
 } 
cout << "\nEnter the profits : \n"; 
for (i=1; i<=num; i++) 
{ 
 cout << "\nProfit " << i << ": "; 
cin >> profit[i]; 
 } 
cout << "\nEnter the maximum capacity : "; 
cin >> capacity; 
totalProfit = 0; 
for( i=1; i<=num; i++) 
loaded[i] = 0; 
Prabodh C P, Dept of CSE, SIT, Tumkur
fnProfitTable(weight,profit,num,capacity,table); 
fnSelectItems(num,capacity,table,weight,loaded); 
cout << "Profit Matrix\n"; 
for (i=0; i<=num; i++) 
{ 
 for(j=0; j<=capacity; j++) 
 { 
 cout <<"\t"<<table[i][j]; 
 } 
 cout << endl; 
} 
cout << "\nItem numbers which are loaded : \n{ "; 
for (i=1; i<=num; i++) 
{ 
if (loaded[i]) 
{ 
cout << i << " "; 
totalProfit += profit[i]; 
} 
} 
cout << "}" << endl; 
cout << "\nTotal Profit : " << totalProfit << endl; 
return 0; 
} 
inline int max(int a, int b) 
{ 
return a>b ? a : b; 
} 
/******************************************************************************
*Function : fnProfitTable 
*Description : Function to construct the profit table 
*Input parameters: 
* int w[MAX] - weight vector 
* int p[MAX] - profit vector 
* int n - no of items 
* int c - knapsack capacity 
* int t[MAX][MAX] - profit table 
*RETURNS : no value 
******************************************************************************/
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]) 
{ 
int i,j; 
for (j=0; j<=c; j++) 
t[0][j] = 0; 
for (i=0; i<=n; i++) 
t[i][0] = 0; 
for (i=1; i<=n; i++) 
{ 
for (j=1; j<=c; j++) 
{ 
if (j-w[i] < 0) 
t[i][j] = t[i-1][j]; 
else 
t[i][j] = max( t[i-1][j], p[i] + t[i-1][j-w[i]]); 
Prabodh C P, Dept of CSE, SIT, Tumkur
} 
} 
} 
/******************************************************************************
*Function : fnSelectItems 
*Description: Function to determine optimal subset that fits into the knapsack 
*Input parameters: 
* int n - no of items 
* int c - knapsack capacity 
* int t[MAX][MAX] - profit table 
* int w[MAX] - weight vector 
* int l[MAX] - bit vector representing the optimal subset 
*RETURNS : no value 
******************************************************************************/
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]) 
{ 
int i,j; 
i = n; 
j = c; 
while (i >= 1 && j >= 1) 
{ 
if (t[i][j] != t[i-1][j]) 
{ 
l[i] = 1; 
j = j - w[i]; 
i--; 
} 
else 
i--; 
} 
} 
/******************************************************************************
Enter the maxium number of objects : 4 
Enter the weights : 
Weight 1: 2 
Weight 2: 1 
Weight 3: 3 
Weight 4: 2 
Enter the profits : 
Profit 1: 12 
Profit 2: 10 
Profit 3: 20 
Profit 4: 15 
Enter the maximum capacity : 5 
Profit Matrix 
0 0 0 0 0 0 
0 0 12 12 12 12 
0 10 12 22 22 22 
0 10 12 22 30 32 
0 10 15 25 30 37 
Item numbers which are loaded : 
{ 1 2 4 } 
Total Profit : 37 
*****************************************************************************/ 
Prabodh C P, Dept of CSE, SIT, Tumkur
Question 8b
Compute the transitive closure of a given directed graph using Warshall's algorithm.
/******************************************************************************
*File : Warshall.c 
*Description : Program to find transitive closure of a given directed 
* graph using Warshall's algorithm. 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : 11 Nov 2013 
******************************************************************************/
#include <stdio.h> 
const int MAX = 100; 
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int i, j, numVert; 
int graph[MAX][MAX]; 
printf("Warshall's Transitive Closure\n"); 
printf("Enter the number of vertices : "); 
scanf("%d",&numVert); 
printf("Enter the adjacency matrix :-\n"); 
for (i=0; i<numVert; i++) 
for (j=0; j<numVert; j++) 
scanf("%d",&graph[i][j]); 
WarshallTransitiveClosure(graph, numVert); 
printf("\nThe transitive closure for the given graph is :-\n"); 
for (i=0; i<numVert; i++) 
{ 
for (j=0; j<numVert; j++) 
{ 
printf("%d\t",graph[i][j]); 
} 
printf("\n"); 
} 
return 0; 
} 
/******************************************************************************
*Function : WarshallTransitiveClosure 
*Description : Function to transitive closure of a given directed 
* graph using Warshall's algorithm. 
*Input parameters: 
* int graph[MAX][MAX] - adjacency matrix of the input graph 
* int numVert - no of vertices in the graph 
*RETURNS : no value 
******************************************************************************/
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert) 
Prabodh C P, Dept of CSE, SIT, Tumkur
{ 
int i,j,k; 
for (k=0; k<numVert; k++) 
{ 
for (i=0; i<numVert; i++) 
{ 
for (j=0; j<numVert; j++) 
{ 
if (graph[i][j] || (graph[i][k] && graph[k][j])) 
graph[i][j] = 1; 
} 
} 
} 
} 
/******************************************************************************
Warshall's Transitive Closure 
Enter the number of vertices : 4 
Enter the adjacency matrix :- 
0 0 1 0 
0 0 0 1 
1 0 0 0 
0 1 0 0 
The transitive closure for the given graph is :- 
1 0 1 0
0 1 0 1
1 0 1 0
0 1 0 1
Warshall's Transitive Closure 
Enter the number of vertices : 4 
Enter the adjacency matrix :- 
0 1 1 0 
1 0 0 1 
1 0 0 1 
0 1 1 0 
The transitive closure for the given graph is :- 
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*****************************************************************************