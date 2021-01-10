#pragma once
#include <string>
#include <vector>

namespace Utilities
{
	// Can extract console parameters with the following format: program.exe -v someValue -d anotherValue
	class ConsoleInputParser
	{
	public:
		ConsoleInputParser(int& argc, char** argv)
		{
			for (int i = 1; i < argc; ++i)
			{
				this->m_Tokens.push_back(std::string(argv[i]));
			}
		}

		// ConsoleInputParser.CmdOptionExists("-v") returns the value associated with the -v parameter, if it exists
		const std::string& GetCmdOption(const std::string& option) const
		{
			std::vector<std::string>::const_iterator iterator = std::find(this->m_Tokens.begin(), this->m_Tokens.end(), option);
			if (iterator != this->m_Tokens.end() && ++iterator != this->m_Tokens.end())
			{
				return *iterator;
			}
			static const std::string emptyString("");
			return emptyString;
		}

		// Checks if a parameter exists
		bool CmdOptionExists(const std::string& option) const
		{
			return std::find(this->m_Tokens.begin(), this->m_Tokens.end(), option)
                != this->m_Tokens.end();
		}

	private:
		std::vector<std::string> m_Tokens;
	};
}