/*
 * Dolunay Dagci
 * Assignment: Random List 12-14
 * This program creates a list of integers of size the user chooses. The list consists of random numbers. The random numbers are assigned in a loop via iterator,
 * and then copied to the output screen.
 * This program does few calculation of this list of numbers. There is sum, average, median, and range of the list.
 * These values are finally printed in the output to user. 
 */
#include<iostream>
#include<iterator>
#include<algorithm>
#include <list>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	int size, sum = 0; //inital sum is 0
	double average, median, range; 
	cout << "how many elements would you like in a list?" << endl; //prompt the user for size
	cin >> size;
	
	list<int> ls; //list
	list<int>::iterator it; //iterator
	ostream_iterator<int> osit(cout, "\n"); //ostream iterator
	
	srand(time(NULL)); //for random numbers
	for (int i = 0; i < size; i++)
	{
		ls.push_back((rand() % 150 + 1)); //assign random numbers between 1-150
	}
	ls.sort(); //sort
	ls.reverse(); //put in descending order
	cout << "Elements:\n"; 
	copy(ls.begin(), ls.end(), osit); //print elements in the list

	it = ls.begin(); //iterator starts from beginning
	
	//sum
	while (it != ls.end()) 
	{
		sum += *it; //add every element
		it++; //go to next element
	}
	
	//mean
	average = sum / size; //calculate the average
	
	//median
	it = ls.begin();
	 // size is even
	if (ls.size() % 2 == 0) {
		for (int i = 0; i < ls.size() / 2; i++) {
			it++;
		}

		median = ((double)*it + *--it) / 2;
	}
	// size is odd
	else {
		for (int i = 0; i < ls.size() / 2; i++) {
			it++;
		}

		median = *it;
	}
	
	//range
	range = ls.front() - ls.back();
	
	cout << "sum: " << sum << endl << "mean: " << setprecision(3) << fixed << average << endl << "median: " << setprecision(0) << median << endl << "range: " << range << endl;
	
}

