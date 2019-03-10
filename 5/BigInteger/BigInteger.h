#ifndef BIGINTER_H_
#define BIGINTER_H_

#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>


class BigInteger {
public:
    BigInteger(int n = 0); 
    BigInteger(long long n);
    BigInteger(const char *n);
    BigInteger(const BigInteger &n);


    const BigInteger& operator=(int  n);
    const BigInteger& operator=(long long n);
    const BigInteger& operator=(const char *n);
    const BigInteger& operator=(const BigInteger &n);

    size_t size() const;
    BigInteger e(size_t n) const;
    BigInteger abs() const;

    const BigInteger& operator+() const;
    const BigInteger& operator+=(const BigInteger &n);
    const BigInteger& operator++();
    BigInteger operator++(int);
    friend std::ostream& operator<<(std::ostream &out, const BigInteger &n); 
private:
    static const int base_ = 10000000;
    static const int width_ = 8;
    bool sign_;
    size_t len_;
    std::vector<int> num_;

    void CutLeadingZero();
    void SetLength();
};
#endif //BIGINTEGER_H_
