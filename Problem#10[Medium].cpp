/*
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

// Job Scheduler function
void jobScheduler(const std::function<void()>& f, int n) {
    std::thread([f, n]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(n));
        f();
    }).detach();
}

// Sample function to be scheduled
void sampleFunction() {
    std::cout << "Function called after delay!" << std::endl;
}

int main() {
    // Schedule the sampleFunction to be called after 1000 milliseconds (1 second)
    jobScheduler(sampleFunction, 1000);

    // Keep the main thread alive for enough time to see the scheduled function execute
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    return 0;
}
