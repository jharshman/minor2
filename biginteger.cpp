/**
 * biginteger.cpp
 * written by Josh Harshman
 * 07/14/15
 * */

#include "biginteger.h"

/* default constructor */
BigInt::BigInt() {
        num="0";
        sign=false;
}

/* constructor for unknown signed values */
BigInt::BigInt(string num) {

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

/* constructor for known signed values */
BigInt::BigInt(string num, bool sign) {
        setNum(num);
        setSign(sign);
}

/* constructor for passing int values */
BigInt::BigInt(int n) {
        string num = to_string(n); // quickest conversion.  ref: http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
       // new BigInt(num); // create bigint out of string :) 
        if(isdigit(num[0])) {
                setNum(num);
                sign=false;
        }
        else {
                setNum(num.substr(1));
                sign=true;
        }
}

/* copy constructor */
BigInt::BigInt(const BigInt &orig) {
        setNum(orig.getNum());
        setSign(orig.getSign());
}

/* set num variable */
void BigInt::setNum(string s) {
        num=s;
}

/* set sign variable */
void BigInt::setSign(bool s) {
        sign=s;
}

// NOTE: don't need get methods.  Those are inlined in the header file

// --- Methods implemented from Java API below --- 
// http://docs.oracle.com/javase/8/docs/api/java/math/BigInteger.html
// http://docs.oracle.com/javase/7/docs/api/java/math/BigInteger.html
/* get absolute value for the number */
BigInt BigInt::absolute() {
        return BigInt(getNum()); // returns number w/o the sign
}

// --- End Big Integer Java 8 API Methods --- 


// --- Operator Overloading ---  

ostream &operator<<(ostream &out, const BigInt &bi) {
        string sign;
        if(bi.getSign())
                sign="-";
        else
                sign="";

        out << sign << bi.getNum();
        return out;
}

istream &operator>>(istream &in, BigInt &bi) {
        string number;
        in >> number;
        if(isdigit(number[0])) {
                //cout << "number @ 0 index is a digit" << endl; //debug
                bi.setNum(number);
                bi.setSign(false);
        }
        else {
                //cout << "number @ 0 index is not a digit" << endl; //debug
                bi.setNum(number.substr(1));
                bi.setSign(true);
        }

        return in;
}

bool BigInt::operator>(BigInt num) {
        return greater((*this),num);
}

bool BigInt::operator<(BigInt num) {
        return less((*this),num);
}

void BigInt::operator=(BigInt num) {
        setNum(num.getNum());
        setSign(num.getSign());
}

bool BigInt::operator==(BigInt num) {
        return equals(*this, num);
}

BigInt BigInt::operator*(BigInt num) { 
        BigInt result;
        string product = multiply(getNum(),num.getNum());
        result.setSign(getSign()!=num.getSign());
        result.setNum(product);
        return result;
}

BigInt BigInt::operator+(BigInt num) {
        BigInt result;
        string sum;
        // need to test if the number is signed
        if(getSign() == num.getSign()) {
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
                        result.setNum(sum);
                }
        }

        return result;
}

BigInt BigInt::operator-(BigInt num) {
        num.setSign(!num.getSign());
        return (*this) + num;
}

// --- End Operator Overloads ---


// --- Private Helper Methods ---

bool BigInt::equals(BigInt a, BigInt b) {
        return a.getNum() == b.getNum() && a.getSign() == b.getSign();
}

bool BigInt::greater(BigInt a, BigInt b) {
        return !equals(a,b) && !less(a,b);
}

bool BigInt::less(BigInt a, BigInt b) {
        bool s1 = a.getSign();
        bool s2 = b.getSign();

        if(s1 && !s2)
                return true;
        else if(!s1 && s2)
                return false;
        else if(!s1) {
                if(a.getNum().length() < b.getNum().length())
                        return true;
                if(a.getNum().length() > b.getNum().length())
                        return false;
                return a.getNum() < b.getNum();
        }
        else {
                if(a.getNum().length() > b.getNum().length())
                        return true;
                if(a.getNum().length() < b.getNum().length())
                        return false;
                return a.getNum().compare(b.getNum()) > 0; 
        }
}

string BigInt::add(string a, string b) {
        string result;
        char c='0';
        int diff=abs((int)(a.size()-b.size()));

        if(a.length()>b.length())
                result=a;
        else
                result=b;


        if(a.size()>b.size())
                b.insert(0,diff,'0');
        else
                a.insert(0,diff,'0');


        //some for-loop magic for addition 
        for(int i=a.size()-1;i>=0;--i) {
                result[i]=((c-'0')+(a[i]-'0')+(b[i]-'0'))+'0';
                if(i!=0) {
                        if(result[i]>'9') {
                                result[i]-=10;
                                c='1';
                        }
                        else {
                                c='0';
                        }
                }
        }
        if(result[0] > '9') {
                result[0]-=10;
                result.insert(0,1,'1');
        }
        return result;
}

string BigInt::subtract(string a, string b) {
        string result;
        int diff=abs((int)(a.size()-b.size()));

        if(a.length()>b.length())
                result=a;
        else
                result=b;


        if(a.size()>b.size())
                b.insert(0,diff,'0');
        else
                a.insert(0,diff,'0');

        
        // for-loop magic for subtraction based off addition routine
        for(int i=a.length()-1;i>=0;--i) {
                if(a[i]<b[i]) {
                        a[i]+=10;
                        a[i-1]--;
                }
                result[i]=((a[i]-'0')-(b[i]-'0'))+'0';
        }
        while(result[0]=='0' && result.length()!=1)
                result.erase(0,1);

        return result;
}

string BigInt::multiply(string a, string b) {
       
        string result="0";
        string tmp;
        int cdig;
        int c;

        if(a.length()>b.length())
                a.swap(b);
        
        // nested for-loop magic for multiplication found online
        for(int i=a.length()-1;i>=0;--i) {
                tmp=b;
                cdig=a[i]-'0';
                c=0;

                for(int j=tmp.length()-1;j>=0;--j) {
                        tmp[j]=((tmp[j]-'0')*cdig)+c;

                        if(tmp[j]>9) {
                                c=(tmp[j]/10);
                                tmp[j]-=(c*10);
                        }
                        else
                                c=0;

                        tmp[j]+='0';
                }

                if(c>0) 
                        tmp.insert(0,1,(c+'0'));
                

                tmp.append((a.length()-i-1),'0');

                result=add(result,tmp);
        }

        while(result[0]=='0' && result.length()!=1)
                result.erase(0,1);

        return result;
}

