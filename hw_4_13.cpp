#include <iostream>
#include <iomanip>
using namespace std;

const double MILES_TO_KILOMETERS = 1.61;

//接收步速(分鐘和秒)，轉換MPH
double convertToMPH(int minute,int secounds) {
	double hour = (minute / 60.0) / 60.0;
	return 1 / hour;
}
//公里小時轉mph
double convertToMPHH(double kph) {
	return kph / MILES_TO_KILOMETERS;
}

int main() {
//case 1 
	int mintues = 5;
	int secounds = 30;
	std::cout << "pace " << mintues << ":" << secounds << "per miles is "
		<< std::setprecision(4) << convertToMPH << "mph" << std::endl;
//case 2
	double kph = 16.0;
	std::cout << kph << " kph is "
		<< std::setprecision(4) << convertToMPHH(kph) << " mph " << std::endl;

	return 0;
}

