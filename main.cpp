#include<stdio.h>
#include<Windows.h>
template<typename T>
class math
{
public:
	math() {}
	~math() {}
	//最小値を求める関数
	T Min(T a, T b)
	{
		if (a > b)
			return b;
		else
			return a;
	}

private:

};



int main() {
	//int型
	math<int> m;
	int a = 10, b = 20;
	int min = m.Min(a, b);
	printf("Min of %d and %d is %d\n", a, b, min);
	//float型
	math<float> m1;
	float a1 = 10.5, b1 = 20.5;
	float min1 = m1.Min(a1, b1);
	printf("Min of %f and %f is %f\n", a1, b1, min1);
	//double型
	math<double> m2;
	double a2 = 10.5, b2 = 20.5;
	double min2 = m2.Min(a2, b2);
	printf("Min of %lf and %lf is %lf\n", a2, b2, min2);

	return 0;
}