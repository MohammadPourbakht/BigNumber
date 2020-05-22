#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H
#include"BigNumber.h"

class MyBigNumber: public BigNumber {
private:

public:
    static BigNumber multByOneDigit( const BigNumber& num1 , const int8_t& num2 );
    friend BigNumber operator << ( const BigNumber& myBig , unsigned shift );
};


#endif //TA14_MYBIGNUMBER_H
