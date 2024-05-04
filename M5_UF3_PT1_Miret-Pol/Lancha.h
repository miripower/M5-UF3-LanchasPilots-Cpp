#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <string>

class Lancha
{
private:
	int speed;
	int distance;
	int nitro;
	std::string name;

public:
	//Getters:
	int getDistance();
	int getSpeed();
	int getNitro();
	std::string getName();

	//Setters:
	void setSpeed(int pSpeed);
	void setDistance(int pDistance);
	void setNitro(int pNitro);
	void setName(std::string pName);

	//Constructor:
	Lancha();
	Lancha(int pSpeed, int pDistane, int pNitro, std::string pName);

	//Metodos:
	void getParameters();
	void throwDice();
	void useNitro();
	void calculateDistance();
	void gameMenu();
	static void initScreen();
};