/**
 * biginteger.cpp
 * written by Josh Harshman
 * 07/14/15
 * */

/* constructor for unknown signed values */
BigInt::BigInt(string num=0) {

        //on the off chance that the number is signed, 
        //and this constructor is called accidentally
        //or for invocations from other constructor
        if(isdigit(num[0])) {
                setNumber(num);
                sign=false;
        }
        else {
                setNumber(num.substr(1));
                sign=true;
        }
}

/* Simple constructor for known signed values */
BigInt::BigInt(string num, bool sign) {
        setNumber(num);
        setSign(sign);
}

/* Constructor for int */
BigInt::BigInt(int n) {
        string num = to_string(n); // quickest conversion.  ref: http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
        BigInt(num); // create bigint out of string :) 
}

/* Set routines for number and sign */
void setNum(string num) {
        setNumber(num);
}
void setSign(bool sign) {
        setSign(sign);
}

//don't need get methods.  Those are inlined in the header file
//


/* routine to fetch absolute value */
BigInt BigInt::absolute() {
        return BigInt(getNumber());
}


