#include <iostream>
#include <sstream>

class ORDEREXCEPTION
{
private:
	int order1[2];
	int order2[2];

public:
	ORDEREXCEPTION() = default;
	ORDEREXCEPTION(int a, int b, int c, int d);
	std::string message();
};

class SINGULAREXCEPTION
{
private:
	std::string message_str;

public:
	SINGULAREXCEPTION();

	std::string message();
};

class DIVIDEBYZERO
{
public:
	std::string message();
};

class OUTOFRANGE
{
private:
	std::string errorMsg;

public:
	OUTOFRANGE() = default;
	OUTOFRANGE(int m, int n, int row, int col);
	std::string message();
};
