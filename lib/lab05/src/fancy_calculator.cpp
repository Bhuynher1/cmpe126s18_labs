#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"

namespace lab5{
    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);


    //CALCULATOR FUNCTIONS
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream *in = new lab1::expressionstream(input_expression);

        while(in->get_current_token() != "\0") {
            infix_expression.enqueue(in->get_current_token());
            in->get_next_token();
        }
    }

    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        stack stack1;
        queue temp = infix_expression;

        while (!temp.isEmpty()){
            if (is_number(temp.top())){
                postfix_expression.enqueue(temp.top());
            }
            else if (is_operator(temp.top())){
                while (!stack1.isEmpty() && operator_priority(temp.top()) <= operator_priority(stack1.top())){
                    postfix_expression.enqueue(stack1.top());
                    stack1.pop();
                }

                stack1.push(temp.top());
            }
            else if (temp.top() == "("){
                stack1.push(temp.top());
            }
            else if (temp.top() == ")"){
                while (stack1.top() != "("){
                    postfix_expression.enqueue(stack1.top());
                    stack1.pop();
                }
                if (stack1.top() == "(") {
                    stack1.pop();
                }
            }
            temp.dequeue();
        }

        while (!stack1.isEmpty()) {
            if (stack1.top() == ")")
                stack1.pop();
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

    int calculator::calculate() {
        stack stack2;
        queue postfix = postfix_expression;
        int num1, num2;

        while(!postfix.isEmpty()) {
            if (is_operator(postfix.top())) {
                num2 = get_number(stack2.top());
                stack2.pop();

                num1 = get_number(stack2.top());
                stack2.pop();

                int answer;
                if(postfix.top() == "*")
                    answer = num1 * num2;
                else if(postfix.top() == "/")
                    answer = num1 / num2;
                else if(postfix.top() == "+")
                    answer = num1 + num2;
                else if(postfix.top() == "-")
                    answer = num1 - num2;
                stack2.push(std::to_string(answer));
            }

            else if (is_number(postfix.top()))
                stack2.push(postfix.top());
            postfix.dequeue();
        }

        return std::stoi(stack2.top());
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        calculator temp = RHS;
        std::cout << "Infix: ";

        for (int i = 0; i < temp.infix_expression.queueSize(); i++) {
            stream << temp.infix_expression.top();
            temp.infix_expression.dequeue();
            if(temp.infix_expression.isEmpty()){

            }
            else
                stream << ",";
        }

        std::cout << "Postfix: ";

        for (int i = 0; i < temp.postfix_expression.queueSize(); i++) {
            stream << temp.postfix_expression.top();
            temp.postfix_expression.dequeue();
            if(temp.postfix_expression.isEmpty()){

            }
            else
                stream << ",";
        }
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
        queue temp1 = infix_expression;
        queue temp2 = postfix_expression;

        std::cout << "Infix: ";
        while (!temp1.isEmpty()) {
            std::cout << temp1.top();
            temp1.dequeue();
            if (temp1.isEmpty()){}
            else std::cout << ",";
        }
        std::cout << std::endl;

        std::cout << "Postfix: ";
        while (!temp2.isEmpty()) {
            std::cout << temp2.top();
            temp2.dequeue();
            if (temp2.isEmpty()){}
            else std::cout << ",";
        }
        std::cout << std::endl;
    }
}

