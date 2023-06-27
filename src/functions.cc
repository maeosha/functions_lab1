#include <functions/functions.h>


Function::Function() {
	parameter_a = 0;

	parameter_b = 0;

	parameter_c = 0;

	argument = 0;

	type = NONE;
}

Function::Function(float parameter_a, float parameter_b) :
	parameter_a(parameter_a),
	parameter_b(parameter_b),
	type(POWERFUNCTION)
{ }

Function::Function(float parameter_c) :
	parameter_c(parameter_c),
	type(NATUREFUNCTION)
{ }


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





Function_list::Function_list() :
	data_ptr(nullptr),
	size(0)
{ }

Function_list::Function_list(int index) {
	data_ptr = new Function * [index];
	for (int i = 0; i < index; i++) {
		data_ptr[i] = new Function;
	}
	size = index;
}


int Function_list::get_size() {
	return size;
}

Function** Function_list::get_data() {
	return data_ptr;
}



void Function_list::swap(Function_list& container) noexcept {
	std::swap(data_ptr, container.data_ptr);
	std::swap(size, container.size);
}


Function_list Function_list::operator=(Function_list& container) {
	swap(container);
	return *this;
}

Function  Function_list::operator[](int const index) {
	if (index < 0) {
		throw  ("You have gone beyond the boundaries!");
	}

	return *data_ptr[index];
}

Function_list::Function_list(Function_list& container) {
	data_ptr = new Function * [container.get_size()];
	size = container.get_size();
	for (int i = 0; i < container.get_size(); i++) {
		data_ptr[i] = new Function(container[i]);
	}
}

Function_list::~Function_list() noexcept {

}


void Function_list::add_element(Function& item, int index) {
	Function time_item = item;
	while (data_ptr[index]->get_type() != NONE && index != size - 1) {
		time_item = *data_ptr[index];
		*data_ptr[index] = item;
		item = time_item;
		index++;
	}
	*data_ptr[index] = time_item;
	quantity++;
	if (quantity == size) {
		data_ptr[size] = new Function;
		size++;
	}
}

void Function_list::add_element_by_index(Function& item, int index) {
	for (int i = size - 1; i <= index; i++) {
		data_ptr[i] = new Function;
	}
	*data_ptr[index] = item;
	quantity++;
	size = index + 1;
}

void Function_list::delete_element(int index) {
	for (int i = index; i < size - 1; i++) {
		data_ptr[i] = data_ptr[i + 1];
	}
	size--;
	quantity--;
}

float Function_list::calculating_the_function(float argument, int index) {
	TypeFunction type = data_ptr[index]->get_type();
	if (type == POWERFUNCTION) {
		float parameter_a = data_ptr[index]->get_parameter_a();
		float parameter_b = data_ptr[index]->get_parameter_b();

		return parameter_a * pow(argument, parameter_b);
	}

	if (type == NATUREFUNCTION) {
		float parameter_c = data_ptr[index]->get_parameter_c();

		return parameter_c * log1pf(abs(argument - 1));
	}
}


Function Function_list::calculating_the_diff(int index) {
	TypeFunction type = data_ptr[index]->get_type();
	float parameter_a = data_ptr[index]->get_parameter_a();
	float parameter_b = data_ptr[index]->get_parameter_b();
	if (type == POWERFUNCTION) {
		parameter_a *= parameter_b;
		Function value(parameter_a, --parameter_b);
		return value;
	}
}

float Function_list::calculating_the_primitive(int index) {
	float parameter_b = data_ptr[index]->get_parameter_b();
	return ++parameter_b;
}


int Function_list::finding_min_derivative(float argument) {
	int index = 0;
	int min_index;
	float min_value = pow(10, 20);

	for (int index = 0; index < size; index++) {
		TypeFunction type = data_ptr[index]->get_type();
		Function& data_item = *data_ptr[index];

		if (type == NONE) {
			continue;
		}

		data_ptr[index]->set_parameter_a(calculating_the_diff(index).get_parameter_a());
		data_ptr[index]->set_parameter_b(calculating_the_diff(index).get_parameter_b());
		data_ptr[index]->set_parameter_c(calculating_the_diff(index).get_parameter_c());

		if (calculating_the_function(argument, index) <= min_value) {
			min_index = index;
			min_value = calculating_the_function(argument, index);
		}

		*data_ptr[index] = data_item;
	}
	return min_index;
}


void Function_list::print(int index) {
	std::cout << data_ptr[index];
}
std::ostream& operator<<(std::ostream& stream, Function* item) {
	stream << std::fixed << std::setprecision(2);
	if (item->get_type() == NONE) {
		stream << "NONE" << "\n" << std::endl;
	}

	if (item->get_type() == POWERFUNCTION) {
		stream << "f(x) = " << item->get_parameter_a() << " * x" << " ^ " << item->get_parameter_b() << "\n" << std::endl;
	}

	if (item->get_type() == NATUREFUNCTION) {
		stream << "f(x) = " << item->get_parameter_c() << " * ln(|x|)" << "\n" << std::endl;
	}
	return stream;
}
