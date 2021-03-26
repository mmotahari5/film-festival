#ifndef NONMEMBER_H
#define NONMEMBER_H
#include <iostream>
#include <string>
#include <random>
#include "Member.hpp"

typedef unsigned int ui;

void help();

void SpellCheck(std::string&);

void CommandSeparator(std::string commands[],std::string,ui);

void getInput(std::string&,ui&);

void show(Film*,std::string,ui);

Film* doCommand(std::string*,Film*,ui&,ui);

Film* add(Film*,Film,ui);

Film* remove(Film*,std::string,ui&);

Film* sortBy(Film*,std::string,ui);

double averageScore(Film*,ui);

#endif
