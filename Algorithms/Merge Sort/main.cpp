#include <iostream>
#include <cstdlib>

using namespace std;

int* merge_sort(int *L , int* R , int Lsz , int Rsz)
{
	bool ihavenotfinishedyet = true;
	int cntL = 0,cntR = 0,cntRES = 0;
	int *result = new int [Lsz+Rsz];
	
	while (ihavenotfinishedyet)
	{
		//blah blah blah (NOT KE$hA Song)
		if (L[cntL] < R[cntR])
		{
			result[cntRES] = L[cntL];
			cntRES++;
			cntL++;
		}
		
		else
		{
			result[cntRES] = R[cntR];
			cntRES++;
			cntR++;
		}
		
		if (cntL == Lsz || cntR == Rsz)
		{
			ihavenotfinishedyet = false;
			if (cntL != Lsz)
			{
				for (int i=cntL;i<Lsz;i++)
				{
					result[cntRES] = L[i];
					cntRES++;
				}
			}
			
			else if (cntR != Rsz)
			{
				for (int i=cntR;i<Rsz;i++)
				{
					result[cntRES] = R[i];
					cntRES++;
				}
			}
		}
	}
	
	return result;
}

int* merge (int* A , int sz)
{
	if (sz == 1)
		return A;
	
	int mid = sz/2;
	int *L = new int[mid];
	int *R = new int[sz-mid];
	int *result;
	int counterR = 0;
	
	for (int i=0;i<mid;i++)
	{
		L[i] = A[i];
	}
	
	for (int i=mid;i<sz;i++)
	{
		R[counterR] = A[i];
		counterR++;
	}
	
	L = merge(L , mid);
	R = merge(R , sz-mid);
	result = merge_sort(L,R,mid,sz-mid);
	
	return result;
}

int main ()
{
	int *A = new int [8];
	A[0] = 5;
	A[1] = 1;
	A[2] = 9;
	A[3] = 6;
	A[4] = 0;
	A[5] = 8;
	A[6] = 4;
	A[7] = 2;
	
	A = merge(A , 8);
	
	for (int i=0;i<8;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	system("PAUSE");
	return 0;
}
