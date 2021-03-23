#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"
#include "math.h"

namespace lab5{
    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

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
            else if (is_operator(temp.top())){
                while (!stack1.isEmpty() && operator_priority(temp.top()) <= operator_priority(stack1.top())){
                    postfix_expression.enqueue(stack1.top());
                    stack1.pop();
                }

                stack1.push(temp.top());
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
                num2 = std::stoi(stack2.top());
                stack2.pop();

                num1 = std::stoi(stack2.top());
                stack2.pop();

                int answer;
                if(postfix.top() == "+")
                    answer = num1 + num2;
                else if(postfix.top() == "-")
                    answer = num1 - num2;
                else if(postfix.top() == "*")
                    answer = num1 * num2;
                else if(postfix.top() == "/")
                    answer = num1 / num2;
                else if(postfix.top() == "%")
                    answer = num1 % num2;
                else if(postfix.top() == "^")
                    answer = pow(num1, num2);
                stack2.push(std::to_string(answer));
            }

            else if (is_number(postfix.top()))
                stack2.push(postfix.top());
            postfix.dequeue();
        }

        return std::stoi(stack2.top());
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        stream << "Infix: ";
        while(!RHS.infix_expression.isEmpty()){
            stream << RHS.infix_expression.top();
            if (RHS.infix_expression.queueSize() != 1)
                stream << ",";
            RHS.infix_expression.dequeue();
        }
        stream << "\nPostfix: ";
        while(!RHS.postfix_expression.isEmpty()) {
            stream << RHS.postfix_expression.top();
            if (RHS.postfix_expression.queueSize() != 1)
                stream << ",";
            RHS.postfix_expression.dequeue();
        }
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string) {
        for (int i = 0; i < input_string.length(); i++)
            if (isdigit(input_string[i]) == false) return false;
        return true;
    }

    bool is_operator(std::string input_string) {
        if (input_string == "("
            || input_string == ")"
            || input_string == "+"
            || input_string == "-"
            || input_string == "*"
            || input_string == "/"
            || input_string == "%"
            || input_string == "^") {
            return true;
        }
        else {
            return false;
        }
    }

    int operator_priority(std::string operator_in) {
        if (operator_in == "^") {
            return 3;
        }
        if (operator_in == "*"
            || operator_in == "/"
            || operator_in == "%") {
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

}

