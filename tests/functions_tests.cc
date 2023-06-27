#include <gtest/gtest.h>

#include <functions/functions.h>




TEST(FunctionsTests, calculating_the_function) {
    Function_list conteiner(5);
    float parameter_a = 4.00f;
    float parameter_b = 3.00f;
    float argument = 2.00f;
    float value;
    Function item(parameter_a, parameter_b);
    conteiner.add_element(item, 0);
    value = conteiner.calculating_the_function(argument, 0);
    EXPECT_EQ(value, 32.00f);
}


TEST(FunctionsTests, calculating_the_function_1) {
    Function_list conteiner(5);
    float parameter_c = 5.00f;
    float argument = 1.00f;
    float value;
    Function item(parameter_c);
    conteiner.add_element(item, 0);
    value = conteiner.calculating_the_function(argument, 0);
    EXPECT_EQ(value, 0);
}


TEST(FunctionsTests, calculating_the_diff) {
    Function_list conteiner(5);
    float parameter_a = 5.00f;
    float parameter_b = 3.00f;
    float diff_parameter_a;
    float diff_parameter_b;
    Function item(parameter_a, parameter_b);
    conteiner.add_element(item, 0);
    diff_parameter_a = conteiner.calculating_the_diff(0).get_parameter_a();
    diff_parameter_b = conteiner.calculating_the_diff(0).get_parameter_b();
    EXPECT_EQ(diff_parameter_a, 15.00f);
    EXPECT_EQ(diff_parameter_b, 2.00f);
}

TEST(FunctionTests, finding_min_derivative) {
    Function_list conteiner(5);
    int min_index;
    float min_value;
    int capasity = conteiner.get_size() - 3;
    int ds = 0;
    for (int index = 0; index < capasity; index++) {
        Function item(1, 1);
        conteiner.add_element(item, index);
        ds++;
    }
    Function item = *conteiner.get_data()[0];
    min_index = conteiner.finding_min_derivative(1);
    min_value = conteiner.calculating_the_function(0, min_index);
    EXPECT_EQ(item.get_parameter_a(), 1);
    EXPECT_EQ(min_value, 1);
}

TEST(FunctionTest, overload_overloading_square_brackets) {
    Function_list conteiner(5);
    Function item(2, 3);
    conteiner.add_element(item, 2);

    EXPECT_EQ(conteiner[2].get_parameter_a(), 2);
    EXPECT_EQ(conteiner[2].get_parameter_b(), 3);
}

TEST(FunctionTest, err_overload_overloading_square_brackets) {
    Function_list conteiner(5);
    EXPECT_ANY_THROW(conteiner[-1]);
}