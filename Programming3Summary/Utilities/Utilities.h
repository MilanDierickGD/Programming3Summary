#pragma once
#include <iostream>
#include <string>

namespace Utilities
{
	class UnsupportedType final : std::exception
	{
	public:
		explicit UnsupportedType(const std::string type)
		{
			m_Type = type;
		}

		char const* what() const override
		{
			return std::string("Unsupported type: " + m_Type).c_str();
		}

	private:
		std::string m_Type;
	};
	
	inline int GetIntFromCin(const std::string message)
	{
		std::cout << message;
		while (true)
		{
			std::string inputString;
			std::getline(std::cin, inputString);
			try
			{
				// Throws std::invalid_argument if no conversion could be performed
				// No need to worry about the std::out_of_range exception because it's beyond this project's scope
				const int number = std::stoi(inputString);
				return number;
			}
			catch (...)
			{
				std::cout << "Bad input: please only insert natural numbers...\n";
			}
		}
	}
}
