#include <iostream>
#include <string>
#include "../include/Member.hpp"
#include "../include/nonMember.hpp"
using namespace std;
int main(){
	ui array_len = 0;

	string input;
	ui numberOfWords;

	getInput(input,numberOfWords);

	string commands[numberOfWords];
	CommandSeparator(commands,input,numberOfWords);


	Film * array = new Film[array_len];
	if(commands[0]=="help"){
		help();
		getInput(input,numberOfWords);
		CommandSeparator(commands,input,numberOfWords);
	}

	while(commands[0] != "exit"){
		array = doCommand(commands,array,array_len,numberOfWords);
		cout << "_____________" << endl;

		getInput(input,numberOfWords);
		CommandSeparator(commands,input,numberOfWords);
		if(commands[0]=="help"){
			help();
			getInput(input,numberOfWords);
			CommandSeparator(commands,input,numberOfWords);
		}
	}

	delete [] array;
	return 0;
}
