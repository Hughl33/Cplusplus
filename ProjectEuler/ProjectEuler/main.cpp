//
//  main.cpp
//  ProjectEuler
//
//  Created by Hugh Lee on 17/11/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

std::string problem_one() {
    //Multiples of 3 and 5
    int limit = 1000; //Multiples below 1000
    std::vector<int> multiples = std::vector<int>();
    for (int i = 3; i < limit; i += 3) multiples.push_back(i); //Push in multiples of 3 first
    for (int i = 5; i < limit; i += 5)
        if (i % 3 != 0) multiples.push_back(i); //Next, Multiples of 5 except multiples of 3 as well
    
    int result = 0;
    for (int i = 0; i < multiples.size(); i++) result += multiples[i]; //Add everything together
    
    return std::to_string(result);
}

std::string problem_two() {
    int limit = 4000000;
    std::vector<int> fibonacciSequence = std::vector<int>();
    fibonacciSequence.push_back(1); //First
    fibonacciSequence.push_back(2); //Second
    
    while (true) {
        if (fibonacciSequence[fibonacciSequence.size()-1] +
            fibonacciSequence[fibonacciSequence.size()-2] < limit) {
            fibonacciSequence.push_back(fibonacciSequence[fibonacciSequence.size()-1] +
                                        fibonacciSequence[fibonacciSequence.size()-2]);
        } else break;
    }
    
    int result = 0;
    for (int i = 0; i < fibonacciSequence.size(); i++)
        if (fibonacciSequence[i] % 2 == 0) result += fibonacciSequence[i];
    return std::to_string(result);
}

std::string problem_three() {
    long value = 600851475143;
    std::vector<long> values = std::vector<long>();
    for (int i = 1; i < value; i++) {
        if (value % i == 0) {
            if (std::find(values.begin(), values.end(), value/i) == values.end()) {
                if (i > 1) {
                    values.push_back(i);
                    values.push_back(value/i);
                }
            } else break;
        }
    }
    
    long result = 0;
    
    for (int i = 0; i < values.size(); i++) {
        int k = 0;
        for (int j = 1; j < values[i]; j++) {
            if (values[i] % j == 0) k++;
            if (k > 1) break;
        }
        if (k < 2) if (result < values[i]) result = values[i];
    }
    
    return std::to_string(result);
}

std::string problem_four() {
    std::vector<long> values = std::vector<long>();
    int begin = 100;
    int end = 999;
    
    for (; begin < end + 1; begin++) {
        for (int i = begin; i < end + 1; i++) {
            values.push_back(begin * i);
        }
    }

    long result = 0;
    for (int i = 0; i < values.size(); i++) {
        long rev = 0;
        int digit = 0;
        long num = values[i];
        
        do {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);
        if (values[i] == rev) if (result < values[i]) result = values[i];
    }
    
    return std::to_string(result);
}

std::string problem_five() {
    int result = 0;
    bool found = false;
    while (!found) {
        result++;
        for (int i = 1; i < 21; i++) {
            if (result % i != 0) break;
            if (i == 20) found = true;
        }
    }
    return std::to_string(result);
}

std::string problem_six() {
    int limit = 100;
    long sum = 0;
    for (int i = 1; i < limit + 1; i++) sum += pow(i, 2);
    long square = 0;
    for (int i = 1; i < limit + 1; i++) square += i;
    square = pow(square, 2);
    
    long result = square - sum;
    return std::to_string(result);
}

std::string problem_seven() {
    int limit = 10002;
    int result = 1;
    int i = 1;
    while (i < limit) {
        result++;
        int k = 0;
        for (int j = 1; j < result; j++) {
            if (result % j == 0) k++;
            if (k > 1) break;
        }
        if (k < 2) i++;
    }
    return std::to_string(result);
}

std::string problem_eight() {
    int length = 4;
    std::string value = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    long result = 0;
    for (int i = length - 1; i < value.size(); i++) {
        long product = 1;
        for (int j = i; j >= 0; j--) {
            char temp = value[j];
            product *= atol(&temp);
        }
        if (result < product) result = product;
    }
    return std::to_string(result);
}

//std::string problem_() {
//    int result = 0;
//    return std::to_string(result);
//}

int main(int argc, const char * argv[]) {
    std::cout << problem_eight() << std::endl;
    return 0;
}
