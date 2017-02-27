/*you have a set of N elements that are into further subsets and you have to track the connectivity of each element in a specific subset or connectivity of subsets with each other.

Two main operations:
Union(A,B): Connects A to B
Find(A,B): Find whether A and B are connected 
*/
#define LIMIT 10 //Max 10 elements can be there
#include <iostream>
void initialize(int *set)//initially each element belong to its seperate set
{
	for(int i=0;i<LIMIT;i++)
		set[i]=i;
}
void unionOp(int *set, int A, int B)//union is a key word. Fun name needs to be different
{
	int t=set[A],i;
	for(i=0;i<LIMIT;i++)
	{
		if(set[i]==t)
			set[i]=set[B];//all the elements having same set as A will now be equal to set to which B belongs
	}
}
bool findOp(int *set, int A, int B)
{
	if(set[A]==set[B])
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

