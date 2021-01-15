#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

int main()
{

	float a = 6378137;
	float b = 6356752.3141;
	float e2 = 0.006694380023;
	float f = 1 / 298.257222101;
	float k = 0.001931851353;
	float m = 0.00344978600308;
	float gamae = 9.7803267715;
	float eDegiskenKare = 0.006739496775;
	float GM = 3986005 * pow(10, 8);
	float w = 7.292115 * pow(10, -5);
	float j2 = 1.08263000 * pow(10, -3);
	float j4 = -2.37091222 * pow(10, -6);
	float j6 = 6.0834706 * pow(10, -9);
	float j8 = -1.427 * pow(10, -11);
	
	float enlem0 = 38 + (45/60);
	float enlemr = enlem0 * (PI / 180);
	float boylam0 = 30 + (30/60);
	float boylamr = boylam0 * (PI / 180);
	float h = 1325;	
	
	
	float gama0 = gamae * ((1 + k * pow(sin(enlemr), 2)) / pow(1 - e2 * pow(sin(enlemr), 2), 0.5));
	
	float gamah = gama0 * (1 - (2 * h) / a * (1 + f + m - 2 * f * pow(sin(enlemr), 2)) + (3 / pow(a, 2)) * pow(h, 2));
	
	
	std::cout << "Gama0: " << gama0 << std::endl;
	std::cout << "Gamah: " << gamah << std::endl;
	return 0;
}

