#include "pch.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Utilities/BinaryReader.h"
#include "Utilities/BinaryWriter.h"

// ===================================================================================================================== 
// Shows how to use catch with a named test case
// =====================================================================================================================
unsigned int Factorial(const unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;		//? = if()
}

TEST_CASE("Factorials are computed", )
{
	// REQUIRE(Factorial(0) == 1);		//wil fail
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("BinaryWriteRead")
{
	Utilities::BinaryWriter writer("binaryFile.dat");	

	int value = 50;
	
	writer.Write(value);

	value = 20;

	REQUIRE(value == 20);

	writer.Close();
	Utilities::BinaryReader reader("binaryFile.dat");
	
	reader.Read(value);

	REQUIRE(value == 50);
}
