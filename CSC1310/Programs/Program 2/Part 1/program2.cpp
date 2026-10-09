/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		program2.cpp
	Author: 		Eddie Gannod & April Crockett & Griffin Sutton
	Last Updated:	October 8th, 2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#include <iostream>
#include <vector>				// used to create and use vectors
#include <fstream>
#include <parallel/algorithm> 	// used for sort function
#include <omp.h>              	// used for OpenMP directives
#include <ctime>             	// used for seeding randome number generator
#include <thread>				//used for calculating number of logical processors on computer
#include <cstdlib>           	// used for random number generation
#include <chrono>				//used for measuring elapsed time
#include "program2.h"

using namespace std;

int main() 
{
	//create two vectors	
    vector<int> nums;       	
    vector<string> words;  		
	string filename;
	bool success;
    
	//determine number of logical processors on your computer
	const auto processor_count = thread::hardware_concurrency();
	
    //Number of threads OpenMP will use. 
    int num_threads;
	
	//ask the user for the number of threads
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;
	
	//*********************LOOK!************************************************
	//add in the code to validate the user's input
	//make sure the user entered in an integer 1 through 500 (and that they actually entered in an integer)
	while (!cin || num_threads < 1 || num_threads > 500){
		cout << "Oops! You didn't enter a valid number!\n"
			 << "Enter a number 1 - 500: ";
			 cin.clear();
		cin.ignore(1000, '\n');
		cin >> num_threads;
	}

	omp_set_dynamic(false);
    omp_set_num_threads(num_threads);
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;
	
	//read from files & place in vectors
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(wordsSmall.txt or wordsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(words, filename);	
	} while(!success);
	do {
		cout << "\nWhat is the name of the string (nums) text file?\n(numsSmall.txt or numsLarge.txt)\nFILENAME: "; //NOTE: Edited this cout statment to say (nums), says (word) without edit.
		cin >> filename;
		success = readFromFile(nums, filename);
	} while(!success);
	cout << "SIZE of words: " << words.size() << endl;
	cout << "SIZE of nums: " << nums.size() << endl;
	
	//prior to calling any of the sort algorithms, you need to scramble (unsort) the vectors
	scramble(nums);
    scramble(words);
	
	/*************************************************************************Parallel Sort in Algorithm Library*****************************
	
	 * For more information about this algorithm in particular, take a look at 
	 * https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
	 * It uses the IntroSort algorithm, which is a hybrid between Quicksort, Heapsort,
	 * and Insertion Sort.
     *********************************************************************************/
	//****************************Parallel Sort in Algorithm Library*****************************/
    auto start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(nums.begin(), nums.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "\n<parallel/algorithm> library sort(int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(words.begin(), words.end());
    end = chrono::high_resolution_clock::now();
    cout << "<parallel/algorithm> library sort(words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


    /*********************************************************************************
		BUBBLE SORT
		
		First, scramble the two vectors (call the scramble function)
		
		Start the clock
		Call the bubbleSort function here for nums vector
		Stop the clock
		Compute the runtime (see example above)
		Print out result to screen
		
		Start the clock
		Call the bubbleSort function for the words vector
		Stop the clock
		Compute the runtime
		Print out result to screen.
		
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
	bubbleSort(nums);
	end = chrono::high_resolution_clock::now();
	cout << "Bubble Sort(int): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	bubbleSort(words);
	end = chrono::high_resolution_clock::now();
	cout << "Bubble Sort(string): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		mergeSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
	mergeSort(nums, 0, nums.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Merge Sort(int): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	mergeSort(words, 0, words.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Merge Sort(string): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		PARALLEL MERGE SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelMergeSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
	parallelMergeSort(nums, 0, nums.size() - 1, 0);
	end = chrono::high_resolution_clock::now();
	cout << "Parallel Merge Sort(int): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	parallelMergeSort(words, 0, words.size() - 1, 0);
	end = chrono::high_resolution_clock::now();
	cout << "Parallel Merge Sort(string): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		QUICK SORT
		
		do all the same stuff described in bubble sort except call the 
		quicksort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
	quickSort(nums, 0, nums.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Quick Sort(int): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	quickSort(words, 0, words.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Quick Sort(string): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    /*********************************************************************************
		PARALLEL QUICK SORT
		
		do all the same stuff described in bubble sort except call the 
		parallelQuickSort function
     *********************************************************************************/
	scramble(nums);
	scramble(words);
	
	start = chrono::high_resolution_clock::now();
	parallelQuickSort(nums, 0, nums.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Parallel Quick Sort(int): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	parallelQuickSort(words, 0, words.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << "Parallel Quick Sort(string): "
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    return 0; 
}

/*********************************************************
 * HELPER FUNCTIONS
 * These functions help read in the data from the files
 * scramble the data, and print the data to the console.
 * You should not have to touch these.
 **********************************************************/

/*
	Function: readFromFile()
	Purpose: 
		readFromFile reads values from a file into a vector<T>. 
		It returns true if the file was successfully opened and 
		read, and false otherwise.
*/
template <typename T>
bool readFromFile(vector<T>& v, string filename)
{
    ifstream file;
    T tmp;
	
    file.open(filename);
	if(file.is_open())
	{
		//place file contents into vector
		while(file >> tmp)
		{
			v.push_back(tmp);
		}
		file.close();
		return true;
	}
	return false;
}

/*
	Function: printVector()
	Purpose: 
		printVector prints each element of the vector to the screen
*/
template <typename T>
void printVector(vector<T>& v)
{
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << endl;
    }
}

/*
	Function: scramble()
	Purpose: 
		scramble will randomly scramble the vector contents to
		make the vector unsorted
*/
template <typename T>
void scramble(vector<T>& v)
{
    srand(time(0));
    int randomIndex;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        randomIndex = rand() % v.size();
        swap(v[i], v[randomIndex]);
    }
}

/*************************************************
 * SORTING FUNCTIONS
 * These functions implement the sorting algorithms
 *************************************************/

// Implement all the sort algorithms below that were described in the assignment

//Bubble Sort
template <typename T>
void bubbleSort(vector <T> &v){
	T tempForSwap;
	bool swapped; //to keep track of whether a swap occurred in the inner loop
	int size;
	
	size = v.size(); //number of elements in the vector
	
	for(int i=0; i<size-1; i++){
		swapped = false;
		for(int j=0; j<size-i-1; j++){ 
			//swap the two adjacent elements if the one on the 
			//left is greater than the one on the right
			if(v[j] > v[j+1]) {
				tempForSwap = v[j];
				v[j] = v[j+1];
				v[j+1] = tempForSwap;
				swapped = true; //a swap occurred
			}
		}
		//if there were no swaps, then break
		if(!swapped)
			break; //prevents unnecessary passes through the array
	}
}

//merge Sort
template <typename T>
void mergeSort(vector <T> &v, int low, int high){
	int mid;
	
	if(low < high){ //recursive case (when low == high then that is base case)
		mid = (low + high) / 2; //find the midpoint in the partition
		
		mergeSort(v, low, mid); //recursively sort left partition
		mergeSort(v, mid + 1, high); //recursively sort right partition
		
		//merge left and right partition in sorted order
		merge(v, low, high, mid);
	}
}
//Parallel merge sort
template <typename T>
void parallelMergeSort(vector <T> &v, int left, int right, int depth){
	int mid; //middle index of the current range
	
	if(left < right){ //recursive case (when left == right, that is the base case)
		mid = (left + right) / 2; //find the midpoint to split the vector into two halves
		
		if(depth < 4){ //not too deep in the recursion tree, so allow parallelism
			#pragma omp parallel sections
			{
				#pragma omp section
				parallelMergeSort(v, left, mid, depth + 1); //left half in its own section
				
				#pragma omp section
				parallelMergeSort(v, mid + 1, right, depth + 1); //right half in its own section
			}
		}
		else{ //depth is 4 or above, so do the recursive calls without parallelizing
			parallelMergeSort(v, left, mid, depth + 1);
			parallelMergeSort(v, mid + 1, right, depth + 1);
		}
		
		//merge the two sorted halves (runs after both halves finish)
		merge(v, left, right, mid);
	}
}

//merge function for the merge sort algorithms
template <typename T>
void merge(vector <T> &v, int left, int right, int mid){
	int n1;
	int n2;
	int i;
	int j;
	int k;
	T* L;
	T* R;
	
	n1 = mid - left + 1;  // size of left half
	n2 = right - mid;     // size of right half

	// Temporary arrays
	L = new T[n1];
	R = new T[n2];

	// Copy data into temp arrays
	for (i = 0; i < n1; i++)
		L[i] = v[left + i];
	for (j = 0; j < n2; j++)
		R[j] = v[mid + 1 + j];

	// Merge the two temp arrays back into v[left...right]
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			v[k++] = L[i++];
		else
			v[k++] = R[j++];
	}

	// Copy remaining elements, if any
	while (i < n1) 
		v[k++] = L[i++];
	while (j < n2) 
		v[k++] = R[j++];

	// Free temporary memory
	delete[] L;
	delete[] R;
}

//quick sort
template <typename T>
void quickSort(vector <T> &v, int left, int right){
	int split = 0;
	
	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if(left >= right){
		return;
	}
	
	//partition the data within the vector
	split = partition(v, left, right); //returns location of last element in left partition
	quickSort(v, left, split); //recursively sort left partition
	quickSort(v, split + 1, right); //recursively sort right partition
}

//parallel quick sort
template <typename T>
void parallelQuickSort(vector <T> &v, int left, int right){
	int split = 0;
	
	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if(left >= right){
		return;
	}
	
	//partition the data within the vector (same partition function as the serial version)
	split = partition(v, left, right); //returns location of last element in left partition
	
	//only create a parallel task if the range is big enough to be worth the overhead
	#pragma omp task shared(v) if(right - left > 10000)
	parallelQuickSort(v, left, split); //recursively sort left partition
	
	#pragma omp task shared(v) if(right - left > 10000)
	parallelQuickSort(v, split + 1, right); //recursively sort right partition
}

//Partition function for the quick sort algorithms
template <typename T>
int partition(vector <T> &v, int left, int right){
	T pivot = v[left]; //pivot starts at left
	
	left--;
	right++;
	while(left < right){
		do{
			right--;
		}while(v[right] > pivot);
		
		do{
			left++;
		}while(v[left] < pivot);
		
		if(left < right){
			swap(v[left], v[right]);
		}
	}
	return right;
}