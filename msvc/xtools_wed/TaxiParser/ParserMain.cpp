#include "ParserMain.h"
#include "UnitTester.h"
#define _CRT_SECURE_NO_WARNINGS

ParserMain::ParserMain(void)
{
}


ParserMain::~ParserMain(void)
{
}


int main(int argc, const char* argv[])
{
	//An array of tests
	const int MAX_TESTS=256;
	Test tests[MAX_TESTS];

	//For all spaces in the array fill it with blanks
	for (int i = 0; i < MAX_TESTS; i++)
	{
		tests[i]=Test();
	}

	//A counter for placing the tests in the array
	int counter = 0;

	//To Add a test create the following
	//tests[counter] = Test(&InString("text"),&OutString("front","optional back"),true,true); counter++;
	tests[counter] = Test(&InString("{@Y}CAT{@@}safety"),&OutString("/YC/YA/YT","/Ys/Ya/Yf/Ye/Yt/Yy"),true,true); counter++;
	tests[counter] = Test(&InString("{@Y,q}CAT{@@}comma"),&OutString("/Yq/YCAT","/Ycomma"),true,true); counter++;
	
	//For all the tests
	for (int i = 0; i < counter; i++)
	{
		//Temp char *'s for itoa
		char temp[256];
		char number[24];
		_itoa(i,number,10);

		//Create the file path
		sprintf(temp,"C:\\Users\\Ted\\Desktop\\Logs\\%s%s%s","log_",number,".txt");
		
		tests[i].RunTest(&tests[i],temp);
	}

	//UnitTester::RunTest(NULL);
	system("pause");
}