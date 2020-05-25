#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H
#include"BigNumber.h"

class MyBigNumber: public BigNumber {
private:

public:
    static BigNumber multByOneDigit( const BigNumber& num1 , const int8_t& num2 );    //zarb tak ragham
    friend BigNumber operator << ( const BigNumber& myBig , unsigned shift );          //shift b chap  ,,,ezafe kardn tedad argham adad
    friend BigNumber operator *( const BigNumber & num1, const BigNumber & num2);       //operator *
    static  BigNumber power ( const BigNumber & myBig , const unsigned int  myNumber ); //tavan

    BigNumber operator () ( unsigned andis , unsigned num );  //operator (), az andis b andaze num  az adad joda mikonad

    MyBigNumber( BigNumber myBig);
    MyBigNumber(){};
    MyBigNumber( const std::string & str );
    MyBigNumber( const char * myCharArray ) ;
    MyBigNumber(const long & intNum );
    MyBigNumber & operator=(const MyBigNumber & myBigNumber);
    MyBigNumber ( const MyBigNumber & myBig );          // copy constructor
    MyBigNumber ( MyBigNumber && myBig ) noexcept;      // move constructor
    MyBigNumber & operator=(MyBigNumber && myBig) noexcept ;   // move assignment overloading


    std::string toString() const;          //override
    std::string toString( int numOfHello );   //overload

    friend BigNumber operator / ( const BigNumber & num1, const BigNumber & num2);          //operatoe /
    friend BigNumber operator % ( const BigNumber & num1, const BigNumber & num2);          //operatoe %


};


#endif //TA14_MYBIGNUMBER_H
