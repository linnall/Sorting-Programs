/*Quick Sort
Linna Luo, 01/06/2018*/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <stdbool.h>
#include <ctime>
#include <stdlib.h>
#include <cstdio>

using namespace std;

typedef long Type; 

//FUNCTIONS 
//----------------------------------------------------------------------
int Partition (vector <Type> &Array, int start, int end)
	{
		//placing elements smaller than pivot before it 
		int pi = Array[end];
		int ebefore = start-1;
		int temp;
		
		for (int i=start; i<end-1; i++)
			{
				if (Array[i]<=pi)
				{
					//moving the index of the smaller numbers forward
					ebefore++;
					
					//bring all the smaller elements than pi to the front
					temp = Array[i];
					Array[ebefore] = Array[i];
					Array[i] = temp; 
				}
			}
			
			//moving pi to the correct place
			for (int j=ebefore+1; j<end; j++)
				Array[j+1] = Array[j];
			
			Array[ebefore+1] = pi; 
			
			return (ebefore+1); 
	}
//----------------------------------------------------------------------	
void QuickSort(vector <Type> &Array, int start, int end)
	{
		if (start<end)
		{
			//position of partition 
			int p = Partition(Array, start, end);
		
			//part before partition
			QuickSort(Array, start, p-1);
			QuickSort(Array, p+1, end); 
		}
	}
//----------------------------------------------------------------------	
int main() 
{
		vector <long> Num;
	long n;
	int i = 0; 
	
	//closing the output stream and opening an input stream
	//MyFile.close();
	ifstream NewFile ("rando.txt");
	
	if (NewFile.fail())
	{
		cout << "File could not be opened";
		return 0;
	}else
	{

	//entering numbers from testtest.txt into a vector
	while (NewFile >> n)
		{
			Num.resize(Num.size()+1); 
			Num[i] = n;
			i++; 
		}
	
	//closing the input stream and opening an output stream and clearing text file
	NewFile.close();
	ofstream LastFile("quicksort.txt", ios::trunc); 
	
	//testing partition 
	int p = Partition(Num, 0, Num.size()-1); 
	
	cout << p; 
	
	return 0;
	}
}
