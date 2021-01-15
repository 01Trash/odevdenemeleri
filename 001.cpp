#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

int main()
{
	float a = 6378137;
	float b = 6356752.3141;
	float e2 = 0.006694380023;
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
	
	float c = pow(a, 2) / b;

	float N = c / pow((1 + eDegiskenKare * pow(cos(enlemr), 2)), 0.5);
	
	float x = (N + h) * cos(enlemr) * cos(boylamr);

	float y = (N + h) * cos(enlemr) * sin(boylamr);

	float z = ((1 - e2) * N + h) * sin(enlemr);

	float r = pow((x * x + y * y + z * z), 0.5);
	float sonb = atan(y / x);
	float sone = atan(pow((x * x + y * y), 0.5) / z);
	
	
	float P0t = 1;
	float P1t = cos(sone);
	float n = 2;
	float P2t = ((2 * n - 1) / n) * cos(sone) * P1t - ((n - 1) / n) * P0t;
	float ar2 = pow((a / r), (n));
	float C2 = P2t * j2 * ar2;
	float n1 = 3;
	float P3t = ((2 * n1 - 1) / n1) * cos(sone) * P2t - ((n1 - 1) / n1) * P1t;
	float n2 = 4;
	float P4t = ((2 * n2 - 1) / n2) * cos(sone) * P3t - ((n2 - 1) / n2) * P2t;
	float ar4 = pow((a / r), (n));
	float C4 = P4t * j4 * ar4;
	float n3 = 5;
	float P5t = ((2 * n3 - 1) / n3) * cos(sone) * P4t - ((n3 - 1) / n3) * P3t;
	float n4 = 6;
	float P6t = ((2 * n4 - 1) / n4) * cos(sone) * P5t - ((n4 - 1) / n4) * P4t;
	float ar6 = pow((a / r), (n));
	
	float C6 = P6t * j6 * ar6;
	
	float toplam = C2 + C4 + C6;
	
	float L = (GM / r) * (1 - toplam) + (pow(w, 2) / 2) * pow(r, 2) * pow(sin(sone), 2);
	
	
	std::cout << "L: " << L << std::endl;
	return 0;
}



