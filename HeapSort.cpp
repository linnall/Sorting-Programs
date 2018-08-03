/*Heap Sort
Linna Luo, 01/06/2018*/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

typedef long Type; 

//FUNCTIONS
//-----------------------------------------------------------
void Heapify (vector <Type> &Array, int size, int index)
//creates max heap with given part of Array
	{
		int largest = index; //set the node as the assumed largest
		int left = index*2 + 1;
		int right = index*2 + 2;
		long temp;
		
		//check if left child node is larger
		if (left < size && Array[left]>Array[largest])
			largest = left;
			
		//check if right child node is larger
		if (right < size && Array[right]>Array[largest])
			largest = right; 
			
		//switch parent and child node if largest value has changed
		if (largest != index)
			{
				temp = Array[largest];
				Array[largest] = Array[index];
				Array[index] = temp;
				
				//check if the child nodes are larger than the new index value
				Heapify (Array, size, largest);
			}
	}
//-----------------------------------------------------------
void HeapSort (vector <Type> &Array, int size)
	{
		long temp; 
		for (int i=size/2 -1; i>=0; i--)
			Heapify(Array, size, i); //create max heap
		
		for (int j=size-1; j>=0; j--)
			{
				//swap the first and last node
				temp = Array[0];
				Array[0] = Array[j];
				Array[j] = temp; 
				
				//build max heap again with reduced heap where j is size of the heap
				Heapify(Array, j, 0); 
			}
	}
//-----------------------------------------------------------

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
	ofstream LastFile("heapsort.txt", ios::trunc); 
	
	for (int i=0; i<10; i++) //move this to clear file each time
	{
	Num2.resize(0); //clear the copy vector with the sorted numbers 
	CopyVector (Num,Num2); 
		
	//indicating start time of sort
	clock_t start = clock();
	
	//HEAP SORT	
	//sorting the numbers stored in Num2
	HeapSort(Num2, Num2.size()); 
	
	start = clock() - start; //finding difference between beginning and end time of sort to find sort time
	sum += (double)start/CLOCKS_PER_SEC; //find sort time in seconds
	trialnum++;	//increase trial number
	}
	
	DisplayAverage (LastFile, sum, trialnum); 

	DisplaySortedNumbers (LastFile, Num2); 
	
	return 0;
	}	
}
