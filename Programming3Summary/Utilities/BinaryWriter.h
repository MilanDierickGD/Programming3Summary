#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "Utilities.h"

#include "../DataExamples/DataExamples.h"

namespace Utilities
{
	class BinaryWriter
	{
	public:
		explicit BinaryWriter(const std::string fileName)
		{
			Open(fileName);
		}

		template <typename T>
		bool Write(T object)
		{
			if (!m_Ready) return false;
			return std::is_pod<T>::value == 1 ? WritePOD(object) : WriteNonPOD(object);
		}

		void Close()
		{
			m_Output.close();
		}
	private:
		bool m_Ready;
		std::ofstream m_Output;

		void Open(const std::string fileName)
		{
			m_Output.open(fileName, std::ios::out | std::ios::binary);
			m_Ready = m_Output.is_open();
		}

		template <typename T>
		bool WritePOD(T object)
		{
			try
			{
				m_Output.write(reinterpret_cast<const char*>(&object), sizeof object);
				return true;
			}
			catch (std::exception exception)
			{
				std::cout << exception.what() << std::endl;
				return false;
			}
		}

		template <typename T>
		bool WriteNonPOD(T object)
		{
			throw new UnsupportedType(typeid(T).name());
		}
	};

	template <>
	inline bool BinaryWriter::WriteNonPOD<std::string>(const std::string object)
	{
		try
		{		
			// TODO: Figure out if this can be done without creating a temporary variable
			m_Output.write(reinterpret_cast<const char*>(object.size()), sizeof object.size());
			// const size_t size = object.size();
			// m_Output.write(reinterpret_cast<const char*>(&size), sizeof size);
			// m_Output.write(reinterpret_cast<const char*>(object.c_str()), size);
			return true;
		}
		catch (std::exception exception)
		{
			std::cout << exception.what() << std::endl;
			return false;
		}
	}

	template<>
	inline bool BinaryWriter::WriteNonPOD<NPC>(const NPC object)
	{
		try
		{
			Write<std::string>(object.Name);
			Write<float>(object.X);
			Write<float>(object.Y);
			Write<float>(object.Z);
			return true;
		}
		catch (std::exception exception)
		{
			std::cout << exception.what() << std::endl;
			return false;
		}
	}
}
