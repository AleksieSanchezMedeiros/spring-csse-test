#include <iostream>

//power of two using loops
bool isPowerOfTwoLoop(int n) {
    if (n <= 0) return false;

    while (n % 2 == 0) n /= 2;

    if (n == 1) return true;
    else return false;
}

//power of two without using loops
bool isPowerOfTwoNonLoop(int n) {
    //dereference?
    return false;
}

//test power of 2 method
void pow2Test() {

    //check for number of powers of 2, 7 of them should be found between 0 and 100
    int numOfPowers = 0;
    for (int i = 0; i <= 100; i++) {
            numOfPowers += isPowerOfTwoLoop(i);
    }
    //if 7 then passed
    if (numOfPowers == 7) {
        printf("Power Of 2 Test Loop PASSED\n");
    }else {
        printf("Power Of 2 Test Loop FAILED\n");
    }

    //reset for second test
    numOfPowers = 0;

    for (int i = 0; i <= 100; i++) {
        numOfPowers += isPowerOfTwoNonLoop(i);
    }
    //if 7 then passed
    if (numOfPowers == 7) {
        printf("Power Of 2 Test Non Loop PASSED\n");
    }else {
        printf("Power Of 2 Test Non Loop FAILED\n");
    }
}

//checks if number is prime
bool isNumPrime(int n) {
    //1 and 0 are not prime numbers
    if (n <= 1) return false;

    //start at 2, dont need to check division by 1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    //true if not found
    return true;
}

//test prime number method
void primeTest() {
    //checks for number of prime numbers found between 0 and 100, should be 25
    int numOfPrime = 0;
    for (int i = 0; i <= 100; i++) {
        numOfPrime += isNumPrime(i);
    }
    if (numOfPrime == 25) {
        printf("Prime Num Test PASSED\n");
    }else {
        printf("Prime Num Test FAILED\n");
    }
}

//fraction class for fraction reducer
class Fraction {
    public:
        int numerator;
        int denominator;

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    bool equals(Fraction other) {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

//reduce the fraction
Fraction reduceFrac(Fraction input) {
    //make numerator positive if denom is neg
    //copied over from CSS143 fraction assignment
    if(input.denominator < 0){
        input.numerator *= -1;
        input.denominator *= -1;
    }

    int numberToDivide = 2;
    //continue until the break or until the denominator is 1
    while(input.numerator != 1 && input.denominator!= 1){
        //divide by the current prime number, will repeat until no longer able to then moves to the next prime number
        //i think this could be a switch statement, but i don't really know how to use those
        if(input.numerator % numberToDivide == 0 && input.denominator % numberToDivide == 0){
            input.numerator = input.numerator / numberToDivide;
            input.denominator = input.denominator / numberToDivide;
        } else if(numberToDivide == 2){
            numberToDivide = 3;
        } else if(numberToDivide == 3){
            numberToDivide = 5;
        } else if(numberToDivide == 5){
            numberToDivide = 7;
        } else if(numberToDivide == 7){
            break;
        }
    }
    return input;
}

//reduce fraction tester, tests 3 different cases, no edge cases
void fractionReduceTest() {
    Fraction inputs[4] = {Fraction(1, 2),
                        Fraction(2, 4),
                        Fraction(4, 2),
                        Fraction(6, 8)};

    Fraction outputs[4] = {Fraction(1, 2),
                        Fraction(1, 2),
                        Fraction(2, 1),
                        Fraction(3, 4)};

    //has to stop at 4, no clue why
    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction expected = outputs[i];
        Fraction actual = reduceFrac(input);

        if(!expected.equals(actual)) {
            std::cout << "Tests failed, current case is: \n" << inputs[i].to_string() << std::endl;
        }
    }

    std::cout << "Tests passed!" << std::endl;
}

//runs test methods
int main() {
    pow2Test(); //tests loop and non loop at the same time
    primeTest();
    fractionReduceTest();
}