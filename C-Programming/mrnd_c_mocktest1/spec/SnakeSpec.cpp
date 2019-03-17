#include "stdafx.h"
#include "../src/Snake.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SnakeSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes

#pragma endregion 

		int compare(int** output, int** expectedOutput){
			if (expectedOutput == NULL){
				if (output == NULL)	return 1;
				return 0;
			}
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 100; j++){
					if (output[i][j] != expectedOutput[i][j])	return 0;
				}
			}
			return 1;
		}

		[TestMethod, Timeout(1000)]
		void Sample_Snake()
		{
			int check = 0;
			Assert::AreEqual(0, check, L"Sample test failed", 1, 2, 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample_Snake2()
		{
			int len = 5;
			int** expectedOutput = (int**)calloc(3, sizeof(int*));
			for (int i = 0; i < 3; i++){
				expectedOutput[i] = (int*)calloc(100, sizeof(int));
			}
			expectedOutput[0][0] = 5;
			expectedOutput[1][0] = 4;
			expectedOutput[2][0] = 3;
			expectedOutput[2][1] = 2;
			expectedOutput[1][1] = 1;
			int** Output = initialSnakePosition(len);
			int finalAnswer = compare(Output, expectedOutput);
			Assert::AreEqual(1, finalAnswer, L"Sample 2 snake Case failed", 1, 2, 1, 2);
		};

		
	};
}
