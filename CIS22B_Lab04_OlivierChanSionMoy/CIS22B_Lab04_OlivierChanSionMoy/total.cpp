//Keep and return a running total of passed values starting at 0.

#define _CRT_SECURE_NO_WARNINGS

template <typename T>
T total(const T a)
{
	static T t = 0.0;
	return t += a;
}