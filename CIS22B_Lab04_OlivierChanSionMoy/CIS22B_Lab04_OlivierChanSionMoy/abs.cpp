//Return absolute value of value by checking if value is less than 0

#define _CRT_SECURE_NO_WARNINGS

template <typename T>
T abs(const T a)
{
	return (a < 0 ? -a : a);
}