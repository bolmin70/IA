#include "stdafx.h"
#include "Sorting.h"
#include "Data.h"

using namespace std;

void Sorting::swapCells(int j) {

	swap(Data::trainingData.hours[j], Data::trainingData.hours[j + 1]);
	swap(Data::trainingData.minutes[j], Data::trainingData.minutes[j + 1]);

	swap(Data::trainingData.year[j], Data::trainingData.year[j + 1]);
	swap(Data::trainingData.month[j], Data::trainingData.month[j + 1]);
	swap(Data::trainingData.day[j], Data::trainingData.day[j + 1]);

	swap(Data::trainingData.speed[j], Data::trainingData.speed[j + 1]);
	swap(Data::trainingData.intensity[j], Data::trainingData.intensity[j + 1]);
	swap(Data::trainingData.power[j], Data::trainingData.power[j + 1]);


}


int Sorting::cellCheck() {
	for (int i = 0; i < 365; i++) {
		if (!Data::trainingData.year[i]) {
			return i;
		}

	}

}


void Sorting::bubbleSortUpPower(int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {
			if (Data::trainingData.power[j] < Data::trainingData.power[j + 1]) {
				swapCells(j);
			}
		}
	}
}
void Sorting::bubbleSortDownPower(int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {
			if (Data::trainingData.power[j] > Data::trainingData.power[j + 1]) {
				if (Data::trainingData.power[j + 1] != 0) {
					swapCells(j);
				}
			}
		}
	}
}

void Sorting::bubbleSortUpDate(int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {


			if (Data::trainingData.year[j] <= Data::trainingData.year[j + 1]) {
				if (Data::trainingData.year[j] < Data::trainingData.year[j + 1]) {
					swapCells(j);
					//return;
				}
				else {
					if (Data::trainingData.month[j] <= Data::trainingData.month[j + 1]) {
						if (Data::trainingData.month[j] < Data::trainingData.month[j + 1]) {
							swapCells(j);
							//return;
						}
						else {
							if (Data::trainingData.day[j] <= Data::trainingData.day[j + 1]) {
								if (Data::trainingData.day[j] < Data::trainingData.day[j + 1]) {
									swapCells(j);
									//return;
								}

							}

						}
					}
				}


			}



		}
	}
}
void Sorting::bubbleSortDownDate(int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {
			if (Data::trainingData.year[j] >= Data::trainingData.year[j + 1]) {
				if (Data::trainingData.year[j] > Data::trainingData.year[j + 1]) {
					swapCells(j);

				}
				else {
					if (Data::trainingData.month[j] >= Data::trainingData.month[j + 1]) {
						if (Data::trainingData.month[j] > Data::trainingData.month[j + 1]) {
							swapCells(j);

						}
						else {
							if (Data::trainingData.day[j] >= Data::trainingData.day[j + 1]) {
								if (Data::trainingData.day[j] > Data::trainingData.day[j + 1]) {
									swapCells(j);

								}

							}

						}
					}
				}


			}
		}
	}
}

