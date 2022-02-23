/// Dual Sort
/// This program will use STL vectors to produce a sales report.
/// C++ 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

using namespace std;

void initVectors(vector<int>&, vector<int>&, vector<double>&);
void calcSales(vector<int>, vector<double>, vector<double>&);
void showOrder(vector<double>, vector<int>);
void dualSort(vector<int>&, vector<double>&);
void showTotals(vector<double>, vector<int>);

void initVectors(vector<int>& id, vector<int>& units, vector<double>& prices) {
	// Just go with ID numbers 914 - 922.
	for (int value = 914; value <= 922; value++) {
		id.push_back(value);
	}
	//Initialize units vector with data.
	units.push_back(842);
	units.push_back(416);
	units.push_back(127);
	units.push_back(514);
	units.push_back(437);
	units.push_back(269);
	units.push_back(97);
	units.push_back(492);
	units.push_back(212);

	//Initialize the prices Vector.
	prices.push_back(12.95);
	prices.push_back(14.95);
	prices.push_back(18.95);
	prices.push_back(16.95);
	prices.push_back(21.95);
	prices.push_back(31.95);
	prices.push_back(14.95);
	prices.push_back(14.95);
	prices.push_back(16.95);
}

void calcSales(vector<int> units, vector<double> prices, vector<double>& sales) {
	for (int index = 0; index < units.size(); index++) {
		sales.push_back(units[index] * prices[index]);
	}
}

void dualSort(vector<int>& id, vector<double>& sales) {
	int startScan, maxIndex, tempId, size;
	double maxValue;

	size = id.size();
	for (startScan = 0; startScan < (size - 1); startScan++) {
		maxIndex = startScan;
		maxValue = sales[startScan];
		tempId = id[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (sales[index] > maxValue) {
				maxValue = sales[index];
				tempId = id[index];
				maxIndex = index;
			}
		}
		sales[maxIndex] = sales[startScan];
		id[maxIndex] = id[startScan];
		sales[startScan] = maxValue;
		id[startScan] = tempId;
	}
}

void showOrder(vector<double> sales, vector<int> id) {
	cout << "Product Number \tSales \n";
	cout << "-----------------------------------------\n";
		for(int index = 0; index < id.size(); index++) {
			cout << id[index] << "\t\t$";
			cout << setw(8) << sales[index] << endl;
		}
	cout << endl;
}

void showTotals(vector<double> sales, vector<int> units) {
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < units.size(); index++) {
		totalUnits += units[index];
		totalSales += sales[index];
	}
	cout << "Total Units Sold: " << totalUnits << endl;
	cout << "Total Sales: " << totalSales << endl;
}
int main()
{
	vector<int> id;
	vector<int> units;
	vector<double> prices;
	vector<double> sales;

	initVectors(id, units, prices);
	calcSales(units, prices, sales);
	dualSort(id, sales);
	showOrder(sales, id);
	showTotals(sales, units);

	return 0;
}

