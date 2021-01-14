/*
CSCI 580 Algorithm Design, Analysis, and Implementation
Find the Peak Value and Its Index
Author: Chu-An Tsai
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Divide and Conquer algorithm for finding the peak index
int findMaxIndex(int* array, int length)
{
    // IF the array contains only one element, the peak is itself
    if (length == 1)
    {
        return 0;
    }

    // Divide the array to half
    int splitPoint = length / 2;

    // Recursion
    int leftArray = findMaxIndex(array, splitPoint);
    int rightArray = findMaxIndex(array + splitPoint, length - splitPoint);

    // Comparison 
    if (array[leftArray] > array[rightArray + splitPoint])
    {
        return leftArray;
    }
    else
    {
        return rightArray + splitPoint;
    }
}

int main()
{
    // Read data from file
    ifstream dataFile;
    dataFile.open("peak.txt");
    int arrayA[32];
    int count = 0;

    // Give a warning and exit if fail to read the file
    if (dataFile.fail())
    {
        cout << "Unable to find input file!";  
        exit(1); 
    }

    // Write the data into arrayA
    int temp;
    while (dataFile >> temp)
    {
        arrayA[count] = temp;
        count++;
    }

    dataFile.close();

    // Apply the divide and conquer algorithm
    int maxIndex = findMaxIndex(arrayA, count + 1);

    // Print out the result
    cout << "The array contains " << count << " number(s) in the following sequence:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arrayA[i] << " ";
    }
    cout << endl;
    cout << "The peak index is " << maxIndex << ", and the peak value is " << arrayA[maxIndex] << "." << endl;

    return 0;
}
