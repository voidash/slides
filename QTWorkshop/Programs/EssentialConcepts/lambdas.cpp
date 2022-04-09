//bin/true; g++ -o "/tmp/$0.bin" "$0" && "/tmp/$0.bin" "$@"; exit $?
#include <chrono>
#include <iostream>
#include <thread>
#include <functional>

// c++ 11 feature

 using namespace std::chrono_literals;
int main() {
	auto intensiveCalc = [](int time) {
		std::this_thread::sleep_for(std::chrono::seconds(time));
		return 500;
	};


	std::function<int (int, int)> sum; 
	sum = [](int a, int b) {
		return a+b;
	};

	std::cout << sum(2,3) << std::endl;


	int a = 12;

	std::cout << "value before calling increment lambda "<< a << std::endl;
	// reference
	auto increment = [&a]() {
		a++;
	};
	
	increment();
	std::cout << "value after calling increment lambda "<< a << std::endl;

}
