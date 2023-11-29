#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_10.2/lab_10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const string testFilename = "test.txt"; 

            ofstream testFile(testFilename);
            if (!testFile.is_open()) {
                Assert::Fail(L"Failed to create test file");
            }

            const string testData = "appla elephant banana sun moon mars"; 

            
            testFile << testData;
            testFile.close();

            ifstream inputFile(testFilename);
            if (!inputFile.is_open()) {
                Assert::Fail(L"Failed to open test file for counting");
            }

            string fileContent;
            string temp;
            while (inputFile >> temp)
                fileContent += temp + " ";

            inputFile.close();

            int result = Count(fileContent);

            Assert::AreEqual(1, result);
		}
	};
}
