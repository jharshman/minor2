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
                string num;
                bool sign;

        public:
                /* Constructors & Destructors */
                BigInt();
                BigInt(string num);
                BigInt(string num, bool sign);
                BigInt(int num);
                ~BigInt() {};
                BigInt(const BigInt &orig);

                /* gets and sets */
                bool getSign() const { return sign; }
                string getNum() const { return num; }

                void setNum(string num);
                void setSign(bool sign);

                /* Common methods taken from Java 8 API */
                BigInt absolute();

                /* Overloaded Operators */ 
                bool operator>(BigInt bi);
                bool operator<(BigInt bi);
                bool operator==(BigInt bi); // not required by assignment but comes in handy
                void operator=(BigInt bi); 
                BigInt operator+(BigInt bi); 
                BigInt operator-(BigInt bi);
                BigInt operator*(BigInt bi);
                //BigInt &operator[](int num);
                //operator string();
                
        private:
                /* helper comparative methods */
                bool equals(BigInt a, BigInt b);
                bool less(BigInt a, BigInt b);
                bool greater(BigInt a, BigInt b);

                /* helper methods for math operations */
                string add(string a, string b);
                string subtract(string a, string b);
                string multiply(string a, string b);

                /* helper methods */
                //string toString(long long num);
                //long long toInt(string num);

}; 
                
                ostream &operator<<(ostream &out, const BigInt &bi);
                istream &operator>>(istream &in, BigInt &bi);


#endif
