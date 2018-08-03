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
		int ebefore = start-1; //position of number of elements smaller than pivot value
		long temp;
		
		//compare every element to partition value 
		for (int i=start; i<end; i++)
			{
				if (Array[i]<=pi)
				{
					//moving the index of the smaller numbers forward
					ebefore++;
					
					//switch positions of current of i element and element closest to begining of vector
					temp = Array[ebefore];
					Array[ebefore] = Array[i];
					Array[i] = temp; 
				}
			}
			
			//moving pi element value to position splitting elements that are larger and smaller than it
			temp = Array[ebefore+1];
			Array[ebefore+1] = Array[end];
			Array[end] = temp; 
			
			return (ebefore+1); 
	}
//----------------------------------------------------------------------	
void QuickSort(vector <Type> &Array, int start, int end)
	{
		if (start<end) //if only one element is being entered into function, stop recursive call of function
		{
			//position of initial partition 
			int p = Partition(Array, start, end);
		
			QuickSort(Array, start, p-1); //continues to partition part before p
			QuickSort(Array, p+1, end); //continues to partition part after p
		}
	}
//----------------------------------------------------------------------	
istream & ReadFile (istream &MyFile, vector <long> &Array, int n, int index)
//reads 10000 numbers into a vector
	{
		//entering numbers from testtest.txt into a vector
		while (MyFile >> n)
		{
			Array.resize(Array.size()+1); 
			Array[index] = n;
			index++; 
		}
	}
//-------------------------------------------------------------------
void CopyVector (const vector <long> Original, vector <long> &Copy)
	{
		for (int k=0; k<10000; k++)
		{
		Copy.resize(Copy.size()+1); 
		Copy[k]=Original[k];
		}
		}
//-------------------------------------------------------------------
ostream & DisplayAverage (ostream &OutFile, double &sum, int& trialnum)
	{
		//display average time the sort took
		OutFile << "On average the sort took "<< sum/trialnum << endl;
		OutFile << endl;
	}
//-------------------------------------------------------------------
ofstream & DisplaySortedNumbers (ostream &OutFile, vector <long> &Copy)
	{
		//writing to LastFile the sorted numbers
		for (int j=0; j<10000; j++)
		{
		OutFile << Copy[j] << endl; 
		}
	}
//-------------------------------------------------------------------
int main() 
{	
	vector <long> Num; //holds randomized numbers
	vector <long> Num2; //will hold sorted numbers
	long n;
	int index = 0, trialnum = 0; 
	double sum = 0;
	ifstream NewFile ("rando.txt");
	
	if (NewFile.fail())	//check if file can be read
	{
		cout << "File could not be opened";
		return 0;
	}else
	{
	ReadFile (NewFile, Num, n, index); //reading random numbers from text file to vector Num
	//closing the input stream and opening an output stream and clearing text file
	NewFile.close();
	ofstream LastFile("quicksort.txt", ios::trunc); 
	
	for (int i=0; i<10; i++) //move this to clear file each time
	{
	Num2.resize(0); //clear the copy vector with the sorted numbers 
	CopyVector (Num,Num2); 
		
	//indicating start time of sort
	clock_t start = clock();
	
	//QUICK SORT	
	//sorting the numbers stored in Num2
	QuickSort(Num2, 0, Num2.size()-1); 
	
	start = clock() - start; //finding difference between beginning and end time of sort to find sort time
	sum += (double)start/CLOCKS_PER_SEC; //find sort time in seconds
	trialnum++;	//increase trial number
	}
	
	DisplayAverage (LastFile, sum, trialnum); 

	DisplaySortedNumbers (LastFile, Num2); 
	
	return 0;
	}	
}


