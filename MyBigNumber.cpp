#include "MyBigNumber.h"
#include <stdexcept>
using namespace std;


BigNumber MyBigNumber::multByOneDigit(const BigNumber &num1, const int8_t &num2) {
    if(num2>9 | num2 < 0){
        throw invalid_argument("bayad yek raqmi bashad!");
    }

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

BigNumber operator<<(const BigNumber &myBig, unsigned shift) {
    MyBigNumber temp;

    temp.sign = myBig.getSign();
    temp.numOfDigits = myBig.getNumOfDigits()+ shift;
    temp.numArray = new int8_t[temp.numOfDigits];
    size_t i{0};
    for( ; i < shift; ++i){
        temp[i] = 0 ;
    }
    size_t j{0};
    for( ; i < temp.numOfDigits; ++i){
        temp[i] = myBig[j];
        ++j;
    }
    return temp;
}

BigNumber operator *(const BigNumber &num1, const BigNumber &num2) {
    const BigNumber bMax = BigNumber::unsignedMax(num1, num2);
    const  BigNumber bMin = BigNumber::unsignedMin(num1, num2);

    size_t i{0};
    BigNumber sum = "0";

    for (; i < bMin.getNumOfDigits(); ++i) {
    sum =  sum +  ((MyBigNumber::multByOneDigit(bMax,bMin[i])) <<i );
    }
    if(num1.getSign() == num2.getSign()){
        sum.setSign(true);
    }else{
        sum.setSign(false);
    }

    return sum;
}

BigNumber MyBigNumber::power(const BigNumber & myBig , const unsigned int myNumber) {
    BigNumber power = myBig;
    BigNumber a {1};
    if( myNumber == 0 ){
        return a;
    }
    size_t i{1};
    for (; i < myNumber; ++i) {
        power = power * myBig;
    }
    return  power;
}

BigNumber MyBigNumber::operator()( unsigned andis, unsigned num) {
    if(num > numOfDigits){                                                 ///////// baghie shart ha ???
        throw invalid_argument("bayad yek raqmi bashad!");
    }

    MyBigNumber myBig;
    myBig.sign = true;
    myBig.numOfDigits = num;
    myBig.numArray = new int8_t[myBig.numOfDigits];

    unsigned int i = (andis - num)+1;
        for (int j = 0; j <num ; ++j) {
            myBig[j] = numArray[i];
            ++i;
        }

    return myBig;
}







