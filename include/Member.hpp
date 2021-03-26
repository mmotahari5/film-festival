#include <iostream>
#include <string>
#ifndef MEMBER_H
#define MEMBER_H

typedef unsigned int ui;

class Film {
public:
	Film(){
	};
	void set_name (std::string);
	void set_score (ui);
	void set_data (ui);
	void set_director (std::string);
	void set_time (ui);
	void set_country (std::string);
	void set_id ();
	std::string get_name ();
	ui get_score ();
	ui get_data ();
	std::string get_director ();
	ui get_time ();
	std::string get_country ();
	ui get_id ();
private:
	std::string name;
	ui score;
	ui data;
	std::string director;
	ui time;
	std::string country;
	ui id;
};


#endif
