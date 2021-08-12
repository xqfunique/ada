Print all the nodes reachable from a given starting node in a given digraph using
Depth First Search method.
/******************************************************************************
*File : DFS.cpp 
*Description: Program to find all nodes reachable from a given node using DFS 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : Wednesday 27 November 2013 
******************************************************************************/
#include <iostream> 
#include <cstdlib> 
using namespace std; 
const int MAX = 100; 
void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n);
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int i,j,k; 
int visited[MAX]; 
int graph[MAX][MAX]; 
int numVert, Vert; 
cout << "Enter the number of vertices : "; 
cin >> numVert; 
for (i=0; i<numVert; i++) 
visited[i] = 0; 
cout << "Enter the adjacency matrix :\n"; 
for (i=0; i<numVert; i++) 
for (j=0; j<numVert; j++) 
cin >> graph[i][j]; 
cout << "Enter the source vertex : "; 
cin >> Vert; 
 fnDepthFirstSearch(Vert,visited,graph,numVert); 
 for (k=0; k<numVert; k++) 
 { 
 if(visited[k]) 
 { 
 cout << "\nVertex " << k+1 << " reachable " << endl; 
 } 
 else 
 { 
 cout << "\nVertex " << k+1 << " not reachable " << endl; 
 } 
 } 
Prabodh C P, Dept of CSE, SIT, Tumkur
 return 0; 
} 
/******************************************************************************
*Function : fnDepthFirstSearch 
*Description : Function to perform DFS traversal and mark visited vertices
*Input parameters: 
* int currentVertex - source vertex 
* int v[] - vector to store visited information 
* int g[][] - adjacency matrix of the graph 
* int n - no of vertices 
*RETURNS : void 
******************************************************************************/
void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n) 
{ 
int i; 
v[currentVertex] = 1; 
for (i=0; i<n; i++) 
if (g[currentVertex][i] && !v[i]) 
fnDepthFirstSearch(i,v,g,n); 
} 
/******************************************************************************
OUTPUT 
SAMPLE 1 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 1 0 
1 0 0 1 
1 0 0 1 
0 1 1 0 
Enter the starting vertex : 1 
Vertex 1 reachable 
Vertex 2 reachable 
Vertex 3 reachable 
Vertex 4 reachable 
SAMPLE 2 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 0 0 
1 0 0 0 
0 0 0 1 
0 0 1 0 
Enter the starting vertex : 1 
Vertex 1 reachable 
Vertex 2 reachable 
Vertex 3 not reachable 
Vertex 4 not reachable 
SAMPLE 3 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
Prabodh C P, Dept of CSE, SIT, Tumkur
0 1 0 0 
0 0 1 0 
0 0 0 1 
0 0 0 0 
Enter the source vertex : 2 
Vertex 1 not reachable 
Vertex 2 not reachable 
Vertex 3 reachable 
Vertex 4 reachable 
SAMPLE 4 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 0 0 
0 0 1 0 
0 0 0 1 
1 0 0 0 
Enter the source vertex : 2 
Vertex 1 reachable 
Vertex 2 reachable 
Vertex 3 reachable 
Vertex 4 reachable 
******************************************************************************/
Prabodh C P, Dept of CSE, SIT, Tumkur
Question 5b
Print all the nodes reachable from a given starting node in a given digraph using
Breadth First Search method.
/******************************************************************************
*File : BFS.cpp 
*Description: Program to find all nodes reachable from a given node using BFS 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : Wednesday 27 November 2013 
******************************************************************************/
#include <iostream> 
#include <cstdlib> 
using namespace std; 
const int MAX = 100; 
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);
class Queue 
{ 
private: 
int cQueue[MAX]; 
int front, rear; 
public: 
Queue(); 
~Queue(); 
int enqueue(int data); 
int dequeue(); 
int empty() { return front == -1 ? 1 : 0; }; 
}; 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
int i,j; 
int graph[MAX][MAX]; 
int visited[MAX]; 
int numVert; 
int startVert; 
cout << "Enter the number of vertices : "; 
cin >> numVert; 
cout << "Enter the adjacency matrix :\n"; 
for (i=0; i<numVert; i++) 
visited[i] = 0; 
for (i=0; i<numVert; i++) 
for (j=0; j<numVert; j++) 
cin >> graph[i][j]; 
cout << "Enter the starting vertex : "; 
cin >> startVert; 
Prabodh C P, Dept of CSE, SIT, Tumkur
fnBreadthFirstSearchReach(startVert-1,graph,visited,numVert); 
cout << "Vertices which can be reached from vertex " << startVert << " 
are :-" << endl; 
for (i=0; i<numVert; i++) 
if (visited[i]) 
cout << i+1 << ", "; 
cout << endl; 
return 0; 
} 
/*Constructor*/ 
Queue::Queue() 
{ 
front = rear = -1; 
} 
/*Destructor*/ 
Queue::~Queue() 
{ 
} 
/******************************************************************************
*Function : enqueue 
*Description : Function to insert an element at the rear of a Queue 
*Input parameters: 
*int data - element to be inserted into the queue 
*RETURNS : returns 1 on success and 0 if queue is full 
******************************************************************************/
int Queue::enqueue(int data) 
{ 
if (front == (rear+1)%MAX) 
return 0; 
if (rear == -1) 
front = rear = 0; 
else 
rear = (rear+1)%MAX; 
cQueue[rear] = data; 
return 1; 
} 
/******************************************************************************
*Function : dequeue 
*Description : Function to delete an element from the front of a Queue 
*Input parameters: no parameters 
*RETURNS : returns element deleted on success and -1 if queue is empty 
******************************************************************************/
int Queue::dequeue() 
{ 
int data; 
if (front == -1) 
return -1; 
data = cQueue[front]; 
if (front == rear) 
front = rear = -1; 
Prabodh C P, Dept of CSE, SIT, Tumkur
else 
front = (front+1)%MAX; 
return data; 
} 
/******************************************************************************
*Function : fnBreadthFirstSearchReach 
*Description : Function to perform BFS traversal and mark visited vertices
*Input parameters: 
* int vertex - source vertex 
* int g[][] - adjacency matrix of the graph 
* int v[] - vector to store visited information 
* int n - no of vertices 
*RETURNS : void 
******************************************************************************/
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n) 
{ 
Queue verticesVisited; 
int frontVertex; 
int i; 
v[vertex] = 1; 
verticesVisited.enqueue(vertex); 
while (!verticesVisited.empty()) 
{ 
frontVertex = verticesVisited.dequeue(); 
for (i=0; i<n; i++) 
{ 
if (g[frontVertex][i] && !v[i]) 
{ 
v[i] = 1; 
verticesVisited.enqueue(i); 
} 
} 
} 
} 
/******************************************************************************
OUTPUT 
SAMPLE 1 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 1 0 
1 0 0 1 
1 0 0 1 
0 1 1 0 
Enter the starting vertex : 1 
Vertices which can be reached from vertex 1 are :- 
1, 2, 3, 4, 
SAMPLE 2 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 0 0 
1 0 0 0 
Prabodh C P, Dept of CSE, SIT, Tumkur
0 0 0 1 
0 0 1 0 
Enter the starting vertex : 1 
Vertices which can be reached from vertex 1 are :- 
1, 2, 
SAMPLE 3 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 0 0 
0 0 1 0 
0 0 0 1 
0 0 0 0 
Enter the starting vertex : 2 
Vertices which can be reached from vertex 2 are :- 
2, 3, 4, 
SAMPLE 4 
Enter the number of vertices : 4 
Enter the adjacency matrix : 
0 1 0 0 
0 0 1 0 
0 0 0 1 
1 0 0 0 
Enter the starting vertex : 2 
Vertices which can be reached from vertex 2 are :- 
1, 2, 3, 4, 
******************************************************************************/
