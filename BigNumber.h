#ifndef TA14_BIGNUMBER_H
#define TA14_BIGNUMBER_H

#include <cstdint>
#include <string>
#include <regex>

class BigNumber {
    friend std::ostream& operator<<( std::ostream & output, const BigNumber & myBig );  //operator <<
    friend std::istream& operator>>( std::istream & input, BigNumber & myBig );         //operator >>
    friend BigNumber operator+( const BigNumber & num1, const BigNumber & num2);        //operator +
    friend BigNumber operator-( const BigNumber & num1, const BigNumber & num2);        //operator -

protected:
    bool sign;
    int8_t * numArray = nullptr;
    unsigned numOfDigits;

    bool validate( const std::string & str, const std::string & pattern);
    unsigned numOfTrimCharsOnLeft( const std::string & str );

    static bool unsignedGreaterOrEqual( const BigNumber& num1, const BigNumber& num2);
    static bool unsignedLessOrEqual( const BigNumber& num1, const BigNumber& num2);

public:

    static BigNumber unsignedMax( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedMin( const BigNumber& num1, const BigNumber& num2);
    static BigNumber unsignedAdd( const BigNumber& num1, const BigNumber& num2 );
    static BigNumber unsignedSubtract( const BigNumber& num1, const BigNumber& num2 );


    BigNumber( const std::string & str );
    BigNumber( const char * myCharArray ) : BigNumber((std::string) myCharArray) {}
    BigNumber(const long & intNum );
    BigNumber ( const BigNumber & myBig );   // copy constructor
    BigNumber ( BigNumber && myBig ) noexcept;  // move constructor
    ~BigNumber();
    void setValues( const std::string & str );
    bool getSign() const;
    unsigned int getNumOfDigits() const;
    BigNumber & operator=(const BigNumber & rightNum);
    BigNumber & operator=(BigNumber && rightNum) noexcept ;   // move assignment overloading
    BigNumber operator-() const; //gharine kardan bigNumber
    int operator[](size_t index) const;
    int8_t& operator[](size_t index);
    bool operator==( const BigNumber & myBig) const;        //operator ==
    bool operator!=( const BigNumber & myBig) const;        //operator !=
    bool operator>=( const BigNumber & myBig) const;        //operator >=
    bool operator<=( const BigNumber & myBig) const;        //operator <=
    bool operator>( const BigNumber & myBig) const;         //operator >
    bool operator<( const BigNumber & myBig) const;         //operator <
    BigNumber absoluteValue() const;     // ghadre motlagh
    BigNumber operator>>( unsigned shift );     //operator shift ,,numOfDigit rakam mikonad az rast biroon mindaze

    BigNumber & operator++();    //operator ++ piri
    BigNumber  operator++(int);  //operator ++ post
    BigNumber & operator--();    //operator -- piri
    BigNumber  operator--(int);  //operator -- post
    BigNumber(){}
    void setSign(bool mySign);
    std::string toString() const;

};


#endif //TA14_BIGNUMBER_H
