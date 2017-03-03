/*N Queen is example of recursion and backtracking 
Given a chess board having N×N we need to place N queens in such a way that 
no queen is attacked by any other queen. A queen can attack horizontally, 
vertically and diagonally*/
#include <iostream>
#define LIMIT 10
#define FILLED 1
#define NOT_FILLED 0
using namespace std;
bool isAttacked(int x, int y, int board[][LIMIT], int dimension)
{
	int i,j;
	//if any cell in xth row is FILLED return true
	for(i=1;i<=dimension;i++)
	{
		if(board[x][i]==FILLED)
			return true;
	}
	//if any cell in yth col is FILLED return true
	for(i=1;i<=dimension;i++)
	{
		if(board[i][y]==FILLED)
			return true;
	}
	//if any cell in same left diagonal as board(x,y) is FILLED return true
	for(i=1;i<=dimension;i++)
	{
		for(j=1;j<=dimension;j++)
		{
			if((i-j)==(x-y)&&(board[i][j]==FILLED))
				return true;
		}
	}
	//if any cell in same right diagonal as board(x,y) is FILLED return true
	for(i=1;i<=dimension;i++)
	{
		for(j=1;j<=dimension;j++)
		{
			if((i+j)==(x+y)&&(board[i][j]==FILLED))
				return true;
		}
	}
	return false;
}
void draw(int board[][LIMIT],int N)
{
	cout<<"N="<<N<<endl;
	for(int i=1;i<=N;i++)
	{
		cout<<"|";
		for(int j=1;j<=N;j++)
		{
			if(board[i][j]==NOT_FILLED)
				cout<<"  |";
			else
				cout<<" Q"<<"|";
		}
		cout<<endl;
		for(int j=1;j<=N;j++)
		cout<<"---";
		cout<<endl;
	}
	//cout<<"*************"<<endl;
}
bool nQueens(int board[][LIMIT], int N,int dimension)//N represents num of Queens
{//In this fun we will use recursion as well as backtracking
	if(N==0)//base case
		return true;
	for(int i=1;i<=dimension;i++)
	{
		for(int j=1;j<=dimension;j++)
		{
			bool v=isAttacked(i,j,board,dimension);
			if(v==true)
				continue;
			board[i][j]=FILLED;
			if(nQueens(board,N-1,dimension))
				{
					return true;
				}
			
			board[i][j]=NOT_FILLED;//backtracking step
		}
	}
	return false;
}

int main()
{
	int board[LIMIT][LIMIT]={NOT_FILLED};//Initialize the whole board to 0
	//We will put board[i][j]=1 to indicate Queen placed at ith row jth col
	int N; //Representing initiL dimensions of board as well as number of queens
	cout<<"Enter number of queens"<<endl;
	cin>>N;
	bool v=nQueens(board,N,N);
	if(v)
	{
		cout<<"nQueens can be successfully placed"<<endl;
		cout<<"Placement of nQueens on board"<<endl;
		draw(board,N);
	}
	else
		cout<<"nQueens cannot be successfully placed"<<endl;
	return 0;
}