/*
Title: CPE553-hw2
Author: Chenhui Yang
*/
#include <iostream>
#include <fstream>
using namespace std;

// compute the average of the elements in x and return
double average(const double x[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum / n;
}
//https://en.wikipedia.org/wiki/Standard_deviation
// divide by n not n-1, grades are not a sample, they are everyone's grades.
void stats(const double x[], int n, double& mean, double& stdev, double& max, double& min) {
	// your code goes here!!!
    double sum = 0;
    double min_num = x[0];
    double max_num = x[0];
    for (int i = 0; i < n; i++) {
        sum += x[i];
        if (x[i] < min_num) {
            min_num = x[i];
        }
        if (x[i] > max_num) {
            max_num = x[i];
        }
    }
    min = min_num;
    max = max_num;
    mean = sum / n;

    double sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += (x[i] - mean) * (x[i] - mean);
    }
    stdev = sum2 / n;
}


int main() {
	ifstream f("grades2.txt");
	double temp;
    if (! f.is_open()) {
        cout << "Error opening file"; 
        exit (1); 
    }
    // read in n from the file
    int n = 0;
    f >> n;
    double array[n];

    int index = 0;
    while (!f.eof() ) {
		f >> temp;
		cout << temp << " ";
		// add the numbers to your array
        array[index++] = temp;
    }
	cout << "the average is " << average(array, n) << '\n';
	double mean, stddev, max, min;
	stats(array, n, mean, stddev, max, min);
	cout << mean << " " << stddev << " " << max << " " << min;
    return 0;
}