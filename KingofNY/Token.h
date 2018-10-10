#pragma once
#include <string>
#include <vector>

using namespace std;

class Token
{
	public:
		Token();
		Token(string);
		~Token();
		string getTokenType();
		
	private:
		string type;
		

};

