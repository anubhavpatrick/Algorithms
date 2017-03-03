/*you have a set of N elements that are into further subsets and you have to track the connectivity of each element in a specific subset or connectivity of subsets with each other.

Two main operations:
Union(A,B): Connects A to B
Find(A,B): Find whether A and B are connected 

Now we will store the parent of each element i in set[i]
 
There will be some elements which wont have any parent. We will call such elements as
root. A root will be an element which is parent of itself

if 2 elements belong to the same set then eventually they will have the same parent

Now we further enhance the approach so as to reduce time req for search which in worst case can be O(n)

This can only be done when the tree formed during union is balanced

We will use one more array size to track the size of each element with the help of array set
*/
#define LIMIT 10 //Max 10 elements can be there
#include <iostream>
int root(int *set,int A)
{
	while(set[A]!=A)
	{
		A=set[A];
	}
	return A;
}
void initialize(int *set,int *size)//initially each element belong to its seperate set
{
	for(int i=0;i<LIMIT;i++)
	{	set[i]=i;//initially each element is its root (parent)
		size[i]=1;//initially size of each element is 0
	}
}
void unionOp(int *set,int *size, int A, int B)//union is a key word. Fun name needs to be different
{
	int root_A=root(A);//finding root of subset of A
	int root_B=root(B);//finding root of subset of B
	int size_A=size[root_A];//size of subset of A
	int size_B=size[root_B];//size of subset of B
	if(size_A<=size_B)
	{
		set[root_A]=set[root_B];
		size[root_B]+=size[root_A];
	}
	else
	{
		set[root_B]=set[root_A];
		size[root_A]+=size[root_B];
	}
}
bool findOp(int *set, int A, int B)
{
	if(root(set,A)==root(set,B))
		return true;
	return false;
}
using namespace std;
int main()
{
	int set[LIMIT],size[LIMIT];
	initialize(set,size);
	//Initially each element is connected to itself so there are N sets
	int A,B,i;
	char choice;
	bool sameSet;
	//setay A will store connectivity
	//If A (element 0) is connected to B (element 1) then a[0]=1,a[1]=1 
	do
	{
		cout<<"Enter the first element connected to the second element (A->B)"<<endl;
		cin>>A>>B;
		unionOp(set,size,A,B);
		cout<<"Do you want add more connectivity(Y)?"<<endl;
		cin.ignore(32767,'\n');
		cin>>choice;
	}while(choice=='Y'||choice=='y');
	do
	{
		cout<<"\nEnter two elements to check their set membership\n";
		cin>>A>>B;
		sameSet=findOp(set,A,B);
		if(sameSet)
			cout<<A<<" and "<<B<<" belong to same set\n";
		else
			cout<<A<<" and "<<B<<" does not belong to same set\n";
		cout<<"Do you want check more membership(Y)?"<<endl;
		cin.ignore(32767,'\n');
		cin>>choice;
	}while(choice=='Y'||choice=='y');
	return 0;
}

