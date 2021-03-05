

#include <string>
#include "calculator.h"
#include <sstream>

namespace lab4 {
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

    void calculator::parse_to_infix(std::string &input_expression) {
        std::string temp = "";
        std::string num = "";

        for (int i = 0; i < input_expression.length(); i++) {
            std::string string1 = input_expression.substr(i,1);

            if (is_number(string1)) {
                num += string1;
            }
            else if (is_operator(string1)) {
                if (num.length() > 0) {
                    temp += num + "";
                    num = "";
                }
                temp += string1;

                if (i < input_expression.length() -1)
                    temp += "";
            }
            else if (string1.compare("") == 0) {
                if (num.length() > 0) {
                    temp += num + "";
                    num = "";
                }
            }
        }
        if (num.length() > 0) {
            temp += num;
            num = "";
        }
        std::istringstream ss(temp);
        std::string string2;

        while (std::getline(ss, string2, ' '))
        {
            infix_expression.enqueue(string2);
        }
        input_expression = temp;
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {

    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {

    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string) {

    }

    bool is_operator(std::string input_string) {

    }

    int get_number(std::string input_string) {

    }

    std::string get_operator(std::string input_string) {

    }

    int operator_priority(std::string operator_in) {

    }
}