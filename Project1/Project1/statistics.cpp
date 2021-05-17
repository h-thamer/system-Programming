#include "statistics.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include<algorithm> 

/* Constructor For Player Set*/
PlayerSet::PlayerSet()
{
	name = "N/A";
	cash = 1000;
	wins = 0;
	loses = 0;
}

//   FUNCTIONS


std::string PlayerSet::getName()    // Function for returning Player's Name.
{
	return name;
}


int PlayerSet::getCash()            // Function for Returning Player's Money
{
	return cash;
}


int PlayerSet::getWins()            // Function for Returning Player's Won Status
{
	return wins;
}


int PlayerSet::getLoses()           // Function for Returning Player's Won Status
{
	return loses;
}


void PlayerSet::setValues(std::string nm, int c, int w, int l)      // Function For Player Panel
{
	name = nm;
	cash = c;
	wins = w;
	loses = l;
}






Statistics::Statistics()            // Function for Statitics Presentation of game
{
	std::fstream temp;
	temp.open("data/statistics.bin", std::ios::in | std::ios::binary);

	if (temp.fail()) {
		saveStats();
	}
	else {
		temp.close();
		loadStats();
	}
}



bool Statistics::check(Player pl)       // Function for High Scores and Saves
{
	bool rewrite = false;

	if (pl.getCash() > p[0].getCash())      // Case : Player Have more money
	{
		p[0].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
		rewrite = true;
	}
	if (pl.getWins() > p[1].getWins())      // Case : Player Have more Wins
	{
		p[1].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
		rewrite = true;
	}
	if (pl.getLoses() > p[2].getLoses())   // Case : Player Have more loses
	{
		p[2].setValues(pl.getName(), pl.getCash(), pl.getWins(), pl.getLoses());
		rewrite = true;
	}
	if (rewrite)
	{
		saveStats();
	}
	return rewrite;
}



void Statistics::print()       // Function For Statitics Printing for user preview
{
	int maxlength = std::max(std::max(p[0].getName().length(), p[1].getName().length()), p[2].getName().length());

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0: std::cout << "MAX CASH  ||||||||| "; break;
		case 1: std::cout << "MAX WINS  ||||||||| "; break;
		case 2: std::cout << "MAX LOSES ||||||||| ";
		}
		std::cout << std::setw(maxlength + 1) << p[i].getName() << "\t | \t" << lightGreen << "Cash: " << std::setw(7) << p[i].getCash() << "\t | \t" << yellow << "Wins: " << std::setw(5) << p[i].getWins() << "\t | \t" << lightRed << "Loses: " << std::setw(5) << p[i].getLoses() << def << "\n";
	}
}

//////////////* File Handling *////

void Statistics::saveStats()        // Function For Records
{
	std::fstream f1;
	f1.open("data/statistics.bin", std::ios::out | std::ios::binary);
	for (int i = 0; i < 3; i++)
	{
		std::string sName = p[i].getName();
		int nameSize = sName.size();
		int sCash = p[i].getCash();
		int sWins = p[i].getWins();
		int sLoses = p[i].getLoses();


		f1.write((char*)&nameSize, sizeof(nameSize));
		f1.write(sName.c_str(), sName.size());
		f1.write((char*)&sCash, sizeof(sCash));
		f1.write((char*)&sWins, sizeof(sWins));
		f1.write((char*)&sLoses, sizeof(sLoses));
	}
	f1.close();
}

void Statistics::loadStats()        // Function for Loading Records
{
	std::fstream f1;
	f1.open("data/statistics.bin", std::ios::in | std::ios::binary);

	for (int i = 0; i < 3; i++)
	{
		std::string sName;
		int nameSize;
		int sCash;
		int sWins;
		int sLoses;
		f1.read((char*)&nameSize, sizeof(nameSize));
		sName.resize(nameSize);
		f1.read(&sName[0], sName.size());
		f1.read((char*)&sCash, sizeof(sCash));
		f1.read((char*)&sWins, sizeof(sWins));
		f1.read((char*)&sLoses, sizeof(sLoses));
		p[i].setValues(sName, sCash, sWins, sLoses);
	}
	f1.close();
}

// STatitics.cpp ends Here