#pragma once




#include <iostream>

#include <utility>

#include <iomanip>

#include <conio.h>










static const int CAPASITY = 30;

class minimal;




enum TypeFunction

{

	POWERFUNCTION,

	NATUREFUNCTION,

	NONE

};




class Function {

private:

	TypeFunction type;




	float parameter_a;

	float parameter_b;

	float parameter_c;

	float argument;







public:

	Function();




	Function(float parameter_a, float parameter_b);

	Function(float parameter_c);







	void set_parameter_a(float parameter_a);

	void set_parameter_b(float parameter_b);

	void set_parameter_c(float parameter_c);

	void set_argument(float argument);







	float get_parameter_a();

	float get_parameter_b();

	float get_parameter_c();

	float get_argument();

	TypeFunction get_type();

};







class Function_list {

private:

	Function** data_ptr;

	int size;

public:

	int quantity = 0;




	Function_list();

	Function_list(int index);




	void swap(Function_list& container) noexcept;







	int get_size();

	Function** get_data();




	Function_list operator=(Function_list& container);

	Function operator[](int index);




	Function_list(Function_list& container);




	~Function_list() noexcept;







	void add_element(Function& item, int index);

	void add_element_by_index(Function& item, int index);

	void delete_element(int index);

	float calculating_the_function(float argument, int index);

	Function calculating_the_diff(int index);

	float calculating_the_primitive(int index);

	int finding_min_derivative(float argument);







	void print(int index);

};




std::ostream& operator<<(std::ostream& stream, Function* item);




void clear();

void Console();

void menu(int index);

void menu_adder(int index, int key1);

void menu_value(int index);

void menu_derivative(int index);

void menu_primitive(int index);

void menu_min_derivative(int index);