#include <gtest/gtest.h>

#include <functions/functions.h>




TEST(FunctionsTests, calculating_the_function) {
    Function_list container;
    float parameter_a = 4.00f;
    float parameter_b = 3.00f;
    float argument = 2.00f;
    float value;
    Function item(parameter_a, parameter_b, POWERFUNCTION);
    container.add_element(item, 0);
    value = container.calculating_the_function(argument);
    EXPECT_EQ(value, 32.00f);
}


TEST(FunctionsTests, calculating_the_function_1) {
    Function_list conteiner;
    float parameter_c = 5.00f;
    float argument = 1.00f;
    float value;
    Function item(parameter_c, NATUREFUNCTION);
    conteiner.add_element(item, 0);
    value = conteiner.calculating_the_function(0);
    EXPECT_EQ(value, 0);
}


TEST(FunctionsTests, calculating_the_diff) {
    Function_list conteiner;
    float parameter_a = 5.00f;
    float parameter_b = 3.00f;
    float diff_parameter_a;
    float diff_parameter_b;
    Function item(parameter_a, parameter_b, POWERFUNCTION);
    conteiner.add_element(item, 0);
    diff_parameter_a = conteiner.calculating_the_diff(0).get_parameter_a();
    diff_parameter_b = conteiner.calculating_the_diff(0).get_parameter_b();
    EXPECT_EQ(diff_parameter_a, 15.00f);
    EXPECT_EQ(diff_parameter_b, 2.00f);
}


