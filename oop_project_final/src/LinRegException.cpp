
#include "include/LinRegException.hpp"

INSUFFICIENTSAMPLE::INSUFFICIENTSAMPLE(std::string s)
{
	message = s;
}

std::string INSUFFICIENTSAMPLE::get_message()
{
	return message;
}