#include <iostream>
#include <utility>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <memory>

class Function;

using Function_ptr = std::shared_ptr<Function>;

class Function {
	float argument;
public:
	virtual bool NONE() = 0;

	virtual float calculating_the_function(float argument) = 0;
	virtual Function_ptr calculating_the_diff() = 0;
	virtual Function_ptr calculating_the_primitive() = 0;

	virtual Function_ptr clone() = 0;

	virtual void print() = 0;
	virtual void print_diff() = 0;
	virtual void print_primitive() = 0;

	virtual ~Function() = default;

protected:
	Function() = default;
	Function(const Function&) = default;
	Function& operator=(const Function&) = default;
};

class Power_function : public Function {
	float parameter_a;
	float parameter_b;
public:

	Power_function();

	Power_function(float parameter_a, float parameter_b);

	bool NONE() override;

	void set_parameter_a(float parameter_a);
	void set_parameter_b(float parameter_b);

	float get_parameter_a();
	float get_parameter_b();

	Function_ptr clone() override;

	float calculating_the_function(float argument) override;
	Function_ptr calculating_the_diff() override;
	Function_ptr calculating_the_primitive() override;

	void print() override;
	void print_diff() override;
	void print_primitive() override;
};

class Nature_function : public Function {
	float parameter_c;
public:
	Nature_function();
	Nature_function(float c);

	bool NONE() override;

	void set_parameter_c(float parameter_a);

	float get_parameter_c();

	Function_ptr clone() override;

	float calculating_the_function(float argument) override;
	Function_ptr calculating_the_diff() override;
	Function_ptr calculating_the_primitive() override;

	void print() override;
	void print_diff() override;
	void print_primitive() override;
};

class NONE_function : public Function {
	int a;
public:

	bool NONE() override;

	float calculating_the_function(float argument) override {
		return 0;
	}
	Function_ptr calculating_the_diff() override {
		return std::make_shared<Nature_function>(0);
	}
	Function_ptr calculating_the_primitive() override {
		return std::make_shared<Nature_function>(0);
	}


	Function_ptr clone() override {
		return std::make_shared<Nature_function>(0);
	}

	void print() override;
	void print_diff() override { std::cout << ""; }
	void print_primitive() override { std::cout << ""; }
};

class Function_list {
	std::vector<Function_ptr> data_ptr;
	size_t size;
	size_t quantity = 0;
public:
	Function_list() {
		data_ptr.push_back(std::make_shared<NONE_function>());
		size = 1;
	}

	size_t get_size();

	Function_ptr operator[](int index);


	void add_element(Function_ptr item, int index);
	void add_element_by_index(Function_ptr item, int index);
	void delete_element(int index);

	int finding_min_derivative(float argument);

};

void Console();
void menu(int index);
void menu_adder(int index, int key1);
void menu_value(int index);
void menu_derivative(int index);
void menu_primitive(int index);
void menu_min_derivative(int index);