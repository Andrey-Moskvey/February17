#include <iostream>
#include <iomanip>
#include <chrono>
#include "arraywork.h"
#include "sorts.h"

int main() {
	bool time[6] = {true, true, true, true, true, true};
	std::cout << "\t"  << "insertion" << "\t" << "quick" << "\t" << "merge" << "\t" << "bubble" << "\t" << "selection" << "\t" << "count" << std::endl;
	int mass[61] = {100, 200, 300, 400, 500, 750, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000, 90000, 95000, 100000, 110000, 120000, 130000, 140000, 150000, 160000, 170000, 180000, 190000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 1000000};
	for (int i = 0; i < 61; i++) {
		int *ar = new int[mass[i]];
		std::cout << mass[i] << "\t";
		for (int o = 1; o < 7; o++) {
			randomFilling(ar, mass[i], 0, 999);
			if (time[o]) {
				std::chrono::time_point<std::chrono::high_resolution_clock> start;
				start = std::chrono::high_resolution_clock::now();
				switch (o) {
					case 1:
						insertionSort(ar, mass[i]);
						break;
					case 2:
						quickSort(ar, mass[i]);
						break;
					case 3:
						mergeSort(ar, mass[i]);
						break;
					case 4:
						bubbleSort(ar, mass[i]);
						break;
					case 5:
						selectionSort(ar, mass[i]);
						break;
					case 6:
						countsort(ar, mass[i]);
						break;
				}
				std::chrono::time_point<std::chrono::high_resolution_clock> end;
				end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start;
				std::cout << std::setprecision(4) << diff.count() << "\t";
				if (diff.count() > 10) time[o] = false;
			} else std::cout << "------" << "\t";
		}
		delete[] ar;
		std::cout  << std::endl;
	}
	return 0;
}
