#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    cout << boolalpha;  //true or false
    MyBigNumber big1 = "63697";
    MyBigNumber big2 = -13698;
    MyBigNumber big3 ;
    MyBigNumber big4 ;

    try {


        cout << "BigNumber 1: " << big1 << endl;    //operator <<
        cout << "BigNumber 2: " << big2 << endl;    //operator <<
        cout << "Enter BigNumber 3: ";                   //operator >>
        cin >> big3;                                     //operator >>
        cout << "BigNumber 3: " << big3 << endl << endl;         //operator >> and <<

        cout << "BigNumber 1 + BigNumber 2 =  " << (big1 + big2) << endl;        //operator +
        cout << "BigNumber 1 - BigNumber 2 =  " << (big1 - big2) << endl;        //operator -
        cout << "BigNumber 2 * 3 = :  " << MyBigNumber::multByOneDigit(big2, 3) << endl;   //multByOneDigit
        cout << "BigNumber 1 * BigNumber 2 =  " << (big1 * big2) << endl;       //operator *
        cout << "BigNumber 1 / BigNumber 2 =  " << (big1 / big2) << endl;       //operator /
        cout << "BigNumber2 ( 2 , 2 ) az andis 2 b toole 2 : " << big2(2, 2) << endl;  // operator ()
        cout << "BigNumber 1 ^ 2 =  " << MyBigNumber::power(big1, 2) << endl;         // tabe power

        cout << "Sign BigNumber 1 : " << big1.getSign() << endl;   //getSign
        cout << "Tedad arghame BigNumber 1 : " << big1.getNumOfDigits() << endl;  //getNumOfDigits

        int number = big2[0];                               //operator[]
        cout << "BigNumber 2 [0] : " << number << endl;     //operator[]

        cout << "++ BigNumber 2 : " << (++big2) << endl;      //operator ++ piri
        cout << "BigNumber 2 ++ : " << (big2++) << endl;      //operator ++ post
        cout << "-- BigNumber 2 : " << (--big2) << endl;      //operator -- piri
        cout << "BigNumber 2 -- : " << (big2--) << endl;      //operator -- post

        big4 = big2;  //operator =
        cout << "-BigNumber 4: " << (-big4) << endl;          //operator -
        cout << "BigNumber 4: " << big4 << endl;     //operator =


        cout << "BigNumber 1 < BigNumber 2 : " << (big1 < big2) << endl;      //operator <
        cout << "BigNumber 1 > BigNumber 2 : " << (big1 > big2) << endl;      //operator >
        cout << "BigNumber 1 <= BigNumber 2 : " << (big1 <= big2) << endl;    //operator <=
        cout << "BigNumber 1 >= BigNumber 2 : " << (big1 >= big2) << endl;    //operator >=
        cout << "BigNumber 2 == BigNumber 4 : " << (big2 == big4) << endl;    //operator ==
        cout << "BigNumber 1 != BigNumber 2 : " << (big1 != big4) << endl;    //operator !=

        cout << "absoluteValue( BigNumber 2 ) : " << big2.absoluteValue() << endl;   //absoluteValue

        cout << "unsignedMin ( BigNumber 1 , BigNumber 2 ) : " << BigNumber::unsignedMin(big1, big2) << endl;   //unsignedMin
        cout << "unsignedMax ( BigNumber 1 , BigNumber 2 ) : " << BigNumber::unsignedMax(big1, big2)<< endl;   //unsignedMax

        big2.setSign(false);                                   //setSign
        big2.setValues("3746");                                     //setValues
        cout << "BigNumber 2 bad az taghir: " << big2 << endl;         //setSign and setValues


        cout << "2 shift >> BigNumber 1 : " << (big1 >> 2) << endl;     //shift >>
        cout << "2 shift << BigNumber 2 : " << (big2 << 2) << endl;     //shift <<

    }
    catch (out_of_range e ){
        cout << e.what() << endl;
    }







    return 0;
}
