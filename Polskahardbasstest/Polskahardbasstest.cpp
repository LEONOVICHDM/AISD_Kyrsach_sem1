#include "pch.h"
#include "CppUnitTest.h"
#include"../AISD_Kyrsach_sem1/AISD_Kyrsach_sem1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Polskahardbasstest
{
	TEST_CLASS(Polskahardbasstest)
	{
	public:
		
		TEST_METHOD(Test_InfixToPrefix_and_calculator)
		{
			Stack<char> PolskaHardBass;
			Stack<double> CalculatedPolskaHardBass;
			

			string str1="2+2";
			string str2="40000-39968+71-4*2*3328/13312";
			string str3="9-8*3.5";
			string str4="(2+2)*2";
			string str5="10000-10000.5";

			string polskastr1 = "+ 2 2";
			string polskastr2 = "- 40000+ 39968- 71* 4* 2/ 3328 13312";
			string polskastr3 = "- 9* 8 3.5";
			string polskastr4 = "*+ 2 2 2";
			string polskastr5 = "- 10000 10000.5";

			double resulte1 = 4;
			double resulte2 = -37;
			double resulte3 = -19;
			double resulte4 = 8;
			double resulte5 = -0.5;

			Assert::AreEqual(polskastr1, InfixToPrefix(str1, PolskaHardBass));
			Assert::AreEqual(polskastr2, InfixToPrefix(str2, PolskaHardBass));
			Assert::AreEqual(polskastr3, InfixToPrefix(str3, PolskaHardBass));
			Assert::AreEqual(polskastr4, InfixToPrefix(str4, PolskaHardBass));
			Assert::AreEqual(polskastr5, InfixToPrefix(str5, PolskaHardBass));

			Assert::AreEqual(resulte1,calculator(polskastr1, CalculatedPolskaHardBass));
			Assert::AreEqual(resulte2,calculator(polskastr2, CalculatedPolskaHardBass));
			Assert::AreEqual(resulte3,calculator(polskastr3, CalculatedPolskaHardBass));
			Assert::AreEqual(resulte4,calculator(polskastr4, CalculatedPolskaHardBass));
			Assert::AreEqual(resulte5,calculator(polskastr5, CalculatedPolskaHardBass));
		}
	};
}
