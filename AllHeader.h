#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using namespace sf;

inline float lenght(Vector2f vec)
{
	return sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
}

inline Vector2f nomalize(Vector2f vec)
{
	float len = lenght(vec);
	if (len != 0)
		return vec / len;
	return vec;
}

inline int randint(int start, int stop)
{
	return rand() % (stop - start + 1) + start;
}

extern float multiplier;

extern int runScene;
#define MenuScene 0
#define GameScene 1
#define ScoreScene 2

inline void setScene(int scene)
{
	runScene = scene;
}

extern vector<Event> textEvents;

struct ScoreData
{
	string name;
	int score;
};

extern ScoreData scoreData[6];

inline void sortScore()
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = i + 1; j < 6; j++)
		{
			if (scoreData[j].score > scoreData[i].score)
			{
				ScoreData temp = scoreData[i];
				scoreData[i] = scoreData[j];
				scoreData[j] = temp;
			}
		}
	}
}

inline void readScore()
{
	fstream file("score.txt", ios::app | ios::in);
	for (size_t i = 0; i < 5; i++)
	{
		string tempName, tempScore;
		if (!getline(file, tempName))
		{
			return;
		}
		if (!getline(file, tempScore))
		{
			return;
		}
		scoreData[i].name = tempName;
		scoreData[i].score = stoi(tempScore);
	}
	file.close();
	sortScore();
}

inline void writeScore(string name, int score)
{
	fstream file("score.txt", ios::out | ios::in);
	scoreData[5].name = name;
	scoreData[5].score = score;
	sortScore();
	for (size_t i = 0; i < 5; i++)
	{
		file << scoreData[i].name << endl << scoreData[i].score << endl;
	}
	file.close();
}