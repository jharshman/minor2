/**
 * biginteger.h
 * written by Josh Harshman
 * 07/14/15
 * */

#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__
#define MAXSIZE 1000 // any higher and you're doing it wrong 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

class BigInt {
        private:
                string number;
                bool sign;

        public:
                /* Constructors & Destructors */
                //BigInt();
                BigInt(string num=0); // defaults to zero
                BigInt(string num, bool sign);
                BigInt(int num);
                ~BigInt();
                BigInt(cont BigInt &orig);

                /* gets and sets */
                bool &getSign() const { return sign; }
                string &getNum() const { return num; }

                void setNum(string num);
                void setSign(bool sign);

                /* Common methods taken from Java 8 API */
                BigInt absolute();

                /* Overloaded Operators */ 
                BigInt operator+(BigInt bi);
                BigInt operator-(BigInt bi);
                BigInt operator*(BigInt bi);
                BigInt operator/(BigInt bi);

                

        private:
                /* helper comparative methods */
                bool equals(BigInt a, BigInt b);
                bool less(BigInt a, BigInt b);
                bool greater(BingInt a, BigInt b);

                /* helper methods for math operations */
                string add(BigInt a, BigInt b);
                string subtract(BigInt a, BigInt b);
                string multiply(BigInt a, BigInt b);

                /* helper methods for printing output */
                string toString(long long num);
                long long toInt(string num);

}; 


#endif
