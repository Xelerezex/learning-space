#include <iostream>

//-------------------------------------------------------------------------------------------------
int main() 
{
	int a = 0;
	std::cin >> a;

	int b = 0;
	std::cin >> b;

	if (b == 0)
	{
		std::cout << "Impossible" << std::endl;
	}
	else
	{
		std::cout << a / b << std::endl;
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------