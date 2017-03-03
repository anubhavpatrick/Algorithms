/*you have a set of N elements that are into further subsets and you have to track the connectivity of each element in a specific subset or connectivity of subsets with each other.

Two main operations:
Union(A,B): Connects A to B
Find(A,B): Find whether A and B are connected 

Now we will store the parent of each element i in set[i]
 
There will be some elements which wont have any parent. We will call such elements as
root. A root will be an element which is parent of itself

if 2 elements belong to the same set then eventually they will have the same parent
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
void initialize(int *set)//initially each element belong to its seperate set
{
	for(int i=0;i<LIMIT;i++)
		set[i]=i;//initially each element is its root (parent)
}
void unionOp(int *set, int A, int B)//union is a key word. Fun name needs to be different
{
		set[root(set,A)]=set[root(set,B)];//Connecting root of subset to which A belongs to root of subset to which B belongs
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
	int set[LIMIT];
	initialize(set);
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
		unionOp(set,A,B);
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

