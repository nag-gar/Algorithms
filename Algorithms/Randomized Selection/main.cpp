#include <iostream>
#include <cstdlib>

using namespace std;

int randSelection (int *A , int idx , int szA)
{
	//Base Case
	if (szA <= 1)
		return A[0];
	
	int pivot;
	int pivotIDX = 0;
	int smallEnds = 0;
	int bigStarts = 0;
	
	//Choose Pivot From Mid of the list
	int mid = szA/2;
	pivot = A[mid];
	
	//Swap Pivot With First Element
	A[mid] = A[0];
	A[0] = pivot;
	
	bool swapFlag = false;
	int swapWithIdx = 1;
	
	for (int i=1;i<szA;i++)
	{
		if (!swapFlag && A[i] >= pivot)
		{
			swapFlag = true;
			swapWithIdx = i;
			bigStarts = i;
		}
		
		if (swapFlag && A[i] < pivot)
		{
			int temp = A[swapWithIdx];
			A[swapWithIdx] = A[i];
			A[i] = temp;
			smallEnds = swapWithIdx;
			bigStarts++;
			swapWithIdx = bigStarts;
		}
		
		if (!swapFlag && A[i] < pivot)
		{
			smallEnds = i;
		}
	}
	
	A[0] = A[smallEnds];
	A[smallEnds] = pivot;
	pivotIDX = smallEnds;
	
	/*cout<<"Pivot is :"<<pivot<<endl;
	
	for (int i=0;i<szA;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl<<endl;*/
	
	if (pivotIDX == idx)
		return pivot;
		
	else if (idx > pivotIDX)
	{
		int newASize = szA - pivotIDX - 1;
		int * newA = new int [newASize];
		int cnt = 0;
		int newIdx = idx - pivotIDX - 1;
		
		for (int i=pivotIDX+1;i<szA;i++)
		{
			newA[cnt] = A[i];
			cnt++;
		}
		
		return randSelection (newA , newIdx , newASize);
	}
	
	else
	{
		int newASize = pivotIDX;
		int * newA = new int [newASize];
		int newIdx = idx;
		
		for (int i=0;i<newASize;i++)
		{
			newA[i] = A[i];
		}
		
		return randSelection (newA , newIdx , newASize);
	}
}

int main()
{
	int * A = new int [11];
	A[0] = 5;
	A[1] = 2;
	A[2] = 1;
	A[3] = 0;
	A[4] = 7;
	A[5] = 9;
	A[6] = 8;
	A[7] = 6;
	A[8] = 4;
	A[9] = 3;
	
	cout<<"NUM IS : "<<randSelection(A , 6 , 10);
}
