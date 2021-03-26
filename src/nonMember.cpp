#include "../include/nonMember.hpp"
#include "../include/Member.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void SpellCheck(string &input){
	ui len = input.length();
	for(size_t i = 0;i < len;i++){
		if(input[i] == 'A'){
			input[i] = 'a';
		}
		if(input[i] == 'B'){
			input[i] = 'b';
		}
		if(input[i] == 'C'){
			input[i] = 'c';
		}
		if(input[i] == 'D'){
			input[i] = 'd';
		}
		if(input[i] == 'E'){
			input[i] = 'e';
		}
		if(input[i] == 'F'){
			input[i] = 'f';
		}
		if(input[i] == 'G'){
			input[i] = 'g';
		}
		if(input[i] == 'H'){
			input[i] = 'h';
		}
		if(input[i] == 'I'){
			input[i] = 'i';
		}
		if(input[i] == 'J'){
			input[i] = 'j';
		}
		if(input[i] == 'K'){
			input[i] = 'k';
		}
		if(input[i] == 'L'){
			input[i] = 'l';
		}
		if(input[i] == 'M'){
			input[i] = 'm';
		}
		if(input[i] == 'N'){
			input[i] = 'n';
		}
		if(input[i] == 'O'){
			input[i] = 'o';
		}
		if(input[i] == 'P'){
			input[i] = 'p';
		}
		if(input[i] == 'Q'){
			input[i] = 'q';
		}
		if(input[i] == 'R'){
			input[i] = 'r';
		}
		if(input[i] == 'S'){
			input[i] = 's';
		}
		if(input[i] == 'T'){
			input[i] = 't';
		}
		if(input[i] == 'U'){
			input[i] = 'u';
		}
		if(input[i] == 'V'){
			input[i] = 'v';
		}
		if(input[i] == 'W'){
			input[i] = 'w';
		}
		if(input[i] == 'X'){
			input[i] = 'x';
		}
		if(input[i] == 'Y'){
			input[i] = 'y';
		}
		if(input[i] == 'Z'){
			input[i] = 'z';
		}
	}
}

void getInput(string &input,ui &numberOfWords){
	getline(cin,input);
	ui len = input.length();
	SpellCheck(input);
	numberOfWords = 0;
	for(size_t i = 0; i < len ;){
		if(input[i] == ' '){
			i++;
			continue;
		}
		else{
			numberOfWords++;
			ui j = 0;
			bool foundSpace = false;
			while(!foundSpace){
				if((input[i+j+1] == ' ')||(i+j+1 == len-1)){
					i += j+1;
					foundSpace = true;
				}
				j++;
			}
		}
		i++;
	}
}

void CommandSeparator(string commands[],string input,ui numberOfWords){
	ui len=input.length(),z=0,k=0,m=0;
	for(size_t i=0;i < len;){
		if(input[i]==' '){
			i++;
			continue;
		}
		else{
			m=i;
			ui j=0;
			bool foundSpace = false;
			while(!foundSpace){
				if((input[i+j+1]==' ')||(i+j+1==len)){
					i+=j+1;
					foundSpace = true;
				}
				j++;
			}
			k=0;
			char temp[100]={'\0'};
			for(;m < i;m++){
				temp[k] = input[m];
				k++;
			}
			commands[z]=temp;
			z++;
		}
		if(z >= numberOfWords){
			break;
		}
		i++;
	}
}

Film* doCommand(string* commands,Film* arrayOfFilms,ui &lengthOfArray,ui numberOfWords){
		if(commands[0] == "add"){
			if(numberOfWords != 7){
				cout << "Your input is invalid, please enter command correctly." << endl;
				if(lengthOfArray == 0){
					return nullptr;
				}
				return arrayOfFilms;
			}
			stringstream geek1(commands[2]);
			ui score;
			geek1 >> score;
			stringstream geek2(commands[3]);
			ui data;
			geek2 >> data;
			stringstream geek3(commands[5]);
			ui time;
			geek3 >> time;
			Film newFilm;
			newFilm.set_name(commands[1]);
			newFilm.set_score(score);
			newFilm.set_data(data);
			newFilm.set_director(commands[4]);
			newFilm.set_time(time);
			newFilm.set_country(commands[6]);
			newFilm.set_id();
			arrayOfFilms = add(arrayOfFilms,newFilm,lengthOfArray);
			lengthOfArray++;
			return arrayOfFilms;
		}
		if(commands[0] == "show"){
			show(arrayOfFilms,commands[1],lengthOfArray);
			if(lengthOfArray == 0){
				return nullptr;
			}
			return arrayOfFilms;
		}
		if(commands[0] == "show-all"){
			cout << left << setw(25) <<"name"<<setw(8) <<"|score" << setw(8) << "|data" << setw(26) << "|director"  << setw(8) << "|time"  << setw(16) << "|country" << setw(8) << "|id"<<endl;
			cout << endl;

			for(size_t i = 0;i < lengthOfArray;i++){
				cout << left << setw(25) << arrayOfFilms[i].get_name()  <<"|"<< setw(7) << arrayOfFilms[i].get_score()  <<"|"<<  setw(7) << arrayOfFilms[i].get_data()  <<"|"<<  setw(25) << arrayOfFilms[i].get_director()  <<"|"<< setw(7) << arrayOfFilms[i].get_time()  <<"|"<<  setw(15) << arrayOfFilms[i].get_country()  <<"|"<<  setw(7) << arrayOfFilms[i].get_id()<< endl;
			}
			return arrayOfFilms;
		}
		if(commands[0]=="remove"){
			if(lengthOfArray == 0){
				cout << "array is empty!!" << endl;
				return arrayOfFilms;
			}
			if(numberOfWords == 1){
				cout << "command invalid." <<endl;
				return arrayOfFilms;
			}
			arrayOfFilms = remove(arrayOfFilms,commands[1],lengthOfArray);
			return arrayOfFilms;
		}
		if(commands[0]=="sort-by"){
			arrayOfFilms = sortBy(arrayOfFilms,commands[1],lengthOfArray);
			return arrayOfFilms;
		}
		if(commands[0]=="average-score"){
			cout <<"average score: " << averageScore(arrayOfFilms,lengthOfArray) << endl;
			return arrayOfFilms;
		}
		if(commands[0]=="help"){
			help();
			return nullptr;
		}
		return arrayOfFilms;
}

void help(){
	cout << "you can add and remove films from Films array\ncommand \"add\" example:\nadd be-vaghte-sham 70 2018 Ebrahim-Hatamikia 115 Iran\nthis code adds a movie with following specifications to array\nMovie name: be-vaghte-sham\nMovie score: 70\nData of manufacture: 2018\nDirector's name: Ebrahim-Hatamikia\nMovie duration: 115\nManufacturing country: Iran\n----------------------" << endl;
			cout << "command \"remove\" example:\nremove be-vaghte-sham\nThis code removes a movie with name(be-vaghte-sham) from array\n----------------------" << endl;
			cout << "The command \"show\" comes with a movie name that prints the properties of the movie in the array.\n----------------------" << endl;
			cout << "The command \"show-all\" prints all of the moives in the array\n----------------------" << endl;
			cout << "The command \"sort-by\" that comes with a mod word specifies whether the array is sorted by name or by score.\n---------------------" << endl;
			cout << "The command \"exit\" is also killed from program :)" << endl;
			cout << "\nGood luck.\n" << endl;
}

Film* add(Film* oldArray,Film newObject,ui lengthOfOldArray){
	Film* newArray = new Film[lengthOfOldArray+1];
	for(size_t i = 0;i < lengthOfOldArray;i++){
		newArray[i] = oldArray[i];
	}
	newArray[lengthOfOldArray] = newObject;
	cout << "movie \"" <<newObject.get_name() << "\" successfully added to array." << endl;
	return newArray;
}

void show(Film* array,string filmName,ui arrayLength){
	ui i = 0;
	bool found = false;
	for(;i<arrayLength;i++){
		string name = array[i].get_name();
		if(name == filmName){
			found = true;
			break;
		}
	}
	if(found){
		cout << setw(10) << array[i].get_name() << setw(10) << array[i].get_score() << setw(10) << array[i].get_data() << setw(10) << array[i].get_director() << setw(10) << array[i].get_time() << setw(10) << array[i].get_country() << setw(10) << array[i].get_id() << endl;
	}
	else{
		cout << "Not found a film with " << filmName << " name" << endl;
	}
}

Film* remove(Film* arrayOfFilms,string nameOfFilm,ui &lengthOfArray){
	bool foundName = false;
	ui i = 0;
	for(;i<lengthOfArray;i++){
		if(arrayOfFilms[i].get_name() == nameOfFilm){
			foundName = true;
			break;
		}
	}
	if(!foundName){
		cout << "your film not found!!" << endl;
		return arrayOfFilms;
	}
	Film* newArray = new Film[lengthOfArray-1];
	for(ui j=0;j<i;j++){
		newArray[j] = arrayOfFilms[j];
	}
	for(ui j=i+1;j<lengthOfArray;j++){
		newArray[j-1] = arrayOfFilms[j];
	}
	cout << "film \"" << nameOfFilm << "\" successfuly removed." << endl;
	lengthOfArray--;
	return newArray;
}

Film* sortBy(Film* arrayOfFilms,string mode,ui lengthOfArray){
	if(!((mode=="score")||(mode=="name"))){
		cout << "sort mode is invalid!" << endl;
		return arrayOfFilms;
	}
	for(ui i=1;i<lengthOfArray;i++){
		for(ui j=0;j<lengthOfArray-i;j++){
			if((mode=="score")&&(arrayOfFilms[j].get_score() > arrayOfFilms[j+1].get_score())){
				Film temp = arrayOfFilms[j];
				arrayOfFilms[j] = arrayOfFilms[j+1];
				arrayOfFilms[j+1] = temp;
			}
			else if((mode=="name")&&(arrayOfFilms[j].get_name()>arrayOfFilms[j+1].get_name())){
				Film temp = arrayOfFilms[j];
				arrayOfFilms[j] = arrayOfFilms[j+1];
				arrayOfFilms[j+1] = temp;
			}
		}
	}
	return arrayOfFilms;
}

double averageScore(Film *arrayOfFilms,ui lengthOfArray){
	ui sum=0;
	for(ui i=0;i<lengthOfArray;i++){
		sum += arrayOfFilms[i].get_score();
	}
	double average = static_cast<double>(sum)/lengthOfArray;
	return average;
}
