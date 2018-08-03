#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <stdbool.h>

using namespace std;

typedef long ItemType; 

//FUNCTIONS
//-----------------------------------------------------------------------
void BubbleSort (vector <ItemType> &Array, long size)
	{
		bool sort = true;
		int bignum = 0; 
		long temp; 
		
		while (sort)
		{
		sort = false; 
		bignum++; 
		for (long i=0; i<size - bignum; i++)
			{
				//if the first item is larger than the second, switch
				if (Array[i] > Array[i+1])
				{
						temp = Array[i];
						Array[i] = Array[i+1];
						Array[i+1] = temp; 
						sort = true;
				}
			}
		}
	}
//-----------------------------------------------------------------------
int main() 
{
	fstream MyFile("RandNums.txt", ios::in | ios::out); 
	fstream TryFile("testtest.txt", ios::in | ios::out); 
	
	if (MyFile.fail())	
	{
		cout << "Could not open file";
		return 0; 
	}else
	{
		//writing 10 000 random numbers between 1 - 100 000
		//seeding into clock chart????
		srand(time(NULL)); 
		long random;
		long num, index = 0; 
		string s; 
		
		for (int i=0; i<10000; i++)
		{
			random = rand()%100000 + 1; //DOUBLE CHECK THIS
			MyFile << random << endl; 
		}
		
		//putting numbers into a vector
		vector <long> Numbers(10000); 
		
		while (getline(MyFile,s) )//THIS IS NOT WORKING 
			{
				Numbers[index] = atol(s.c_str());
				index++; 
			}		
			
			cout << Numbers[500]; 
			
				//display sorted numbers
		for (long j=0; j<10000; j++)
			TryFile << Numbers[j] << endl;
			
		BubbleSort (Numbers, 10000); 
				
		return 0;
	}
}
