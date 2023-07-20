#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//ax+by=c

//dx+ey=f

int gcd(int p, int q) { // 최대공약수

	if (q == 0)

		return p;

	else

		return gcd(q, p % q);

}

int lcm(int p, int q) { //최소공배수

	return p * q / gcd(p, q);
}

int main(void)

{

	int a, b, c, d, e, f;

	int fir = 0;



	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);



	


	if(a!=0&&b!=0&&d!=0&&e!=0)
	{
		fir = lcm(a, d);



		int ka = fir / a;

		int kd = fir / d;

		a *= ka;

		b *= ka;

		c *= ka;

		d *= kd;

		e *= kd;

		f *= kd;



		int k, z;

		if (b > e) {

			k = b - e;

			z = c - f;

		}

		else {

			k = e - b;

			z = f - c;

		}



		int y = z / k;

		int x;

		x = (c - b * y) / a; //ax+by=c

		printf("%d %d", x, y);
	}
	else if (a == 0&&e==0) {
		int y = c / b;
		int x = f / d;
		printf("%d %d", x, y);
	}
	else if (b == 0 && d == 0) {
		int x = c / a;
		int y = f / e;
		printf("%d %d", x, y);
	}
	else if (a==0) {
		int y = c / b;
		int x = (f - e * y) / d;
		printf("%d %d", x, y);
	}
	else if (d == 0) {
		int y = f / e;
		int x = (c - b * y) / a;
		printf("%d %d", x, y);
	}
	else if (b == 0) {
		int x = c / a;
		int y = (f - d * x) / e;
		printf("%d %d", x, y);
	}
	else if (e == 0) {
		int x = f / d;
		int y = (c - a * x) / b;
		printf("%d %d", x, y);
	}



	return 0;

}