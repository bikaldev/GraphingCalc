#include "include/MatrixException.hpp"


std::string
ORDEREXCEPTION::message()
{
	std::ostringstream os;
	os << "[ERROR]: Tried to multiply "
	   << order1[0] << " x " << order1[1] << " with " << order2[0] << " x " << order2[1] << std::endl;
	return os.str();
}

ORDEREXCEPTION::ORDEREXCEPTION(int a, int b, int c, int d)
	{
		order1[0] = a;
		order1[1] = b;
		order2[0] = c;
		order2[1] = d;
	}

	SINGULAREXCEPTION::SINGULAREXCEPTION()
	{
		message_str = "[ERROR]: The Matrix is Singular.";
	}
std::string SINGULAREXCEPTION::message()
	{
		return message_str;
	}

std::string DIVIDEBYZERO::message()
{
	return "[ERROR]: Can't Divide Matrix by Zero";
}

OUTOFRANGE::OUTOFRANGE(int m, int n, int row, int col)
{
	std::ostringstream os;
	os << "[ERROR]: Tried to access (" << row << " , " << col << ") from a matrix with order " << m << " x " << n;
	errorMsg = os.str();
}
std::string OUTOFRANGE::message()
{
	return errorMsg;
}