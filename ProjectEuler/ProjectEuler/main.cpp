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
    int length = 13;
    std::string value = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    
    long result = 0;
    while (true) {
        long product = 1;
        for (int i = 0; i < length; i++) {
            char temp = value[i];
            product *= atol(&temp);
        }
        if (result < product) result = product;
        value.erase(value.begin());
        if (value.size() < length) break;
    }
    
    return std::to_string(result);
}

std::string problem_nine() {
    int a = 0;
    int b = 1;
    int c = 999;
    
    for (int i = 0; i < c; i++) {
        c--;
        b++;
        for (int j = 0; j < b; j++) {
            c--;
            a++;
            if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                return std::to_string(a*b*c);
            }
        }
        c += a - 1;
        a = 1;
    }
    
    return "Error: No Result";
}

std::string problem_ten() {
    long result = 5;
    long limit = 2000000;
    
    for (int i = 2; i < limit; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) break;
            else if (j + 1 > sqrt(i)) {
                result += i;
            }
            
        }
    }
    return std::to_string(result);
}

std::string problem_eleven() {
    int result = 0;
    static const std::string data[] = {"08", "02", "22", "97", "38", "15", "00", "40", "00", "75", "04", "05", "07", "78", "52", "12", "50", "77", "91", "08", "49", "49", "99", "40", "17", "81", "18", "57", "60", "87", "17", "40", "98", "43", "69", "48", "04", "56", "62", "00", "81", "49", "31", "73", "55", "79", "14", "29", "93", "71", "40", "67", "53", "88", "30", "03", "49", "13", "36", "65", "52", "70", "95", "23", "04", "60", "11", "42", "69", "24", "68", "56", "01", "32", "56", "71", "37", "02", "36", "91", "22", "31", "16", "71", "51", "67", "63", "89", "41", "92", "36", "54", "22", "40", "40", "28", "66", "33", "13", "80", "24", "47", "32", "60", "99", "03", "45", "02", "44", "75", "33", "53", "78", "36", "84", "20", "35", "17", "12", "50", "32", "98", "81", "28", "64", "23", "67", "10", "26", "38", "40", "67", "59", "54", "70", "66", "18", "38", "64", "70", "67", "26", "20", "68", "02", "62", "12", "20", "95", "63", "94", "39", "63", "08", "40", "91", "66", "49", "94", "21", "24", "55", "58", "05", "66", "73", "99", "26", "97", "17", "78", "78", "96", "83", "14", "88", "34", "89", "63", "72", "21", "36", "23", "09", "75", "00", "76", "44", "20", "45", "35", "14", "00", "61", "33", "97", "34", "31", "33", "95", "78", "17", "53", "28", "22", "75", "31", "67", "15", "94", "03", "80", "04", "62", "16", "14", "09", "53", "56", "92", "16", "39", "05", "42", "96", "35", "31", "47", "55", "58", "88", "24", "00", "17", "54", "24", "36", "29", "85", "57", "86", "56", "00", "48", "35", "71", "89", "07", "05", "44", "44", "37", "44", "60", "21", "58", "51", "54", "17", "58", "19", "80", "81", "68", "05", "94", "47", "69", "28", "73", "92", "13", "86", "52", "17", "77", "04", "89", "55", "40", "04", "52", "08", "83", "97", "35", "99", "16", "07", "97", "57", "32", "16", "26", "26", "79", "33", "27", "98", "66", "88", "36", "68", "87", "57", "62", "20", "72", "03", "46", "33", "67", "46", "55", "12", "32", "63", "93", "53", "69", "04", "42", "16", "73", "38", "25", "39", "11", "24", "94", "72", "18", "08", "46", "29", "32", "40", "62", "76", "36", "20", "69", "36", "41", "72", "30", "23", "88", "34", "62", "99", "69", "82", "67", "59", "85", "74", "04", "36", "16", "20", "73", "35", "29", "78", "31", "90", "01", "74", "31", "49", "71", "48", "86", "81", "16", "23", "57", "05", "54", "01", "70", "54", "71", "83", "51", "54", "69", "16", "92", "33", "48", "61", "43", "52", "01", "89", "19", "67", "48"};

    std::vector<std::vector<std::string>
    
    while (true) {
        
    }
    
    return std::to_string(result);
}

//std::string problem_() {
//    int result = 0;
//    return std::to_string(result);
//}

int main(int argc, const char * argv[]) {
    std::cout << problem_eleven() << std::endl;
    return 0;
}
