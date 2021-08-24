#include <string>

class INSUFFICIENTSAMPLE
{
private:
	std::string message;

public:
	INSUFFICIENTSAMPLE() = default;
	INSUFFICIENTSAMPLE(std::string s);

	std::string get_message();
};