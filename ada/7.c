Question 7a
Implement Horspool algorithm for String Matching.
/******************************************************************************
*File : Horspool.c 
*Description: Program to find a matching sub string in a given text using 
Horspool's Algorithm 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : 21 Nov 2013 
******************************************************************************/
#include <stdio.h> 
#include <string.h> 
const int MAX = 256; 
int fnHorspool(char string[], char pattern[],int []); 
void fnGenShiftTable(char *,int []); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
char text[MAX]; 
char pattern[MAX]; 
 int shiftTable[MAX]; 
int found; 
puts("Enter the source string : "); 
gets(text); 
puts("Enter the pattern string : "); 
gets(pattern); 
fnGenShiftTable(pattern,shiftTable); 
found = fnHorspool(text,pattern,shiftTable); 
if(found==-1) 
puts("\nMatching Substring not found.\n"); 
else 
printf("\nMatching Substring found at position: %d\n",found+1); 
return 0; 
} 
/******************************************************************************
*Function : fnGenShiftTable 
*Description : Function to generate the shift table 
*Input parameters: 
* char p[] - pattern to be searched for 
* int t[] - shift table containing shift values for each alphabet 
*RETURNS : no value 
******************************************************************************/
void fnGenShiftTable(char p[], int t[]) 
{ 
int m, i, j; 
m = strlen(p); 
for(i=0; i<MAX; i++) 
{ 
Prabodh C P, Dept of CSE, SIT, Tumkur
t[i]=m; 
} 
for(j=0; j<m-1; j++) 
{ 
t[p[j]] = m-1-j; 
} 
} 
/******************************************************************************
*Function : fnHorspool 
*Description : Function to search for a matching substring for a given 
pattern in the text 
*Input parameters: 
* char s[] - text string 
* char p[] - pattern to be searched for 
* int t[] - shift table containing shift values for each alphabet 
*RETURNS : no value 
******************************************************************************/
int fnHorspool(char s[],char p[],int t[]) 
{ 
int i, n, m, k; 
n = strlen(s); 
m = strlen(p); 
i = m-1; 
while(i<n) 
{ 
k = 0; 
while((k<m)&&(p[m-1-k]==s[i-k])) 
k++; 
if (k == m) 
return i-m+1; 
else 
i = i+t[s[i]]; 
} 
return -1; 
} 
/******************************************************************************
Sample 1: 
Enter the source string : 
I want you to rebel! 
Enter the pattern string : 
you 
Matching Substring found at position: 8 
Sample 2: 
Enter the source string : 
Be a rebel! 
Enter the pattern string : 
coward 
Matching Substring not found. 
******************************************************************************/
Prabodh C P, Dept of CSE, SIT, Tumkur
Question 7b
For a given set of elements construct an AVL Tree and also display balance factor for
each node.
/******************************************************************************
*File : AVL.c 
*Description: Program to construct an AVL Tree for a given set of elements 
* and also display balance factor for each node. 
*Author : Prabodh C P 
*Compiler : gcc compiler 4.6.3, Ubuntu 12.04 
*Date : Saturday 14 December 2013 
******************************************************************************/
#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 
struct node 
{ 
int info,balance; 
struct node *lchild,*rchild; 
}; 
typedef struct node * NODEPTR; 
void inorder(NODEPTR); 
NODEPTR insert (int , NODEPTR, bool *); 
NODEPTR search(NODEPTR,int); 
/******************************************************************************
*Function : main 
*Input parameters: no parameters 
*RETURNS : 0 on success 
******************************************************************************/
int main(void) 
{ 
bool ht_inc; 
int info,choice; 
NODEPTR root; 
root = NULL; 
while(1) 
{ 
printf("1.Insert\n2.Display\n3.Quit\nEnter your choice : "); 
scanf("%d",&choice); 
switch(choice) 
{ 
case 1:printf("Enter the value to be inserted : "); 
scanf("%d", &info); 
if( search(root,info) == NULL ) 
root=insert(info, root, &ht_inc); 
else 
printf("Duplicate value ignored\n"); 
break; 
case 2:if(root==NULL) 
{ 
printf("Tree is empty\n"); 
continue; 
} 
printf("Tree is :\n"); 
Prabodh C P, Dept of CSE, SIT, Tumkur
printf("Inorder Traversal is: "); 
inorder(root); 
printf("\n \n"); 
break; 
case 3:exit(1); 
default:printf("Wrong choice\n"); 
} 
} 
return 0; 
} 
/******************************************************************************
*Function : search 
*Description : Function to search for a given node in a AVL tree 
*Input parameters: 
* NODEPTR pptr - pointer to root node 
* int info - element to be searched 
*RETURNS : pointer to a node 
******************************************************************************/
NODEPTR search(NODEPTR ptr,int info) 
{ 
if(ptr!=NULL) 
if(info < ptr->info) 
ptr=search(ptr->lchild,info); 
else if( info > ptr->info) 
ptr=search(ptr->rchild,info); 
return(ptr); 
} 
/******************************************************************************
*Function : insert 
*Description : Function to insert an element into a AVL tree 
*Input parameters: 
* int info - element to be inserted 
* NODEPTR pptr - pointer to parent node 
* bool *ht_inc - boolean value 
*RETURNS : pointer to a node 
******************************************************************************/
NODEPTR insert (int info, NODEPTR pptr, bool *ht_inc) 
{ 
NODEPTR aptr,bptr; 
if(pptr==NULL) 
{ 
pptr = (NODEPTR) malloc(sizeof(struct node)); 
pptr->info = info; 
pptr->lchild = NULL; 
pptr->rchild = NULL; 
pptr->balance = 0; 
*ht_inc = true; 
return (pptr); 
} 
if(info < pptr->info) 
{ 
pptr->lchild = insert(info, pptr->lchild,ht_inc); 
if(*ht_inc==true) 
{ 
switch(pptr->balance) 
{ 
case -1: /* Right heavy */ 
pptr->balance = 0; 
*ht_inc = false; 
break; 
case 0: /* Balanced */ 
Prabodh C P, Dept of CSE, SIT, Tumkur
pptr->balance = 1; 
break; 
case 1: /* Left heavy */ 
aptr = pptr->lchild; 
if(aptr->balance == 1) 
{ 
printf("\nR Rotation performed during 
Insertion\n\n"); 
pptr->lchild= aptr->rchild; 
aptr->rchild = pptr; 
pptr->balance = 0; 
aptr->balance=0; 
pptr = aptr; 
} 
else 
{ 
printf("\nLR Rotation performed during 
Insertion\n\n"); 
bptr = aptr->rchild; 
aptr->rchild = bptr->lchild; 
bptr->lchild = aptr; 
pptr->lchild = bptr->rchild; 
bptr->rchild = pptr; 
if(bptr->balance == 1 ) 
pptr->balance = -1; 
else 
pptr->balance = 0; 
if(bptr->balance == -1) 
aptr->balance = 1; 
else 
aptr->balance = 0; 
bptr->balance=0; 
pptr=bptr; 
} 
*ht_inc = false; 
} 
} 
} 
if(info > pptr->info) 
{ 
pptr->rchild = insert(info, pptr->rchild,ht_inc); 
if(*ht_inc==true) 
{ 
switch(pptr->balance) 
{ 
case 1: /* Left heavy */ 
pptr->balance = 0; 
*ht_inc = false; 
break; 
case 0: /* Balanced */ 
pptr->balance = -1; 
break; 
case -1: /* Right heavy */ 
aptr = pptr->rchild; 
if(aptr->balance == -1) 
{ 
printf("\nL Rotation performed during Insertion\n\n"); 
pptr->rchild= aptr->lchild; 
aptr->lchild = pptr; 
pptr->balance = 0; 
aptr->balance=0; 
Prabodh C P, Dept of CSE, SIT, Tumkur
pptr = aptr; 
} 
else 
{ 
printf("\nRL Rotation performed during Insertion\n\n");
bptr = aptr->lchild; 
aptr->lchild = bptr->rchild; 
bptr->rchild = aptr; 
pptr->rchild = bptr->lchild; 
bptr->lchild = pptr; 
if(bptr->balance == -1) 
pptr->balance = 1; 
else 
pptr->balance = 0; 
if(bptr->balance == 1) 
aptr->balance = -1; 
else 
aptr->balance = 0; 
bptr->balance=0; 
pptr = bptr; 
} 
*ht_inc = false; 
} 
} 
} 
return(pptr); 
} 
/******************************************************************************
*Function : inorder 
*Description : Function to display inorder traversal of AVL tree with 
* balance factor at each node 
*Input parameters: 
* NODEPTR pptr - pointer to root node 
*RETURNS : nothing 
******************************************************************************/
void inorder(NODEPTR ptr) 
{ 
if(ptr!=NULL) 
{ 
inorder(ptr->lchild); 
printf("%d(%d) ",ptr->info,ptr->balance); 
inorder(ptr->rchild); 
} 
}