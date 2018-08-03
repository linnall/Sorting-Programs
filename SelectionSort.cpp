/*Selection Sort
Program reads in random numbers from a text file into a vector,
uses the SelectionSort function to sort the numbers in
ascending order, calculates the average time the sort takes
and writes the sorted numbers to a text file where each number
is on a separate line.
Linna Luo, 29/05/2018*/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std; 

typedef long Type;

//FUNCTIONS
//--------------------------------------------------------------'
void SelectionSort (vector <Type> &Array)
	{
		long temp; 
		int smallest;
		
		//comparing each element (minus the last element) to all other elements after it
		for (int i=0; i<Array.size()-1; i++)
			{	
			smallest = i; //initiating the the i element as the smallest
			//finding lowest number 
			for (int j=i+1; j<Array.size(); j++)
				{
					//if a compared number in the array is smaller than current smallest number
					if (Array[smallest] > Array[j])
						//replace ltemp with the smaller number
						smallest = j; 
 				}
 				
 			//switch smallest element and initial comparison element's values 
			temp = Array[i];	
			Array[i] = Array[smallest];
			Array[smallest] = temp; 
			}
	}
//-------------------------------------------------------------------
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
	ofstream LastFile("selectionsort.txt", ios::trunc); 
	
	for (int i=0; i<10; i++) //move this to clear file each time
	{
	Num2.resize(0); //clear the copy vector with the sorted numbers 
	CopyVector (Num,Num2); 
		
	//indicating start time of sort
	clock_t start = clock();
	
	//SELECTION SORT	
	//sorting the numbers stored in Num2
	SelectionSort(Num2); 
	
	start = clock() - start; //finding difference between beginning and end time of sort to find sort time
	sum += (double)start/CLOCKS_PER_SEC; //find sort time in seconds
	trialnum++;	//increase trial number
	}
	
	DisplayAverage (LastFile, sum, trialnum); 

	DisplaySortedNumbers (LastFile, Num2); 
	
	return 0;
	}	
}
