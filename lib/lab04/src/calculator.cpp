#include <string>
#include "calculator.h"
#include <sstream>
#include <iostream>


namespace lab4 {
    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

    void printinfo();


    // CALCULATOR FUNCTIONS
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream *in = new lab1::expressionstream(input_expression);

        while(in->get_current_token() != "\0") {
            infix_expression.enqueue(in->get_current_token());
            in->get_next_token();
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo stack1;
        lab3::fifo temp = infix_expression;

        while (!temp.is_empty()){
            if (is_number(temp.top())){
                postfix_expression.enqueue(temp.top());
            }
            else if (is_operator(temp.top())){
                while (!stack1.is_empty() && operator_priority(temp.top()) <= operator_priority(stack1.top())){
                    postfix_expression.enqueue(stack1.top());
                    stack1.pop();
                }
                while (stack1.is_empty()) {
                    std::cout << "Operator stack is empty";
                }

                stack1.push(temp.top());
            }
            else if (temp.top() == "("){
                stack1.push(temp.top());
            }
            else if (temp.top() == ")"){
                while (stack1.top() != "("){
                    if (stack1.top() == "(") continue;
                    else{
                        postfix_expression.enqueue(stack1.top());
                        stack1.pop();
                    }
                }
                stack1.pop();
            }
            temp.dequeue();
        }
        while (!stack1.is_empty()) {
            if (stack1.top() == ")") stack1.pop();
            else {
                postfix_expression.enqueue(stack1.top());
                stack1.pop();
            }
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        std::getline (stream, input);
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }

    int lab4::calculator::calculate() {
        lab3::lifo stack2;
        int num1, num2;

        while(!postfix_expression.is_empty())
        {
            if(is_number(postfix_expression.top()))
            {
                stack2.push(postfix_expression.top());
            }
            else {
                num2 = get_number(stack2.top());
                stack2.pop();

                num1 = get_number(stack2.top());
                stack2.pop();

                if(postfix_expression.top() == "*") {
                    stack2.push(std::to_string(num1 * num2));
                }
                else if(postfix_expression.top() == "/") {
                    stack2.push(std::to_string(num1 / num2));
                }
                else if(postfix_expression.top() == "+") {
                    stack2.push(std::to_string(num1 + num2));
                }
                else if(postfix_expression.top() == "-") {
                    stack2.push(std::to_string(num1 - num2));
                }
            }

            postfix_expression.dequeue();
        }

        std::cout << "Answer: " << num1 << std::endl;
        return std::stoi(stack2.top());
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        std::cout << "Infix: " << RHS.infix_expression.top();
        RHS.infix_expression.dequeue();

        while(!RHS.infix_expression.is_empty()) {
            stream << RHS.infix_expression.top();
            RHS.infix_expression.dequeue();
            if (RHS.infix_expression.is_empty()) continue;
            stream << ",";

        }

        std::cout << "\n";

        std::cout << "Postfix: " << RHS.postfix_expression.top();
        RHS.postfix_expression.dequeue();

        while(!RHS.postfix_expression.is_empty()) {
            std::cout << RHS.postfix_expression.top();
            RHS.postfix_expression.dequeue();
            if (RHS.infix_expression.is_empty()) continue;
            stream << ",";
        }
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string) {
        if (input_string >= "0" && input_string <= "9") {
            return true;
        }
        else
            return false;
    }

    bool is_operator(std::string input_string) {
        if (input_string == "("
            || input_string == ")"
            || input_string == "+"
            || input_string == "-"
            || input_string == "*"
            || input_string == "/") {
            return true;
        }
        else {
            return false;
        }
    }

    int get_number(std::string input_string) {
        return std::stoi(input_string);
    }

    std::string get_operator(std::string input_string) {
        return input_string;
    }

    int operator_priority(std::string operator_in) {
        if (operator_in == "*"
        || operator_in == "/" ) {
            return 2;
        }
        if (operator_in == "+"
        || operator_in == "-") {
            return 1;
        }
        else {
            return 0;
        }
    }

    void calculator::printinfo() {
        lab3::fifo temp1 = infix_expression;
        lab3::fifo temp2 = postfix_expression;

        std::cout << "Infix: ";
        while (!temp1.is_empty()) {
            std::cout << temp1.top();
            temp1.dequeue();
            if (temp1.is_empty()){}
            else std::cout << ",";
        }
        std::cout << std::endl;

        std::cout << "Postfix: ";
        while (!temp2.is_empty()) {
            std::cout << temp2.top();
            temp2.dequeue();
            if (temp2.is_empty()){}
            else std::cout << ",";
        }
        std::cout << std::endl;
    }
}