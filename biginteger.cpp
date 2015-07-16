/**
 * biginteger.cpp
 * written by Josh Harshman
 * 07/14/15
 * */

#include "biginteger.h"

/* constructor for unknown signed values */
BigInt::BigInt(string num=0) {

        //on the off chance that the number is signed, 
        //and this constructor is called accidentally
        //or for invocations from other constructor
        if(isdigit(num[0])) {
                setNum(num);
                sign=false;
        }
        else {
                setNum(num.substr(1));
                sign=true;
        }
}

/* Simple constructor for known signed values */
BigInt::BigInt(string num, bool sign) {
        setNum(num);
        setSign(sign);
}

/* Constructor for int */
BigInt::BigInt(int n) {
        string num = to_string(n); // quickest conversion.  ref: http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
        BigInt(num); // create bigint out of string :) 
}

/* Set routines for number and sign */
void setNum(string num) {
        setNum(num);
}
void setSign(bool sign) {
        setSign(sign);
}

// NOTE: don't need get methods.  Those are inlined in the header file

// --- Methods implemented from Java API below --- 
// http://docs.oracle.com/javase/8/docs/api/java/math/BigInteger.html
// http://docs.oracle.com/javase/7/docs/api/java/math/BigInteger.html

/* routine to fetch absolute value */
BigInt BigInt::absolute() {
        return BigInt(getNum());
}

// --- End Big Integer Java 8 API Methods --- 



// --- Operator Overloading ---  

/* Overloaded assignment operator */
void BigInt::operator=(BigInt num) {
        setNum(num.getNum());
        setSign(numb.getSign);
}

/* Overloaded equality operator */
bool BigInt::operator==(BigInt num) {
        return equals(*this, num);
}


/* multiplication */
BigInt BigInt::operator*(BigInt num) { 
        BigInt result;
        string product = multiply(getNum(),num.getNum());
        result.setNum(product);
        return result;
}

/* addition */
BigInt BigInt::operator+(BigInt num) {
        BigInt result;
        string sum;
        // need to test if the number is signed
        if(getSign == num.getSign()) {
                //sign the same
                result.setSign(getSign());
                sum = add(getNum(), num.getNum());
                result.setNum(sum);
        }
        else {
                // sign not the same
                if(absolute() > num.absolute()) {
                        result.setSign(getSign());
                        sum=subtract(getNum(), num.getNum()); 
                        result.setNum(sum);
                }
                else {
                        result.setSign(num.getSign());
                        sum=subtract(num.getNum(), getNum());
                        result.setnum(sum);
                }
        }

        return result;
}

/* subtraction */
BigInt operator-(BigInt num) {
        num.setSign(!num.getSign());
        return (*this) + num;
}

/* quick conversion for funzies */
BigInt BigInt::operator string() {
        string s;
        if(getSign()) {
                s="-";
        }
        else {
                s="";
        }
        return s;
}

// --- End Operator Overloads ---



// --- Private Helper Methods ---


/* equals routine */
bool BigInt::equals(BigInt a, BigInt b) {
        return a.getNum() == b.getNum() && a.getSign() == b.getSign();
}

/* add */
string BigInt::add(string a, string b) {

        string result;
        char c='0';
        int diff=abs((int)(a.size()-b.size()));


        if(a.length() > b.length())
                result=a;
        else
                result=b;


        if(a.size()>b.size())
                b.insert(0,diff,'0');
        else
                a.insert(0,diff,'0');



        
}

/* subtract */
string BigInt::subtract(string a, string b) {

}

/* multiply */
string BigInt::multiply(string a, string b) {

}











