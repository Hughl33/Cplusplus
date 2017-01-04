//
//  main.cpp
//  ProjectEuler
//
//  Created by Hugh Lee on 17/11/2016.
//  Copyright © 2016 OysterFinish. All rights reserved.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

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

std::mutex mutex;
std::vector<long> factors = std::vector<long>();

void p3_process(long start, long end) {
    std::vector<long> values = std::vector<long>();
    for (long i = start; i < end; i++) if (end % i == 0) values.push_back(i);
    for (long i = 0; i < values.size();) {
        int k = 0;
        for (long j = 0; j < values[i]; j++) if (values[i] % j == 0) k++;
        if (k > 1) values.erase(values.begin() + i);
        else i++;
    }   
    mutex.lock();
    factors.reserve(values.size());
    factors.insert( factors.end(), values.begin(), values.end() );
    mutex.unlock();
}

std::string problem_three() {
    long value = 600851475143;
    int num_threads = 10000;
    std::vector<std::thread> threads(num_threads);
    long start = 0;
    long end = 1;
    for (int i = 0; i < num_threads; i++) {
        start = end;
        end += value / num_threads;
        if (end > value) end = value;
        threads[i] = std::thread(p3_process, start, end);
    }
    
    for (int i = 0; i < threads.size(); i++) threads[i].join();
    
    long result = 0;
    for (long i = 0; i < factors.size(); i++) if (factors[i] > result) result = factors[i];
    return std::to_string(result);
}

//std::string problem_() {
//    int result = 0;
//    return std::to_string(result);
//}

void testOne() {
    for (long i = 0; i < 10000; i++) std::cout << std::to_string(i) + " " << std::endl;
}

void testTwo() {
    for (long i = 10000; i < 20000; i++) std::cout << std::to_string(i) + " " << std::endl;
}

int main(int argc, const char * argv[]) {
//    std::cout << problem_three() << std::endl;
    return 0;
}
