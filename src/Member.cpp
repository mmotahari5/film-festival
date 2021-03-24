#include "../include/Member.hpp"
#include "../include/nonMember.hpp"

using namespace std;

void Film::set_name(string Name){
	name = Name;
}
void Film::set_score(ui Score){
	score = Score;
}
void Film::set_data (ui Data){
	data = Data;
}
void Film::set_director (string Director){
	director = Director;
}
void Film::set_time (ui Time){
	time = Time;
}
void Film::set_country (string Country){
	country = Country;
}
void Film::set_id (){
  random_device dev;
  default_random_engine eng (dev());
  uniform_int_distribution <ui> Myrand(1000, 2000);
  id = Myrand(eng);
}
string Film::get_name(){
	return name;
}
ui Film::get_score(){
	return score;
}
ui Film::get_data(){
	return data;
}
string Film::get_director(){
	return director;
}
ui Film::get_time(){
	return time;
}
string Film::get_country(){
	return country;
}
ui Film::get_id(){
	return id;
}
