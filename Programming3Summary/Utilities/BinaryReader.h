#pragma once
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "Utilities.h"

namespace Utilities
{
	class BinaryReader
	{
	public:
		explicit BinaryReader(const std::string fileName)
		{
			Open(fileName);
		}

		template <typename T>
		bool Read(T& object)
		{
			if (!m_Ready) return false;
			return std::is_pod<T>::value == 1 ? ReadPOD(object) : ReadNonPOD(object);
		}

		void Close()
		{
			m_Input.close();
		}

	private:
		bool m_Ready;
		std::ifstream m_Input;

		void Open(const std::string fileName)
		{
			m_Input.open(fileName, std::ios::in | std::ios::binary);
			m_Ready = m_Input.is_open();
		}

		template <typename T>
		bool ReadPOD(T& object)
		{
			try
			{
				m_Input.read(reinterpret_cast<char*>(&object), sizeof object);
				return true;
			}
			catch (std::exception exception)
			{
				std::cout << exception.what() << std::endl;
				return false;
			}
		}

		template <typename T>
		bool ReadNonPOD(T& object)
		{
			throw new UnsupportedType(typeid(T).name());
		}
	};
}
