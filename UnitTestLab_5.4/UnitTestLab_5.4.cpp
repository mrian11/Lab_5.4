#include "pch.h"
#include "CppUnitTest.h"
#include "../LAb__5.4/5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab54
{
	TEST_CLASS(UnitTestLab54)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double n;
			n = P4(2, 3, 1.2);
			Assert::AreEqual(2,2, 1.44);
		}
	};
}
