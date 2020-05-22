#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H
#include"BigNumber.h"

class MyBigNumber: public BigNumber {
private:

public:
    static BigNumber multByOneDigit( const BigNumber& num1 , const int8_t& num2 );
    friend BigNumber operator << ( const BigNumber& myBig , unsigned shift );
    friend BigNumber operator *( const BigNumber & num1, const BigNumber & num2);
    static  BigNumber power ( const BigNumber & myBig , const unsigned int  myNumber );
};


#endif //TA14_MYBIGNUMBER_H
