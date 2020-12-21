#include <iostream>
using namespace std;

int x, y;
int **board;
int size;


void record(int step, int loc[2]);

int possibilities(int loc[2]);

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
	while(step<size)
	{
		bool success = record(step,location);
		if(!success)
		{
			cout << "There is no solution" << endl;
			return 0;
		}
		step ++;
	}

	cout << "The solution is:" << endl << endl;
	//output array
	for(int i = 0;i<y;i++)
	{
		for(int j = 0;j<x;j++)
		{
			cout << board[j][i];
		}
		cout << endl;
	}
	for(int i = 0;i<x;i++)
		delete[] board[i];
	delete[] board;
	return 0;

}

bool record(int step, int loc[2])
{
	int next[16];
	int choices = possibilities(loc);
	if(choices ==0 && step < size)
		return false;
	for(int i =0;i<16;i++)
	{
		next[i]=-1;
	}
	int nextIndex=0;
	//find the possible jumps from the current location
	if(
}

//returns number of possible moves from the specified position
int possibilities(int loc[2])
{
	int num = 0;
	if(loc[1]-2>=0)
	{
		if(loc[0]-1>=0)
			num++;
		if(loc[0]+1<x)
			num++;
	}
	if(loc[1]+2<y)
	{
		if(loc[0]-1>=0)
			num++;
		if(loc[0]+1<x)
			num++;
	}
	if(loc[0]-2>=0)
	{
		if(loc[1]-1>=0)
			num++;
		if(loc[1]+1<y)
			num++;
	}
	if(loc[0]+2<x)
	{
		if(loc[1]-1>=0)
			num++;
		if(loc[1]+1<y)
			num++;
	}
	return num;
}






