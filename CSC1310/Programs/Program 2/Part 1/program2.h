/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		GIVEN: program2.h
	Author: 		April Crockett & Griffin Sutton
	Last Updated:	October 8th. 2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#ifndef PROGRAM2_H
#define PROGRAM2_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
bool readFromFile(vector<T>&, string);
template <typename T>
void printVector(vector<T>&);
template <typename T>
void scramble(vector<T>&);

/********************************************************
 * Declare the function prototypes below for each sort
 * function 
 ********************************************************/
template <typename T>
void bubbleSort(vector<T>&);
template <typename T>
void mergeSort(vector<T>&, int, int);
template <typename T>
void parallelMergeSort(vector<T>&, int, int, int);
template <typename T>
void merge(vector<T>&, int, int, int);
template <typename T>
void quickSort(vector<T>&, int, int);
template <typename T>
void parallelQuickSort(vector<T>&, int, int);
template <typename T>
int partition(vector<T>&, int, int);

#endif