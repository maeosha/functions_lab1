#include <functions/functions.h>

Function_list container(1);


void menu(int index) {

	std::cout << "Function " << index + 1 << "/" << container.get_size() << std::endl;
	std::cout << "----------------------\n";
	container.print(index);
	if (container[index].get_type() == NONE) {
		std::cout << "1. Add a function.\n";
		std::cout << "2. Add a function by the index.\n";
	}
	else {
		std::cout << "1. Add a function.\n";
		std::cout << "2. Add a function by the index.\n";
		std::cout << "3. Delete a function.\n\n";
		std::cout << "4. Calculate the value of the function.\n";
		std::cout << "5. Calculate the derivative of the function.\n";
		std::cout << "6. Calculate the primitive function.\n\n";
		std::cout << "Enter. Find the minimum derivative of a function with a given argument\n\n";
	}
	if (container.get_size() == 1) {
		std::cout << "" << std::endl;
	}
	else {
		if (index == 0) {
			std::cout << "-> Next function." << std::endl;
		}
		else {
			if (index == container.get_size() - 1) {
				std::cout << "<-Last function." << std::endl;
			}

			else {
				std::cout << "-> Next function.\n";
				std::cout << "<-Last function.\n";
			}
		}
	}
	std::cout << "esc - escape from program." << std::endl;
}

void menu_adder(int index, int key1) {
	float parameter_a;
	float parameter_b;
	float parameter_c;
	int add_index;
	Function item;
	system("cls");
	if (key1 == 50) {
		std::cout << "By which index do you want to add an element?" << std::endl;
		std::cin >> add_index;
		if (add_index < 1) {
			throw("The index must be greater than 1");
		}
	}
	std::cout << "What function do you want to add:\n";
	std::cout << "1. ax^b.\n";
	std::cout << "2. c*ln(|x|)\n";
	int key = _getch();
	if (key == 49) {
		system("cls");
		std::cout << "Enter a parameter a: ";
		std::cin >> parameter_a;
		std::cout << "Enter a parameter b: ";
		std::cin >> parameter_b;
		item = Function(parameter_a, parameter_b);
	}
	if (key == 50) {
		system("cls");
		std::cout << "Enter a parameter c: ";
		std::cin >> parameter_c;
		item = Function(parameter_c);
	}
	switch (key1)
	{
	case 49:
		container.add_element(item, index);
		break;
	case 50:
		if (add_index > container.get_size()) {
			container.add_element_by_index(item, add_index - 1);
		}
		else {
			container.add_element(item, add_index - 1);
		}
	}
}

void menu_value(int index) {
	float argument;
	float value;
	system("cls");
	std::cout << "Enter the function argument: ";
	std::cin >> argument;
	value = container.calculating_the_function(argument, index);
	std::cout << "f(%.2f) = %.2f\n", argument, value;
	system("pause");
}

void menu_derivative(int index) {
	system("cls");
	TypeFunction type = container[index].get_type();
	if (type == POWERFUNCTION) {
		float parameter_a = container.calculating_the_diff(index).get_parameter_a();
		float parameter_b = container.calculating_the_diff(index).get_parameter_b();
		Function* New_item = new Function(parameter_a, parameter_b);
		std::cout << New_item;
		delete New_item;
	}
	else {
		float parameter_c = container[index].get_parameter_c();
		Function* New_item = new Function(parameter_c);
		std::cout << New_item;
		delete New_item;
	}
	system("pause");
}

void menu_primitive(int index) {
	system("cls");
	TypeFunction type = container[index].get_type();
	if (type == POWERFUNCTION) {
		float parameter_a = container[index].get_parameter_a();
		float parameter_b = container.calculating_the_primitive(index);
		Function* New_item = new Function(parameter_a, parameter_b);
		std::cout << New_item;
		delete New_item;
	}
	if (type == NATUREFUNCTION) {
		float parameter_c = container[index].get_parameter_c();
		Function* New_item = new Function(parameter_c);
		std::cout << New_item;
		delete New_item;
	}
	system("pause");
}

void menu_min_derivative(int index) {
	float argument;
	int min_index;
	float min_derivative_value;
	system("cls");
	std::cout << "Enter the function argument: ";
	std::cin >> argument;
	min_index = container.finding_min_derivative(argument);
	min_derivative_value = container.calculating_the_function(argument, min_index);
	std::cout << "The minimum value of the derivative: " << min_derivative_value << " (Function " << min_index + 1 << ")";
	system("pause");
}

void Console() {
	int index = 0;
	int key = 0;
	TypeFunction type;
	while (key != 27) {
		system("cls");
		menu(index);
		key = _getch();
		if (key == 49) {
			menu_adder(index, key);
		}
		if (key == 50) {
			try {
				menu_adder(index, key);
			}
			catch (const char) {
				std::cout << "Error: ";
			}
		}
		type = container[index].get_type();

		if (key == 51 && type != NONE) {
			container.delete_element(index);
		}
		if (key == 52 && type != NONE) {
			menu_value(index);
		}
		if (key == 53 && type != NONE) {
			menu_derivative(index);
		}
		if (key == 54 && type != NONE) {
			menu_primitive(index);
		}
		if (key == 13 && container.get_size() != 0) {
			menu_min_derivative(index);
		}
		if (key == 77 && index < container.get_size() - 1) {
			++index;
		}
		if (key == 75 && index > 0) {
			--index;
		}
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	Console();
	for (int i = 0; i < container.get_size(); i++) {
		delete container.get_data()[i];
	}
	delete[] container.get_data();
}