/*
Title: CPE553-hw1
Author: Chenhui Yang
*/

#include <iostream>
#include <cmath>
using namespace std;

int sumSquaresUpTo(int num) {
    int res = 0;
    for (int i = 1; i <= num; i++) {
        res += i * i;
    }
    return res;
}

// method for mystery1
float method1(int n) {
    float mystery1 = 0;
    for (int i = 1; i <= n; i++) {
        mystery1 += 1.0f / (i * i);
    }
    return mystery1;
}

//method for mystery1
float method2(int n) {
    float mystery2 = 0;
    for (int i = n; i >= 1; i--) {
        mystery2 += 1.0f / (i * i);
    }
    return mystery2;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cout << sumSquaresUpTo(5) << '\n'; // inclusive: 1*1 + 2*2 + 3*3 + 4*4 + 5*5
    cout << sumSquaresUpTo(7) << '\n'; // inclusive: 1*1 + 2*2 + 3*3 + 4*4 + 5*5 +6*6 + 7*7
    
    float sum1 = 0;// compute the sum 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/100 =5.18....
    for (int i = 1; i <= 100; i++) {
        sum1 += 1.0f / i;
    }
    float sum2 = 0;// compute the sum 1/100 + 1/99 + 1/98 + ... + 1/1 = 5.18
    for (int i = 100; i >= 1; i--) {
        sum2 += 1.0f / i;
    }
    cout << sum1 << '\n';
    cout << sum2 << '\n';
    cout << (sum1 - sum2) << '\n';


    // mystery sum
    // be careful! if you calculate as int this will not work. use float!
    // be careful! overflow (i*i)
    // compute 1.0/(1*1) + 1.0/(2.0*2.0) + 1/(3*3) + ... + 1/(n*n)  n-> infinity
    float mystery1 = method1(10000); 
    // compute  1/(n*n) + 1/((n-1)*(n-1)) +  1/((n-2)*(n-2)) + ...
    float mystery2 = method2(10000); //

    // print out sqrt(mystery1*6).
    cout << sqrt(6 * mystery1) << '\n';
    // print out sqrt(mystery2*6).
    cout << sqrt(6 * mystery2) << '\n';

    cout << isPrime(81) << '\n'; // trial divide, 81%3 == 0 therefore not prime
    cout << isPrime(57) << '\n'; // 57 % 2, 57% 3, 57%4

}