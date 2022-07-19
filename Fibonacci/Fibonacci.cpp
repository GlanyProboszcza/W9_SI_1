#include <iostream>

int numOfAddition = 0;
int* memoryArr;

// Level 0 - Fibonacci sequence (iterative)
int fiboLvl0(int n)
{
    int nMinusDwa = 0, nMinusJeden = 1, nElement = 0;

    if (n <= 1) return n;
    else {
        for (int i = 2; i <= n; i++)
        {
            numOfAddition++;
            //std::cout << nMinusDwa << " + " << nMinusJeden<<std::endl;
            nElement = nMinusDwa + nMinusJeden;
            nMinusDwa = nMinusJeden;
            nMinusJeden = nElement;
        }
    }
    return nElement;
}

// Level 1 - Fibonacci sequence (naive recursive)
int fiboLvl1(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        numOfAddition++;
        return fiboLvl1(n - 1) + fiboLvl1(n - 2);
    }
}

// Level 2 - Fibonacci sequence(recursive with memorization)
int fiboLvl2(int n) {
        
    if (n <= 1) {
        return n;
    }
    else if (memoryArr[n - 1] != 0)
        return memoryArr[n - 1];
    else {
        numOfAddition++;
        return memoryArr[n-1] = fiboLvl2(n - 1) + fiboLvl2(n - 2);
    }
}
// Level 3 - Fibonacci sequence(tail recursive)
int fiboLvl3(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    numOfAddition++;
    std::cout << "n: " << n << ", a: " << a << ", b: " << b << std::endl;
    return fiboLvl3(n - 1, b, a + b);
}

int main() {

    std::cout << "Level 0 - Fibonacci sequence (iterative) " << fiboLvl0(7) << std::endl;
    std::cout << "Number of addition " << numOfAddition << std::endl;

    std::cout << "\nLevel 1 - Fibonacci sequence (naive recursive) " << fiboLvl1(7) << std::endl;
    std::cout << "Number of addition " << numOfAddition << std::endl;

    int n = 10;
    memoryArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        memoryArr[i] = 0;
    }

    std::cout << "\nLevel 2 - Fibonacci sequence(recursive with memorization) " << fiboLvl2(7) << std::endl;
    std::cout << "Number of addition " << numOfAddition << std::endl;

    delete[] memoryArr;

    std::cout << "\nLevel 3 - Fibonacci sequence(tail recursive) " << fiboLvl3(7) << std::endl;
    std::cout << "Number of addition " << numOfAddition << std::endl;

    return 0;
}
