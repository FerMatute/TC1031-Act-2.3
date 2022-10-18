// =================================================================
//
// File: main.cpp
// Author: Fernando - A00833375
// Date: 18/10/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "header.h" 
#include "ship.h"
#include "selection.h"

using namespace std;

int main(int argc, char* argv[]) {

  ifstream input;
  ofstream mysolution;

  if (argc != 3){
    cout<< "Error"<<endl;
    return -1;
  }

  input.open(argv[1]);
  if (!input.is_open()){
    cout << "Error al abrir el archivo\n";
    return -1;
  }

	mysolution.open(argv[2]);
	int num;
	string prefix, date, time, ubi;
	char entry;
	//Read the file first line
	input >>num >> prefix;
	//Ships vector with the amount of ships
	vector <Ship> ships;
	ships.resize(num);
	//Ships with prefix
	vector<Ship>ships_only_ubi;

	//We fill the vector with ships from the file
	for (int i=0; i<num; i++){
		input >> date >> time >> entry >> ubi;
		ships[i] = Ship(date, time, entry, ubi);
	}

	//We sort the ships by date
	selectionSort(ships);
	//January
	int rJan = 0;
	int mJan = 0;
	//February
	int rFeb = 0;
	int mFeb = 0;
	//March
	int rMar = 0;
	int mMar = 0;
	//April
	int rApr = 0;
	int mApr = 0;
	//May
	int rMay = 0;
	int mMay = 0;
	//Jun
	int rJun = 0;
	int mJun = 0;
	//Jul
	int rJul = 0;
	int mJul = 0;
	//Ago
	int rAgo = 0;
	int mAgo = 0;
	//Sep
	int rSep = 0;
	int mSep = 0;
	//Oct
	int rOct = 0;
	int mOct = 0;
	//Nov
	int rNov = 0;
	int mNov = 0;
	//Dic
	int rDic = 0;
	int mDic = 0;

	//We search for the prefix in the vector with all the ships
	for (int i = 0; i < num; i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		if(first_3 == prefix){
			int fecha = ships[i].month;
			char clave = ships[i].entry;
			if(fecha == 1){
				if(clave == 'R'){
					rJan++;
				}
				else{
					mJan++;
				}
			}
			else if(fecha == 2){
				if(clave == 'R'){
					rFeb++;
				}
				else{
					mFeb++;
				}
			}
			else if(fecha == 3){
				if(clave == 'R'){
					rMar++;
				}
				else{
					mMar++;
				}
			}
			else if(fecha == 4){
				if(clave == 'R'){
					rApr++;
				}
				else{
					mApr++;
				}
			}
			else if(fecha == 5){
				if(clave == 'R'){
					rMay++;
				}
				else{
					mMay++;
				}
			}
			else if(fecha == 6){
				if(clave == 'R'){
					rJun++;
				}
				else{
					mJun++;
				}
			}
			else if(fecha == 7){
				if(clave == 'R'){
					rJul++;
				}
				else{
					mJul++;
				}
			}
			else if(fecha == 8){
				if(clave == 'R'){
					rAgo++;
				}
				else{
					mAgo++;
				}
			}
			else if(fecha == 9){
				if(clave == 'R'){
					rSep++;
				}
				else{
					mSep++;
				}
			}
			else if(fecha == 10){
				if(clave == 'R'){
					rOct++;
				}
				else{
					mOct++;
				}
			}
			else if(fecha == 11){
				if(clave == 'R'){
					rNov++;
				}
				else{
					mNov++;
				}
			}
			else if(fecha == 12){
				if(clave == 'R'){
					rDic++;
				}
				else{
					mDic++;
				}
			}
		}
	}

	mysolution << "jan\n";
	mysolution << "M " << mJan << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 1 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rJan << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 1 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "feb\n";
	mysolution << "M " << mFeb << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 2 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rFeb << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 2 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "mar\n";
	mysolution << "M " << mMar << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	
	mysolution << "\n";
	mysolution << "R " << rMar << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "apr\n";
	mysolution << "M " << mApr << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rApr << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "may\n";
	mysolution << "M " << mMay << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rMay << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "jun\n";
	mysolution << "M " << mJun << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rJun << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "jul\n";
	mysolution << "M " << mJul << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rJul << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "ago\n";
	mysolution << "M " << mAgo << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rAgo << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "sep\n";
	mysolution << "M " << mSep << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rSep<< ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "oct\n";
	mysolution << "M " << mOct << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rOct << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "nov\n";
	mysolution << "M " << mNov << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rNov << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "dic\n";
	mysolution << "M " << mDic << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rDic << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}

	input.close();
	mysolution.close();

	return 0;
}