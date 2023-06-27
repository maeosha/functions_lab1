#include <gtest/gtest.h>

#include <functions/functions.h>




TEST(FunctionsTests, calculating_the_function) {
    Function_list conteiner;
    float parameter_a = 4.00f;
    float parameter_b = 3.00f;
    float argument = 2.00f;
    float value;
    auto item = std::make_shared<Power_function>(parameter_a, parameter_b);
    conteiner.add_element(item, 0);
    value = conteiner[0]->calculating_the_function(argument);
    EXPECT_EQ(value, 32.00f);
}


TEST(FunctionsTests, calculating_the_function_1) {
    Function_list conteiner;
    float parameter_c = 5.00f;
    float argument = 1.00f;
    float value;
    auto item = std::make_shared<Nature_function>(parameter_c);
    conteiner.add_element(item, 0);
    value = conteiner[0]->calculating_the_function(argument);;
    EXPECT_EQ(value, 0);
}


TEST(FunctionsTests, calculating_the_diff) {
    Function_list conteiner;
    float parameter_a = 5.00f;
    float parameter_b = 3.00f;
    float diff_parameter_a;
    float diff_parameter_b;
    auto item = std::make_shared<Power_function>(parameter_a, parameter_b);
    auto diff_item = item->calculating_the_diff();
    diff_parameter_a = item->get_parameter_a();
    EXPECT_EQ(diff_parameter_a, 5);
}

TEST(FunctionTests, finding_min_derivative) {
    Function_list conteiner;
    int min_index;
    float min_value;
    for (int index = 0; index < 30; index++) {
        auto item = std::make_shared<Power_function>(1, 1);
        conteiner.add_element(item, index);
    }
    min_index = conteiner.finding_min_derivative(1);
    min_value = conteiner[min_index]->calculating_the_function(1);
    EXPECT_EQ(min_index, 30);
    EXPECT_EQ(min_value, 0);
}

TEST(FunctionTest, overload_overloading_square_brackets) {
    Function_list conteiner;
    auto item = std::make_shared<Power_function>(2, 3);
    conteiner.add_element(item, 0);
    EXPECT_EQ(item->get_parameter_a(), 2);
}


