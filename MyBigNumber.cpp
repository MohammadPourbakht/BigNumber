#include "MyBigNumber.h"

using namespace std;


BigNumber MyBigNumber::multByOneDigit(const BigNumber &num1, const int8_t &num2) {
    MyBigNumber multiply;


    multiply.sign = true;
    multiply.numOfDigits = num1.getNumOfDigits() + 1;
    multiply.numArray = new int8_t[multiply.numOfDigits];

    size_t i{0};
    int8_t carry = 0;
    int8_t temp;

    for (; i < num1.getNumOfDigits(); ++i) {
        temp = (num1[i] * num2 ) + carry;
        multiply[i] = temp % 10;
        carry = temp / 10;
    }

     if (carry == 0) {
        multiply.numOfDigits -= 1;
    }else{
             multiply[i] = carry;
         }

    return multiply;
     }



