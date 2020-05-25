#include "MyBigNumber.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

BigNumber MyBigNumber::multByOneDigit(const BigNumber &num1, const int8_t &num2) {  //zarb tak ragham
    if(num2>9 | num2 < 0){
        throw out_of_range("multByOneDigit bayad yek raqmi bashad!!!");
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

BigNumber operator<<(const BigNumber &myBig, unsigned shift) {   //shift b chap  ,,,ezafe kardn tedad argham adad
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

BigNumber operator *(const BigNumber &num1, const BigNumber &num2) {        //operator *
    const BigNumber bMax = BigNumber::unsignedMax(num1, num2);
    const  BigNumber bMin = BigNumber::unsignedMin(num1, num2);

    size_t i{0};
    BigNumber zarb = "0";

    for (; i < bMin.getNumOfDigits(); ++i) {
        zarb = zarb + ((MyBigNumber::multByOneDigit(bMax, bMin[i])) << i );   //ba estefade az zarb tak ragham va <<
    }
    if(num1.getSign() == num2.getSign()){
        zarb.setSign(true);
    }else{
        zarb.setSign(false);
    }

    return zarb;
}

BigNumber MyBigNumber::power(const BigNumber & myBig , const unsigned int myNumber) {         //tavan
    BigNumber power = myBig;
    BigNumber a {1};
    if( myNumber == 0 ){    //b tavane sefr
        return a;
    }
    size_t i{1};
    for (; i < myNumber; ++i) {
        power = power * myBig;
    }
    return  power;
}

BigNumber MyBigNumber::operator()( unsigned andis , unsigned num) {     //operator (), az andis b andaze num  az adad joda mikonad
    if(num > numOfDigits || andis > numOfDigits - 1){
        throw out_of_range("operator() , kharej az mahdoode!!!");
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

MyBigNumber::MyBigNumber(BigNumber myBig) {
    sign = myBig.getSign();
    numOfDigits = myBig.getNumOfDigits();
    numArray = new int8_t[numOfDigits];
    for (int i = 0; i < numOfDigits ; ++i) {
        numArray[i] = myBig[i];
    }
}


MyBigNumber::MyBigNumber(const std::string &str) : BigNumber(str) {}
MyBigNumber::MyBigNumber( const char * myCharArray ) :BigNumber(myCharArray){}
MyBigNumber::MyBigNumber(const long & intNum ) : BigNumber(intNum){ }

MyBigNumber & MyBigNumber:: operator=(const MyBigNumber & myBigNumber){
    if( &myBigNumber != this ){
        sign = myBigNumber.sign;
        numOfDigits = myBigNumber.numOfDigits;
        delete[] numArray;
        numArray = new int8_t(numOfDigits);
        for (int i = 0; i <numOfDigits ; ++i) {
            numArray[i] = myBigNumber[i];
        }
    }
    return *this;
}

std::string MyBigNumber::toString() const {  //override
    ostringstream output;
    output << "I am a MyBigNumber Object" << endl;
    output << BigNumber::toString();
    return output.str();
}

std::string MyBigNumber::toString( int numOfHello ){   //overload
    ostringstream output;
    for (int i = 1; i <= numOfHello ; ++i) {
        output <<"Hello" <<endl;
    }
    output << BigNumber::toString();
    return output.str();

}

MyBigNumber::MyBigNumber(const MyBigNumber &myBig) : BigNumber(myBig) {}   // copy constructor
MyBigNumber::MyBigNumber(MyBigNumber &&myBig) noexcept : BigNumber(myBig) {}   // move constructor
MyBigNumber &MyBigNumber::operator=(MyBigNumber &&myBig) noexcept {    // move assignment overloading
    if( &myBig != this ){
        sign = myBig.sign;
        numOfDigits = myBig.numOfDigits;
        delete [] numArray;
        numArray = myBig.numArray;
        myBig.numArray = nullptr;
    }
    return *this;
}

BigNumber operator / ( const BigNumber & num1, const BigNumber & num2){         //operatoe /
    MyBigNumber bMax = BigNumber::unsignedMax(num1, num2);
    MyBigNumber bMin = BigNumber::unsignedMin(num1, num2);

    if(num2 == "0"){
        throw out_of_range("makhraj nmitavanad 0 bashad!!");
    }
    if(num1 == num2){
        return 1;
    }
    if(num1 == bMin){
        return "0";
    }

    else {
        unsigned digit1 = bMax.getNumOfDigits();
        unsigned digit2 = bMin.getNumOfDigits();

        MyBigNumber temp2 = bMax(digit1 - 1, digit2);  //joda kardan az adad bozorg tar
        if (temp2 < bMin) {
            temp2 = bMax(digit1 - 1, digit2 + 1);
        }

        unsigned digit3 = temp2.getNumOfDigits();       // tekan mikhorad
        unsigned digit4 = temp2.getNumOfDigits();       // sabet

        MyBigNumber hasel;
        MyBigNumber baghimande;

        if (bMax.getSign() == bMin.getSign()) {         // sign javab naha e
            hasel.sign = true;
        } else {
            hasel.sign = false;
        }

        if (temp2.getNumOfDigits() == bMin.getNumOfDigits()) {                          //numOfDigits javab nahae
            hasel.numOfDigits = bMax.getNumOfDigits() - bMin.getNumOfDigits() + 1;
        } else {
            hasel.numOfDigits = bMax.getNumOfDigits() - bMin.getNumOfDigits();
        }

        hasel.numArray = new int8_t[hasel.numOfDigits];

        int j = 1;
        for (int i = hasel.getNumOfDigits() - 1 ; i >= 0  ; --i) {
            if(temp2.getNumOfDigits() == bMin.getNumOfDigits()){        //halate aval
                if(temp2 < bMin){    //baraye charkhesh
                  hasel[i] = 0;
                }else {
                  hasel[i] = temp2[digit3 - 1] / bMin[digit2 - 1];
                    if( temp2 < hasel[i] * bMin){
                        hasel[i] = hasel[i] - 1;
                    }
               }
            } else{                                                     //halate dovom
                if(temp2 < bMin){    //baraye charkhesh
                    hasel[i] = 0;
                }else {
                    hasel[i] =  ((temp2[digit3 - 1] * 10) + temp2[digit3-2] )/ bMin[digit2 - 1];
                    if( temp2 < hasel[i] * bMin){
                        hasel[i] = hasel[i] - 1;
                    }
                }
            }
            baghimande = BigNumber::unsignedSubtract(temp2, (hasel[i] * bMin));
            if(i>0) {         //bare akhar chizi nadarim biad pain braye temp2[0]
                temp2 = baghimande;
                temp2 = (temp2 << 1);
                temp2[0] = bMax[digit1 - digit4 - j];
                digit3 = temp2.numOfDigits;
                j++;
            }
    }
    return hasel;
        }

    }

BigNumber operator % ( const BigNumber & num1, const BigNumber & num2){         //operatoe %
    MyBigNumber bMax = BigNumber::unsignedMax(num1, num2);
    MyBigNumber bMin = BigNumber::unsignedMin(num1, num2);

    if(num2 == "0"){
        throw out_of_range("makhraj nmitavanad 0 bashad!!");
    }
    if(num1 == num2){
        return 1;
    }
    if(num1 == bMin){
        return "0";
    }

    else {
        unsigned digit1 = bMax.getNumOfDigits();
        unsigned digit2 = bMin.getNumOfDigits();

        MyBigNumber temp2 = bMax(digit1 - 1, digit2);

        if (temp2 < bMin) {
            temp2 = bMax(digit1 - 1, digit2 + 1);
        }
        unsigned digit3 = temp2.getNumOfDigits();
        unsigned digit4 = temp2.getNumOfDigits();

        MyBigNumber hasel;
        MyBigNumber baghimande;

        if (bMax.getSign() == bMin.getSign()) {
            hasel.sign = true;
        } else {
            hasel.sign = false;
        }

        if (temp2.getNumOfDigits() == bMin.getNumOfDigits()) {
            hasel.numOfDigits = bMax.getNumOfDigits() - bMin.getNumOfDigits() + 1;
        } else {
            hasel.numOfDigits = bMax.getNumOfDigits() - bMin.getNumOfDigits();
        }

        hasel.numArray = new int8_t[hasel.numOfDigits];

        int j = 1;
        for (int i = hasel.getNumOfDigits() - 1 ; i >= 0  ; --i) {
            if(temp2.getNumOfDigits() == bMin.getNumOfDigits()){
                if(temp2 < bMin){    //baraye charkhesh
                    hasel[i] = 0;
                }else {
                    hasel[i] = temp2[digit3 - 1] / bMin[digit2 - 1];
                    if( temp2 < hasel[i] * bMin){
                        hasel[i] = hasel[i] - 1;
                    }
                }
            } else{
                if(temp2 < bMin){    //baraye charkhesh
                    hasel[i] = 0;
                }else {
                    hasel[i] =  ((temp2[digit3 - 1] * 10) + temp2[digit3-2] )/ bMin[digit2 - 1];
                    if( temp2 < hasel[i] * bMin){
                        hasel[i] = hasel[i] - 1;
                    }
                }
            }

            baghimande = BigNumber::unsignedSubtract(temp2, (hasel[i] * bMin));
            if(i>0) {         //bare akhar chizi nadarim biad pain braye temp2[0]
                temp2 = baghimande;
                temp2 = (temp2 << 1);
                temp2[0] = bMax[digit1 - digit4 - j];
                digit3 = temp2.numOfDigits;
                j++;
            }
        }
        return baghimande;
    }
}









