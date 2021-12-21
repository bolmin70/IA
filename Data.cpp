#include "stdafx.h"
#include "Data.h"

using namespace std;


Data::userInputs Data::trainingData;


void Data::Save()
{
	ofstream SaveFile;
	SaveFile.open("IA.dat", std::ofstream::trunc);


	for (int i = 0; i < 365; i++) {
		if (!trainingData.distance[i]) {
			return;
		}
		SaveFile << trainingData.distance[i] << " " << trainingData.hours[i] << " " << trainingData.minutes[i]
			<< " " << trainingData.year[i] << " " << trainingData.month[i] << " " << trainingData.day[i]
			<< " " << trainingData.speed[i] << " " << trainingData.power[i] << " " << trainingData.intensity[i] << " ";

	}

	SaveFile.close();
}

void Data::Load()
{

	ifstream LoadFile;
	LoadFile.open("IA.dat", std::ofstream::in);

	for (int i = 0; i < 365; i++) {



		LoadFile >> trainingData.distance[i] >> trainingData.hours[i] >> trainingData.minutes[i]
			>> trainingData.year[i] >> trainingData.month[i] >> trainingData.day[i]
			>> trainingData.speed[i] >> trainingData.power[i] >> trainingData.intensity[i];

		if (!trainingData.distance[i]) {
			return;
		}

	}

	LoadFile.close();
}

void Data::randomInputs(int cells) {
	srand(NULL);

	for (int i = 0; i <= cells; i++) {
		stringstream submitStream;

		submitStream << rand() % 99;
		submitStream >> trainingData.distance[i];
		submitStream.clear();

		submitStream << rand() % 99;
		submitStream >> trainingData.speed[i];
		submitStream.clear();

		submitStream << rand() % 99;
		submitStream >> trainingData.power[i];
		submitStream.clear();

		submitStream << rand() % 99;
		submitStream >> trainingData.intensity[i];
		submitStream.clear();


		submitStream << rand() % 24;
		submitStream >> trainingData.hours[i];
		submitStream.clear();

		submitStream << rand() % 60;
		submitStream >> trainingData.minutes[i];
		submitStream.clear();


		submitStream << rand() % 31 + 1;
		submitStream >> trainingData.day[i];
		submitStream.clear();

		submitStream << rand() % 12 + 1;
		submitStream >> trainingData.month[i];
		submitStream.clear();

		submitStream << rand() % 99 + 1;
		submitStream >> trainingData.year[i];
		submitStream.clear();


	}
}


