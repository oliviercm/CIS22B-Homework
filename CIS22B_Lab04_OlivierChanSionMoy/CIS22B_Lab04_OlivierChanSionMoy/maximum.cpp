//Return higher of two values using > operator

#define _CRT_SECURE_NO_WARNINGS

template <typename T>
T maximum(const T a, const T b)
{
	return (a > b ? a : b);
}