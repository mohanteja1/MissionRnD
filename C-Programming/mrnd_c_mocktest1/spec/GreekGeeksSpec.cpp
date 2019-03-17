#include "stdafx.h"
#include <stdlib.h>
#include "../src/GreekGeeks.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class GreekGeeksSpec
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
		
		
		[TestMethod, Timeout(1000)]
		void GreekGeekTest01_samples()
		{
			long long result = 0;
			result = countCommonStars(1, 3, 6, 10, 4);
			Assert::AreEqual(0LL, result, L"Failed GreekGeeks Sample 1", 1, 2);
			result = countCommonStars(3, 1, 10, 2, 10);
			Assert::AreEqual(2LL, result, L"Failed GreekGeeks Sample 2", 1, 2);
			result = countCommonStars(1, 5, 5, 6, 5);
			Assert::AreEqual(0LL, result, L"Failed GreekGeeks Sample 2", 1, 2);
		}

	
	};
}
