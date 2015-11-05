#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <io.h>
#include <thread>
#include <process.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "ShellAPI.h"
#include <Windef.h>
#include <stdlib.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

using namespace std;
HWND hwnd;


class SearchManager {
public:
	void CreateIndex(){
		int position = 0; //keep track of array position where new character from file will be stored
		ifstream fin("data.txt", ifstream::binary);
		if (fin.is_open())
		{
				while (!fin.eof())
				{
					if (fin.get() == '\n') {
						cout << to_string(position)<<" ";
					}
					position++;
				}
		}
		else //file could not be opened
		{
			cout << "File could not be opened." << endl;
		}
	}

	void Statistic(int CountOfDaemons) {
		if (CountOfDaemons == 0) {
			cout << "Total Daemons: " << CountOfDaemons << endl;
		}
		else {
			cout << "Total Daemons: " << CountOfDaemons << endl;
			string line;
			string FileName;
			for (int i = 0; i < CountOfDaemons;i++) {
				FileName = "DaemonFile" + to_string(i) + ".txt";
				ifstream myfile(FileName.c_str());
				if (myfile.is_open())
				{
					while (!myfile.eof())
					{
						getline(myfile, line);
						cout << "Daemon "<<i << " progress: "<< atof((line).c_str()) *100 <<"%" << endl;
					}
					myfile.close();
				}

				else cout << "Unable to open file";
			}
		}
	}

	void MenuSelect(char *folder, string SearchRange,int &CountOfDaemons) {
		cout << endl << "1) New SeachDaemon" << endl;
		cout << "2) New SeachDaemon with Name" << endl;
		cout << "3) Show progress" << endl;
		cout << "4) Show History" << endl;
		cout << "5) Create Index" << endl;
		cout << "6) Exit" << endl;
		int s;
		std::cin >> s;
		system("cls");
		switch (s)
		{
		case 1:SearchR(folder, SearchRange, CountOfDaemons);  break;
		case 2:SearchR2(folder, SearchRange, CountOfDaemons); break;
		case 3:
			Statistic(CountOfDaemons);
			break;
		case 4:History(); break;
		case 5:
			CreateIndex();
			break;
		case 6:for (int i = 0; i < CountOfDaemons; i++) {
				//string RemoveNames = "DaemonFile" + to_string(i) + ".txt";
				if (remove(("DaemonFile" + to_string(i) + ".txt").c_str()) != 0);
			}
			exit(0); break;
		default:exit(0);
			break;
		}
		MenuSelect(folder, SearchRange, CountOfDaemons);
	}

	void History() {
		string line;
		ifstream myfile("History.txt");
		cout << "History: ";
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				cout << line<<endl;
				getline(myfile, line);
			}
			myfile.close();
		}
	}


	void SearchR(char *folder, string SearchRange,int &CountOfDaemons) {
		string tempString;
		cout << "Write number of Start position: ";
		cin >> SearchRange;
		cout << "Write number of End position: ";
		cin >> tempString;
		if (atoi(tempString.c_str())<= atoi(SearchRange.c_str())) {
			cout << "Wrong!"<<endl;
			SearchR(folder, SearchRange, CountOfDaemons);
		}
		SearchRange += "/" + tempString + "/"  + to_string(CountOfDaemons);
		++CountOfDaemons;
		NewWindow(folder, SearchRange);
	}

	void SearchR2(char *folder, string SearchRange, int &CountOfDaemons) {
		string tempString;
		string FileName, WhatSearch;
		cout << "Write file name: ";
		cin >> FileName;
		cout << "Search for: ";
		cin >> WhatSearch;

		ofstream myfile2;
		myfile2.open("Temp.txt");
		myfile2 << FileName+"/"+ WhatSearch;
		myfile2.close();

		cout << "Write number of Start position: ";
		cin >> SearchRange;
		cout << "Write number of End position: ";
		cin >> tempString;
		if (atoi(tempString.c_str()) <= atoi(SearchRange.c_str())) {
			cout << "Wrong!" << endl;
			SearchR(folder, SearchRange, CountOfDaemons);
		}
		SearchRange += "/" + tempString + "/" + to_string(CountOfDaemons);
		++CountOfDaemons;
		NewWindow(folder, SearchRange);
	}

	void NewWindow(char *folder, string SearchRange)
	{
		ShellExecute(GetConsoleWindow(), "open", folder,SearchRange.c_str(), NULL, SW_SHOWNORMAL);
		//PostMessage(child, WM_CLOSE, 0, 0);
		//std::cout << child;
		//std::thread fr(StartCMD);
		//fr.join();
	}
};



class SeachDaemon {
public:


	void Parse(int startL,int endL, int &NumbofDaemon,string &FileForSearch,string &SearchWord) {
			int array_size = endL-startL; //size of array
			char * array = new char[array_size]; //array to store file contents
			int position = 0; //keep track of array position where new character from file will be stored


			ofstream myfile;
			string FileName = "DaemonFile" + to_string(NumbofDaemon)+".txt";

			std::ifstream fin(FileForSearch, std::ifstream::binary);
			if (fin.is_open())
			{
				fin.seekg(0, std::ios::end); //seeking to the end of the file
				int length = fin.tellg(); //Getting the length of file or positon of enf of file
				fin.seekg(0, std::ios::beg); //seeking to the start of the file
										//prompting user to enter position, to start reading data from, in the file
				cout << "FileLength: " << length << endl;
				int seek_position;
				//string SearchWord = "Recreation_and_Sports";

				int LengthOfWord = SearchWord.length();
				bool ContinueSearch=true;

				cout << endl<< SearchWord[LengthOfWord-1];
				//std::cin >> seek_position;
				seek_position = startL;
				if (seek_position >= 0 && seek_position <= length) // checking user entered position lie within file
				{
					fin.seekg(seek_position, std::ios::beg); //seeking to the user specified position from begining of the file
										//Reading file from seek_position to end of file into array
					while (!fin.eof()&& ContinueSearch)
					{

						myfile.open(FileName.c_str());
						myfile << (float)position/ (endL - startL);
						myfile.close();

						fin.get(array[position]);
						cout << array[position];

						if (SearchWord[LengthOfWord-1]==array[position]) {
							ContinueSearch = true;
							for (int i = 0; i < LengthOfWord; i++) {
								if (SearchWord[LengthOfWord - i-1] == array[position-i]) {
									ContinueSearch = true;
									if (SearchWord[0] == array[position - i]) {
										cout <<endl <<"READY: "<< position - i<<endl;
										ContinueSearch = false;
										myfile.open(FileName.c_str());
										myfile << 1;
										myfile.close();
									}

								}else{ break; }
							}
						}

						position++;
						if (position > endL-startL)break;
					}

					if (ContinueSearch) { cout <<endl <<"---------------Don't Found------------"; }
					array[position - 1] = '\0';
					//displaying the data stored in the array
					/*for (int i = 0; array[i] != '\0'; i++)
					{
						cout << array[i];
					}*/
				}
				else //position entered by user in not with in the file range
				{
					cout << "Invalid Seek Position." << endl;
				}

			}
			else //file could not be opened
			{
				cout << "File could not be opened." << endl;
			}

			fstream fs("History.txt", ios::app);
				fs << startL<<"-" << endL<< endl;
				fs.close();
			cout << endl;
		}



	void Search(string SearchRange) {
		size_t pos = SearchRange.find("/");
		size_t pos2 = SearchRange.find_last_of("/");
		string startS = SearchRange.substr(0, pos),
			   endS = SearchRange.substr(pos+1),
			   DaemonS = SearchRange.substr(pos2 + 1);
		int startPos = atoi(startS.c_str()) ,
			endPos = atoi(endS.c_str()),
			NumbofDaemon = atoi(DaemonS.c_str());
		cout << "Searching from: " << startPos  << " to " << endPos<< endl <<"Number of Daemon: " << NumbofDaemon << endl;
		string Title = "Daemon_" + to_string(NumbofDaemon);
		SetConsoleTitle(Title.c_str());



		string line;
		ifstream myfile("Temp.txt");
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				getline(myfile, line);
				//cout << "Daemon " << i << " progress: " << atof((line).c_str()) * 100 << "%" << endl;
			}
			myfile.close();
		}

		size_t pos3 = line.find("/");
		string startS2 = line.substr(0, pos3),
			endS2 = line.substr(pos3 + 1);
		//int startPos2 = atoi(startS.c_str()),
		//	endPos2 = atoi(endS.c_str());
		//cout << buff << "///";
		cout <<"Search File: " << startS2<< endl <<"Searching for: " << endS2;
		Parse(startPos,endPos, NumbofDaemon, startS2, endS2);
	}
};



int main(int argc, char* argv[], char *env[])
{
	string SearchRange;

	if (argv[1] != NULL) {
		SearchRange = argv[1];
		SeachDaemon SearhD;
		SearhD.Search(SearchRange);
	}
	else {
		int CountOfDaemons = 0;
		char *folder;
		char *my1;
		SetConsoleTitle("Manager");
		folder = argv[0];
		SearchManager Manager;
	    Manager.MenuSelect(folder, SearchRange, CountOfDaemons);
	}
	system("pause");
	return 0;
}
