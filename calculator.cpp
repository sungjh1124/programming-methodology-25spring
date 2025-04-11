#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    // TODO
    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        throw std::overflow_error("addoverflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if((a>0 && b<=INT_MIN+a) || (a<0 && b>INT_MAX+a)) {
        throw std::overflow_error("suboverflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a > 0 && b > INT_MAX / a) {
        throw std::overflow_error("muloverflow");
    }
    if (a < 0 && b > INT_MIN / a) {
        throw std::overflow_error("muloverflow");
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == INT_MIN && b == -1) {
        throw std::overflow_error("divoverflow");
    }
    return a / b;
}