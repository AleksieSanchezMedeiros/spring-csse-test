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
        printf("POWER OF 2 TEST LOOP PASSED\n");
    }else {
        printf("POWER OF 2 TEST LOOP FAILED\n");
    }

    //reset for second test
    numOfPowers = 0;

    for (int i = 0; i <= 100; i++) {
        numOfPowers += isPowerOfTwoNonLoop(i);
    }
    //if 7 then passed
    if (numOfPowers == 7) {
        printf("POWER OF 2 TEST NON LOOP PASSED\n");
    }else {
        printf("POWER OF 2 TEST NON LOOP FAILED\n");
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
        printf("PRIME NUM TEST PASSED\n");
    }else {
        printf("PRIME NUM TEST FAILED\n");
    }
}

//reduce the fraction
void reduceFrac(int numerator, int denominator) {

}

//runs test methods
int main() {
    pow2Test(); //tests loop and non loop at the same time
    primeTest();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.