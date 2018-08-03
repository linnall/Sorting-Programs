/*Merge Sort
Program reads in random numbers from a text file into a vector,
uses the MergeSort function to sort the numbers in
ascending order, calculates the average time the sort takes
and writes the sorted numbers to a text file where each number
is on a separate line.
Linna Luo, 29/05/2018*/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

typedef long Type;

//FUNCTIONS 
//-------------------------------------------------------------------------------
void Merge (vector <Type> &Array, int start, int mid, int end)
/*Sorts two halves within Array
Pre: two halves are sorted*/
	{
		//temporary vector 
		vector <Type> Temp(Array.size()); 
		//declaring the indicators at the beginning of each part of the vector and index number for Temp
		int p1 = start, p2 = mid+1, tempindex = start; 
		
		//Comparing elements in two halves of vector 
		while(!(p1>mid && p2>end)) 
		{ 
	//checks if two parts are still being compared and the p1 value is smaller, OR all of the second part has been depleted
			if ((Array[p1] < Array[p2] && p1<=mid) || p2>end) 
			{
				//save the smaller element into the temporary vector
				Temp[tempindex] = Array[p1]; 
				//move on to next element in first part to compare
				p1++; 
			}else
			{
				//save the smaller element into the temporary vector
				Temp[tempindex] = Array[p2]; 
				//move on to next element in second part to compare
				p2++; 
			}
			//move to the next position in the temporary vector
			tempindex++; 
		}
		
		//copying sorted array to original
		for (int i=start; i<=end; i++)
			Array[i] = Temp[i];
			
	}
//-------------------------------------------------------------------------------
void MergeSort (vector <Type> &Array, int start, int end)
	{
		if (start<end) //if only one element being entered into the function, stop recursive call of function
			{
				int mid = (start+end)/2;
				MergeSort (Array, start, mid); //continue to "half" the first part of the vector
				MergeSort (Array, mid+1, end); //continue to "half" the second part of the vector
				Merge (Array, start, mid, end); //sort the two indicated parts of the vector together 
			}
	}
//-------------------------------------------------------------------------------
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
	ofstream LastFile("mergesort.txt", ios::trunc); 
	
	for (int i=0; i<10; i++) //move this to clear file each time
	{
	Num2.resize(0); //clear the copy vector with the sorted numbers 
	CopyVector (Num,Num2); 
		
	//indicating start time of sort
	clock_t start = clock();
	
	//MERGE SORT	
	//sorting the numbers stored in Num2
	MergeSort (Num2, 0, Num2.size()-1); 
	
	start = clock() - start; //finding difference between beginning and end time of sort to find sort time
	sum += (double)start/CLOCKS_PER_SEC; //find sort time in seconds
	trialnum++;	//increase trial number
	}
	
	DisplayAverage (LastFile, sum, trialnum); 

	DisplaySortedNumbers (LastFile, Num2); 
	
	return 0;
	}	
}
