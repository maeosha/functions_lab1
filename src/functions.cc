#include <functions/functions.h>


Power_function::Power_function() {
	parameter_a = 0;
	parameter_b = 0;
}
Power_function::Power_function(float parameter_a, float parameter_b) :
	parameter_a(parameter_a),
	parameter_b(parameter_b)
{ }

bool Power_function::NONE() {
	return 0;
}

void Power_function::set_parameter_a(float parameter_a) {
	this->parameter_a = parameter_a;
}
void Power_function::set_parameter_b(float parameter_b) {
	this->parameter_b = parameter_b;
}

float Power_function::get_parameter_a() {
	return parameter_a;
}
float Power_function::get_parameter_b() {
	return parameter_b;
}

Function_ptr Power_function::clone() {
	return std::make_shared<Power_function>(parameter_a, parameter_b);
}

float Power_function::calculating_the_function(float argument) {
	return parameter_a * pow(argument, parameter_b);
}
Function_ptr Power_function::calculating_the_diff() {
	float diff_parameter_a = parameter_a * parameter_b;
	float diff_parameter_b = parameter_b - 1;

	return std::make_shared<Power_function>(diff_parameter_a, diff_parameter_b);
}
Function_ptr Power_function::calculating_the_primitive() {
	float primitive_parameter_a = parameter_a;
	float primitive_parameter_b = parameter_b + 1;

	return std::make_shared<Power_function>(primitive_parameter_a, primitive_parameter_b);
}

void Power_function::print() {
	std::cout << "f(x) = " << parameter_a << " * x" << " ^ " << parameter_b << std::endl << std::endl;
}
void Power_function::print_diff() {
	std::cout << "f'(x) = " << parameter_a << " * x" << " ^ " << parameter_b << std::endl << std::endl;
}
void Power_function::print_primitive() {
	std::cout << "F(x) = (" << parameter_a << " * x" << " ^ " << parameter_b << ") / " << parameter_b << std::endl << std::endl;
}



Nature_function::Nature_function() {
	parameter_c = 0;
}
Nature_function::Nature_function(float parameter_c) :
	parameter_c(parameter_c)
{ }

bool Nature_function::NONE() {
	return 0;
}

void Nature_function::set_parameter_c(float parameter_c) {
	this->parameter_c = parameter_c;
}

float Nature_function::get_parameter_c() {
	return parameter_c;
}

Function_ptr Nature_function::clone() {
	return std::make_shared<Nature_function>(parameter_c);
}

float Nature_function::calculating_the_function(float argument) {
	return parameter_c * log1pf(abs(argument - 1));
}
Function_ptr Nature_function::calculating_the_diff() {
	return std::make_shared<Nature_function>(parameter_c);;
}
Function_ptr Nature_function::calculating_the_primitive() {
	Nature_function primitive_item(parameter_c);
	return std::make_shared<Nature_function>(parameter_c);;
}

void Nature_function::print() {
	std::cout << "f(x) = " << parameter_c << " * ln(|x|)" << std::endl << std::endl;
}
void Nature_function::print_diff() {

	std::cout << "f'(x) = " << parameter_c << " * 1/|x|" << std::endl << std::endl;
}
void Nature_function::print_primitive() {
	auto item = this->clone();
	item->calculating_the_primitive();
	std::cout << "F(x) = (" << parameter_c << "ln(|x|)" << " - " << parameter_c << "x" << std::endl << std::endl;
}


bool NONE_function::NONE() {
	return 1;
}
void NONE_function::print() {
	std::cout << "NONE" << std::endl << std::endl;
}




size_t Function_list::get_size() {
	return size;
}

Function_ptr Function_list::operator[](int index) {
	return data_ptr[index];
}

void Function_list::add_element(Function_ptr item, int index) {

	data_ptr.insert(data_ptr.begin() + index, item);
	quantity++;
	if (quantity == size || index == size - 1) {
		size++;
		data_ptr.push_back(std::make_shared<NONE_function>());
	}

}
void Function_list::add_element_by_index(Function_ptr item, int index) {

	if (index <= size) {
		add_element(item, index);
		return;
	}


	for (int i = 0; i < (index - size + 1); i++) {
		data_ptr.push_back(std::make_shared<NONE_function>());
	}

	data_ptr.insert(data_ptr.begin() + index, item);
	size = index + 2;
	quantity++;

}
void Function_list::delete_element(int index) {
	data_ptr.erase(data_ptr.begin() + index);
	size--;
	quantity--;
}

int Function_list::finding_min_derivative(float argument) {
	float value;
	int min_index;
	float min_value = pow(10, 20);

	for (int index = 0; index < size; index++) {

		auto data_item = data_ptr[index]->clone();

		if (data_item->NONE() == 1) {
			continue;
		}

		value = data_ptr[index]->calculating_the_diff()->calculating_the_function(argument);

		if (value <= min_value) {
			min_index = index;
			min_value = value;
		}

		data_ptr[index] = data_item->clone();
	}
	return min_index;
}