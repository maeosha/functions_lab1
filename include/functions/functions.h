#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
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

	Function(float parameter_a, float parameter_b, TypeFunction type);
	Function(float parameter_c, TypeFunction type);

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

int get_key() {
	int key;
	return key = _getch();
}

class Function_list {
private:
	Function data[CAPASITY];
	int size;
public:
	int index;
	Function_list();


	int get_size();

	Function get_element(int index);
	void add_element(Function item, int index);
	void delete_element(int index, int size);

	void set_size(int _size);
	float calculating_the_function(int index);
	Function calculating_the_diff(int index);
	float calculating_the_primitive(int index);
	void set_argument(int index, float argeument);
	minimal finding_min_derivative();


	void print_function(int index);
};

class minimal {
public:
	float min_Function;
	float min_Function_index;
	minimal() {
		min_Function = pow(10, 20);
		min_Function_index = 0;
	}
};

void Console();