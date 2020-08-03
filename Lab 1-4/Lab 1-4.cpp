// Lab 1-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//add vector
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
//show max of element
void maxofelement(vector<int>V, int& max, int& value);
//pushback to vector

//calculate sum
void sumofelement(vector<int>V, int& sum);
//find high value
void highvalue(vector<int>V);
//find low value
void lowvalue(vector<int>V);
//find mean
void findmean(vector<int>V, int& sum, int& max, int& mean);
//find median
void median(vector<int>V, int& max);
//find mode
void mode(vector<int>V, int& max);
//find sd
void calculateSD(vector<int>V, int& max, int& mean);
//find num of even
void even(vector<int>V);
//find num of odd
void odd(vector<int>V);
//show number low to high
void show_lowtohigh(vector<int>V, int& max);

int main() {

	int max;
	int value;
	int sum = 0;
	int mean = 0;
	vector<int>V;

	maxofelement(V, max, value);


	for (int i = 0; i < max; i++) {
		value = rand() % 101;
		V.push_back(value);

	}


	sumofelement(V, sum);
	highvalue(V);
	lowvalue(V);
	findmean(V, sum, max, mean);
	median(V, max);
	mode(V, max);
	calculateSD(V, max, mean);
	even(V);
	odd(V);
	show_lowtohigh(V, max);


	system("pause");
	return 0;
}

void maxofelement(vector<int>V, int& max, int& value) {//big O is O(N)
	//random max
	srand(time(0));
	max = rand() % 101 + 50;

	cout << "Max of element : " << max << endl;

}



void sumofelement(vector<int>V, int& sum) {//big O is O(N)
	//sum ++
	for (int i = 0; i < V.size(); i++) {
		sum = sum + V[i];

	}
	cout << "Sum of element is : " << sum << endl;

}

void highvalue(vector<int>V) { //big O is O(N)
	//find high
	int high = 0;
	for (int i = 0; i < V.size(); i++) {

		if (V[i] > high) {
			high = V[i];
		}

	}
	cout << "Highest of vaule : " << high << endl;

}

void lowvalue(vector<int>V) {//big O is O(N)
	//find low
	int low = 0;
	low = V[0];
	for (int i = 0; i < V.size(); i++) {


		if (V[i] < low) {
			low = V[i];
		}

	}
	cout << "Lowest of vaule : " << low << endl;
}

void findmean(vector<int>V, int& sum, int& max, int& mean) {//big O is O(1)
	//find mean

	mean = sum / max;

	cout << "Mean is : " << mean << endl;
}

void even(vector<int>V) {//big O is O(N)
	//find even
	int even = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] % 2 == 0) {
			even++;
		}

	}
	cout << "Even number is : " << even << endl;

}

void odd(vector<int>V) {//big O is O(N)
	//find odd
	int odd = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] % 2 == 1) {
			odd++;
		}

	}
	cout << "odd number is : " << odd << endl;

}

void show_lowtohigh(vector<int>V, int& max) {//big O is O(N^2)
	//sort low - high
	int temp = 0;

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max - 1; j++) {

			if (V[j] >= V[j + 1]) {
				temp = V[j + 1];
				V[j + 1] = V[j];
				V[j] = temp;
			}

		}


	}

	cout << "Max is : " << max << endl;
	cout << "Show low to high : " << endl;
	//display number
	for (int i = 0; i < max; i++) {
		cout << V[i] << " ";

	}


}

void median(vector<int>V, int& max) {//big O is O(N^2)
	int temp = 0;
	int median = 0;
	//first sort low-high
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max - 1; j++) {

			if (V[j] >= V[j + 1]) {
				temp = V[j + 1];
				V[j + 1] = V[j];
				V[j] = temp;
			}

		}
	}
	//if max is even number
	//median = 2 number of central plus and divine 2
	if (max / 2 == 0) {
		median = (V[max / 2] + V[(max / 2) + 1]) / 2;

	}
	//if max is even odd
	//median = number of central
	else {
		median = V[(max / 2) + 1];
	}
	cout << "Median is : " << median << endl;

}

void mode(vector<int>V, int& max) {//big O is O(N^2)

	int temp = 0;
	//first sort low-high
	//big O is O(N^2)
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max - 1; j++) {

			if (V[j] >= V[j + 1]) {
				temp = V[j + 1];
				V[j + 1] = V[j];
				V[j] = temp;
			}

		}
	}

	int number = V[0];
	int mode = number;
	int count = 1;
	int countMode = 1;
	//big O is O(N)
	for (int i = 1; i < max; i++)
	{
		if (V[i] == number)
		{
			count++;
		}
		else
		{
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1;
			number = V[i];
		}
	}

	cout << "mode : " << mode << endl;
}

void calculateSD(vector<int>V, int& max, int& mean) {//big O is O(N)

	double sd = 0;

	for (int i = 0; i < max; i++) {
		sd = sd + pow(V[i] - mean, 2);
	}
	sd = sqrt(sd / max - 1);

	cout << "SD is : " << sd << endl;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
