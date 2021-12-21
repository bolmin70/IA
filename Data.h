#pragma once
class Data
{
public:
	static struct userInputs {
		int distance[365];

		int hours[365];
		int minutes[365];

		int year[365];
		int month[365];
		int day[365];

		int speed[365];
		int power[365];
		int intensity[365];
	};

	static userInputs trainingData;

	static void Save();
	static void Load();
	static void randomInputs(int cells);
};

