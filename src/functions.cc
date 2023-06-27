#include <functions/functions.h>

void Console();
void menu(int index);
void menu_adder(int index);
void menu_value(int index);
void menu_derivative(int index);
void menu_primitive(int index);
void menu_min_derivative(int index);

Function::Function() {
	parameter_a = 0;

	parameter_b = 0;

	parameter_c = 0;

	argument = 0;

	type = NONE;
}

Function::Function(float parameter_a, float parameter_b, TypeFunction type) :
	parameter_a(parameter_a),
	parameter_b(parameter_b),
	type(type)
{ }

Function::Function(float parameter_c, TypeFunction type) :
	parameter_c(parameter_c),
	type(type)
{ }

Function_list::Function_list() :
	size(0)
{ }


Function item;

Function_list conteiner;


void Function::set_parameter_a(float parameter_a) {
	this->parameter_a = parameter_a;
}

void Function::set_parameter_b(float parameter_b) {
	this->parameter_b = parameter_b;
}

void Function::set_parameter_c(float parameter_c) {
	this->parameter_c = parameter_c;
}

void Function::set_argument(float argument) {
	this->argument = argument;
}


float Function::get_parameter_a() {
	return parameter_a;
}

float Function::get_parameter_b() {
	return parameter_b;
}

float Function::get_parameter_c() {
	return parameter_c;
}

float Function::get_argument() {
	return argument;
}

TypeFunction Function::get_type() {
	return type;
}

int Function_list::get_size() {
	return size;
}

void Function_list::set_size(int _size) {
	size = _size;
}

Function Function_list::get_element(int index) {
	return data[index];
}

void Function_list::set_argument(int index, float argument) {
	data[index].set_argument(argument);
}

void Function_list::add_element(Function item, int index) {
	Function time_item = item;
	if (size >= CAPASITY) {
		throw "err";
	}
	while (data[index].get_type() != NONE && index != CAPASITY - 1) {
		time_item = data[index];
		data[index] = item;
		item = time_item;
		index++;
	}
	data[index] = time_item;
	size++;
}
void Function_list::delete_element(int index, int size) {
	Function item;
	data[index] = item;
	size--;
}

float Function_list::calculating_the_function(int index) {
	TypeFunction type = data[index].get_type();
	float argument = data[index].get_argument();
	if (type == POWERFUNCTION) {
		float parameter_a = data[index].get_parameter_a();
		float parameter_b = data[index].get_parameter_b();

		return parameter_a * pow(argument, parameter_b);
	}

	if (type == NATUREFUNCTION) {
		float parameter_c = data[index].get_parameter_c();

		return parameter_c * log1pf(abs(argument));
	}
}


Function Function_list::calculating_the_diff(int index) {
	TypeFunction type = data[index].get_type();
	float parameter_a = data[index].get_parameter_a();
	float parameter_b = data[index].get_parameter_b();
	if (type == POWERFUNCTION) {
		parameter_a *= parameter_b;
		Function value(parameter_a, --parameter_b, POWERFUNCTION);
		return value;
	}

}

float Function_list::calculating_the_primitive(int index) {
	float parameter_b = data[index].get_parameter_b();
	return ++parameter_b;
}

minimal Function_list::finding_min_derivative() {
	minimal minimal;

	for (int index = 0; index < CAPASITY - 1; index++) {
		TypeFunction type = data[index].get_type();

		if (type == NONE) {
			index++;
		}

		else {
			Function data_item = data[index];
			data[index].set_parameter_a(calculating_the_diff(index).get_parameter_a());
			data[index].set_parameter_b(calculating_the_diff(index).get_parameter_b());


			if (calculating_the_function(index) <= minimal.min_Function) {
				minimal.min_Function_index = index;
			}

			data[index] = data_item;
		}
	}

	return minimal;
}


void Function_list::print_function(int index) {
	TypeFunction type = data[index].get_type();
	if (type == NONE) {
		printf("NONE\n\n");
	}

	if (type == POWERFUNCTION) {
		float parameter_a = data[index].get_parameter_a();
		float parameter_b = data[index].get_parameter_b();

		printf("f(x) = %.2f * x ^ %.2f\n\n", parameter_a, parameter_b);
	}

	if (type == NATUREFUNCTION) {
		float parameter_c = data[index].get_parameter_a();

		printf("f(x) = %.2f * ln(|x|)\n\n", data[index].get_parameter_c());
	}
}


void menu(int index) {

	printf("Function #%d/%d\n", index + 1, CAPASITY);
	printf("----------------------\n");
	conteiner.print_function(index);
	if (conteiner.get_element(index).get_type() == NONE) {
		printf("1. Add a function.\n");
	}
	else {
		printf("1. Add a function.\n");
		printf("2. Delete a function.\n\n");
		printf("3. Calculate the value of the function.\n");
		printf("4. Calculate the derivative of the function.\n");
		printf("5. Calculate the primitive function.\n\n");
		printf("Enter. Find the minimum derivative of a function with a given argument\n\n");
	}
	if (index == 0) {
		printf("-> Next function.\n");
	}
	else {
		if (index == CAPASITY - 1) {
			printf("<-Last function.\n");
		}
		else {
			printf("-> Next function.\n");
			printf("<-Last function.\n");
		}
	}
}

void menu_adder(int index) {
	float parameter_a;
	float parameter_b;
	float parameter_c;

	system("cls");
	printf("What function do you want to add:\n");
	printf("1. ax^b.\n");
	printf("2. c*ln(|x|)\n");
	int key = get_key();
	if (key == 49) {
		system("cls");
		printf("Enter a parameter a: ");
		scanf_s("%f", &parameter_a);
		printf("Enter a parameter b: ");
		scanf_s("%f", &parameter_b);
		Function item(parameter_a, parameter_b, POWERFUNCTION);
		conteiner.add_element(item, index);
	}


	if (key == 50) {
		system("cls");
		printf("Enter a parameter c: ");
		scanf_s("%f", &parameter_c);
		Function item(parameter_c, NATUREFUNCTION);
		conteiner.add_element(item, index);
	}
}

void menu_value(int index) {
	float argument;
	float value;
	system("cls");
	printf("Enter the function argument: ");
	scanf_s("%f", &argument);
	conteiner.set_argument(index, argument);
	value = conteiner.calculating_the_function(index);
	printf("f(%.2f) = %.2f\n", argument, value);
	system("pause");
}

void menu_derivative(int index) {
	system("cls");
	TypeFunction type = conteiner.get_element(index).get_type();
	if (type == POWERFUNCTION) {
		float parameter_a = conteiner.calculating_the_diff(index).get_parameter_a();
		float parameter_b = conteiner.calculating_the_diff(index).get_parameter_b();

		printf("f'(x) = %.2f * x ^ %.2f\n", parameter_a, parameter_b);
	}
	else {
		float parameter_c = conteiner.get_element(index).get_parameter_c();

		printf("f'(x) = %.2f / x\n", parameter_c);
	}
	system("pause");
}

void menu_primitive(int index) {
	system("cls");
	TypeFunction type = conteiner.get_element(index).get_type();
	if (type == POWERFUNCTION) {
		float parameter_a = conteiner.get_element(index).get_parameter_a();
		float parameter_b = conteiner.calculating_the_primitive(index);
		printf("F(x) = (%.2f * x ^ %.2f) / %.2f + C\n", parameter_a, parameter_b, parameter_b);
	}
	if (type == NATUREFUNCTION) {
		float parameter_c = conteiner.get_element(index).get_parameter_c();
		printf("F(x) = %.2f * x * (ln(|x| - 1) + C\n", parameter_c);
	}
	system("pause");
}

void menu_min_derivative(int index) {
	float argument;
	int min_index = conteiner.finding_min_derivative().min_Function_index;
	float min_derivative_value = conteiner.finding_min_derivative().min_Function;
	system("cls");
	printf("Enter the function argument: ");
	scanf_s("%f", &argument);
	conteiner.set_argument(index, argument);
	conteiner.finding_min_derivative();
	printf("The minimum value of the derivative: %.2f (Function #%d)\n", min_derivative_value, min_index);
	system("pause");
}

void Console() {
	int index = 0;
	TypeFunction type;
	while (true) {
		system("cls");
		menu(index);
		int key = _getch();
		if (key == 49) {
			menu_adder(index);
		}

		type = conteiner.get_element(index).get_type();

		if (key == 50 && type == NONE) {
			conteiner.delete_element(index, conteiner.get_size());
		}
		if (key == 51 && type != NONE) {
			menu_value(index);
		}
		if (key == 52 && type != NONE) {
			menu_derivative(index);
		}
		if (key == 53 && type != NONE) {
			menu_primitive(index);
		}
		if (key == 13 && conteiner.get_size() != 0) {
			menu_min_derivative(index);
		}
		if (key == 77 && index < CAPASITY - 1) {
			++index;
		}
		if (key == 75 && index > 0) {
			--index;
		}
	}
}

