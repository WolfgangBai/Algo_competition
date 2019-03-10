#include "BigInteger.h"

void BigInteger::CutLeadingZero()
{
    while (num_.back() == 0 && num_.size() != 1) {
        num_.pop_back();
    }
}

void BigInteger::SetLength()
{
}

BigInteger::BigInteger(int n)
{
   *this = n; 
}

BigInteger::BigInteger(long long n)
{
    *this = n;
}

//BigInteger::BigInteger(const char *n)
//{
//   *this = n;
//}


//BigInteger::BigInteger(const BigInteger &n)
//{
//   *this = n;
//}

const BigInteger& BigInteger::operator=(int n) 
{
    *this = (long long) n;
    return *this;
}

const BigInteger& BigInteger::operator=(long long n) 
{
    num_.clear();
    if (n == 0) {
        num_.push_back(0);
    }
    if (n >= 0) {
        sign_ = true;
    } else {
        sign_ = false;
        n = -n; 
    }
    while (n != 0) {
        num_.push_back(n % base_);
        n /= base_;
    }
    
//    SetLength();

    return *this;
}

std::ostream& operator <<(std::ostream &out, const BigInteger &n) 
{
    size_t len = n.num_.size();
    if (!n.sign_) {
        out << "-";
    }
    out << n.num_.back();
    for (int i = len - 2; i >= 0; i--) {
        out << std::setw(BigInteger::width_) << std::setfill('0') << n.num_[i];
    }
    return out;
}
