#include "calculator.h"
#include <limits>
#include <stdexcept>
using namespace std;

int Calculator::add(int a, int b) {
    if ((b > 0 && a > numeric_limits<int>::max() - b) || (b < 0 && a < numeric_limits<int>::min() - b)) {
        throw overflow_error("Overflow Error in Addition");
    }

    return a + b;
}

int Calculator::sub(int a, int b) {
    // if ((b < 0 && a > numeric_limits<int>::max() + b) || (b > 0 && a < numeric_limits<int>::min() + b)) {
    //     throw overflow_error("Overflow Error in Subtraction");
    // }

    // return a - b;

    return add(a, -b);
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0 && a > numeric_limits<int>::max() / b) {
            throw overflow_error("Overflow Error in Multiplication");
        } else if (b < 0 && b < numeric_limits<int>::min() / a) {
            throw overflow_error("Overflow Error in Multiplication");
        }
    } else if (a < 0) {
        if (b > 0 && a < numeric_limits<int>::min() / b) {
            throw overflow_error("Overflow Error in Multiplication");
        }
        if (b < 0 && a < numeric_limits<int>::max() / b) {
            throw overflow_error("Overflow Error in Multiplication");
        }
    }

    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw invalid_argument("Division by zero");
    }

    if (a == numeric_limits<int>::min() && b == -1) {
        throw overflow_error("Overflow Error in Division");
    }

    return (int)(a / b);
}