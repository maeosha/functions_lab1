#include <functions/functions.h>

Function_list container;

void menu(int index) {

	std::cout << "Function " << index + 1 << "/" << container.get_size() << std::endl;
	std::cout << "----------------------\n";
	container[index]->print();
	if (container[index]->NONE() == 1) {
		std::cout << "1. Add a function.\n";
		std::cout << "2. Add a function by the index.\n\n";
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
	Function_ptr item;
	system("cls");
	if (key1 == 50) {
		std::cout << "By which index do you want to add an element?" << std::endl;
		std::cin >> index;
		system("cls");
		if (index < 1) {
			throw("The index must be greater than 1");
		}
		index--;
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
		auto item = std::make_shared<Power_function>(parameter_a, parameter_b);
		container.add_element_by_index(item, index);

	}

	if (key == 50) {
		system("cls");
		std::cout << "Enter a parameter c: ";
		std::cin >> parameter_c;
		auto item = std::make_shared<Nature_function>(parameter_c);
		container.add_element_by_index(item, index);
	}
}

void menu_value(int index) {
	float argument;
	float value;
	system("cls");
	std::cout << "Enter the function argument: ";
	std::cin >> argument;

	value = container[index]->calculating_the_function(argument);
	std::cout << "f(" << argument << ") = " << value << std::endl;
	system("pause");
}

void menu_derivative(int index) {
	system("cls");
	container[index]->calculating_the_diff()->print_diff();
	system("pause");
}

void menu_primitive(int index) {
	system("cls");
	container[index]->calculating_the_primitive()->print_primitive();
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
	min_derivative_value = container[min_index]->calculating_the_function(argument);
	std::cout << "The minimum value of the derivative: " << min_derivative_value << " (Function " << min_index + 1 << ")";
	system("pause");
}

void Console() {
	int index = 0;
	int key = 0;
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
		bool type = container[index]->NONE();
		if (key == 51 && type != 1) {
			container.delete_element(index);
		}
		if (key == 52 && type != 1) {
			menu_value(index);
		}
		if (key == 53 && type != 1) {
			menu_derivative(index);
		}
		if (key == 54 && type != 1) {
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
}
