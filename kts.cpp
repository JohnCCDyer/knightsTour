#include <iostream>
using namespace std;

//initialize global values
int x, y;
int **board;
int size;


bool record(int step, int loc[2]);

int possibilities(int loc[2]);

void print();

int main(int argc, char * argv[])
{
	if(argc != 1)
	{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	}
	else
	{
		cout << "Enter x dimension: ";
		cin >> x;
		cout << "Enter y dimension: ";
		cin >> y;
	}
	//create board according to specifications
	board = new int*[x];
	for(int i = 0;i<x;i++)
		board[i] = new int[y];
	for(int i = 0;i<y;i++)
	{
		for(int j = 0;j<x;j++)
		{
			board[j][i]=-1;
		}
	}
	size = x * y;	
	int location[2]={0,0};
	int step = 0;

	//record the solution onto the created board
	while(step<size-1)
	{
		bool success = record(step,location);
		if(!success)
		{
			cout << "There is no solution" << endl;
			return 0;
		}
		step ++;
	}
	
	board[location[0]][location[1]]=step;
	cout << "The solution is:" << endl << endl;
	//output array and clean array
	print();
	for(int i = 0;i<x;i++)
		delete[] board[i];
	delete[] board;
	return 0;

}

bool record(int step, int loc[2])
{
	int next[16];
	int choices = possibilities(loc);
	if(choices ==0 && step < size-1)
		return false;
	int nextIndex=0;
	int xtemp = loc[0];
	int ytemp = loc[1];
	//find the possible jumps from the current location
	if(loc[1]-2>=0)
	{
		if(loc[0]-1>=0&&board[xtemp-1][ytemp-2]==-1)
		{
			next[nextIndex]=loc[0]-1;
			next[nextIndex+1]=loc[1]-2;
			nextIndex+=2;
		}
		if(loc[0]+1<x&&board[xtemp+1][ytemp-2]==-1)
		{
			next[nextIndex]=loc[0]+1;
			next[nextIndex+1]=loc[1]-2;
			nextIndex+=2;
		}
	}
	if(loc[1]+2<y)
	{
		if(loc[0]-1>=0&&board[xtemp-1][ytemp+2]==-1)
		{
			next[nextIndex]=loc[0]-1;
			next[nextIndex+1]=loc[1]+2;
			nextIndex+=2;
		}
		if(loc[0]+1<x&&board[xtemp+1][ytemp+2]==-1)
		{
			next[nextIndex]=loc[0]+1;
			next[nextIndex+1]=loc[1]+2;
			nextIndex+=2;
		}
	}
	if(loc[0]-2>=0)
	{
		if(loc[1]-1>=0&&board[xtemp-2][ytemp-1]==-1)
		{
			next[nextIndex]=loc[0]-2;
			next[nextIndex+1]=loc[1]-1;
			nextIndex+=2;
		}
		if(loc[1]+1<y&&board[xtemp-2][ytemp+1]==-1)
		{
			next[nextIndex]=loc[0]-2;
			next[nextIndex+1]=loc[1]+1;
			nextIndex+=2;
		}
	}
	if(loc[0]+2<x)
	{
		if(loc[1]-1>=0&&board[xtemp+2][ytemp-1]==-1)
		{
			next[nextIndex]=loc[0]+2;
			next[nextIndex+1]=loc[1]-1;
			nextIndex+=2;
		}
		if(loc[1]+1<y&&board[xtemp+2][ytemp+1]==-1)
		{
			next[nextIndex]=loc[0]+2;
			next[nextIndex+1]=loc[1]+1;
			nextIndex+=2;
		}
	}
	//initialize important comparison values
	int lowest = 9;
	int lowestIndex=0;
	nextIndex=0;
	int testPlace[2];
	while(nextIndex<choices*2)
	{
		testPlace[0]=next[nextIndex];
		testPlace[1]=next[nextIndex+1];
		nextIndex+=2;
		int curVal=possibilities(testPlace);
		//if the possible jumps is 1, then it's a clear shot
		if(curVal==1)
		{
			board[loc[0]][loc[1]]=step;
			loc[0]=testPlace[0];
			loc[1]=testPlace[1];
			return true;
		}
		if(curVal<lowest)
		{
			lowest=curVal;
			lowestIndex=nextIndex-2;
		}
	}
	board[loc[0]][loc[1]]=step;
	loc[0]=next[lowestIndex];
	loc[1]=next[lowestIndex+1];
	return true;
}

//returns number of possible moves from the specified position
int possibilities(int loc[2])
{
	int num = 0;
	int xtemp = loc[0];
	int ytemp = loc[1];
	if(loc[1]-2>=0)
	{
		if(loc[0]-1>=0&&board[xtemp-1][ytemp-2]==-1)
			num++;
		if(loc[0]+1<x&&board[xtemp+1][ytemp-2]==-1)
			num++;
	}
	if(loc[1]+2<y)
	{
		if(loc[0]-1>=0&&board[xtemp-1][ytemp+2]==-1)
			num++;
		if(loc[0]+1<x&&board[xtemp+1][ytemp+2]==-1)
			num++;
	}
	if(loc[0]-2>=0)
	{
		if(loc[1]-1>=0&&board[xtemp-2][ytemp-1]==-1)
			num++;
		if(loc[1]+1<y&&board[xtemp-2][ytemp+1]==-1)
			num++;
	}
	if(loc[0]+2<x)
	{
		if(loc[1]-1>=0&&board[xtemp+2][ytemp-1]==-1)
			num++;
		if(loc[1]+1<y&&board[xtemp+2][ytemp+1]==-1)
			num++;
	}
	return num;
}
//prints the array. 
//*******ADD IN FORMATTING FOR READABILITY*********
void print()
{
	for(int i = 0;i<y;i++)
	{
		for(int j = 0;j<x;j++)
		{
			cout << board[j][i];
			if(j!=x-1)
				cout << ",";
		}
		cout << endl;
	}
}




