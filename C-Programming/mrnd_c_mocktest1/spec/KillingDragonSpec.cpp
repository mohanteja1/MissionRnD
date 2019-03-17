#include "stdafx.h"
#include "../src/KillingDragons.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class KillingDragonsSpec
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
		
		[TestMethod, Timeout(500)]
		void KillingDragonsSamples()
		{

			long dragonPower1[] = { 1, 5, 7 };
			long energyPortion1[] = { 2, 6, 3 };

			int res1 = canSavePrincess(dragonPower1, energyPortion1, sizeof(dragonPower1)/sizeof(dragonPower1[0]));

			Assert::AreEqual(-1, res1, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);

			long dragonPower2[] = { 5,10,12,4 };
			long energyPortion2[] = { 20,2,1,15 };

			int res2 = canSavePrincess(dragonPower2, energyPortion2, sizeof(dragonPower2) / sizeof(dragonPower2[0]));

			Assert::AreEqual(4, res2, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);



			long dragonPower3[] = { 7,10,6};
			long energyPortion3[] = { 8, 9, 7 };

			int res3 = canSavePrincess(dragonPower3, energyPortion3, sizeof(dragonPower3) / sizeof(dragonPower3[0]));

			Assert::AreEqual(1, res3, L"Simple Case 1 Failed for Killing Dragon", 1, 2, 1, 2);


		};
		
	};

}