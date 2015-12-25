#include <iostream>
#include <fstream>
#include <string>

using std::istream;
using std::cout;
using std::cin;
using std::endl;

void deleteOneLineComment(istream& in);
void deleteMultiLineComment(istream& in);
void ignoreTextInComas(istream& in, char coma);

int main (int argc, const char* argv[])
{
	int c = 0;	

	while ( (c = cin.get()) != EOF )
	{
		char symb = (char)c;
		if (symb == '\'' || symb == '\"') {			
			ignoreTextInComas(cin, symb);
			continue;
		} else if (symb == '/' && (char)cin.peek() == '/') {			
			deleteOneLineComment(cin);		
			continue;		
		} else if (symb == '/' && (char)cin.peek() == '*') {
			deleteMultiLineComment(cin);
			cout << ' ';
			continue;
		}

		cout << symb;
	}

	cin.get();
	return 0;
}

void deleteOneLineComment(istream& in)
{
	int c = 0;
	while ( (c = in.get()) != EOF ) {
		if ((char)c == '\n') {
			cout << (char)c;
			break;
		}
	}
}

void deleteMultiLineComment(istream& in)
{
	int c = 0;
	while ( (c = in.get()) != EOF ) {
		if ((char)c == '*' && (char)in.peek() == '/') {
			in.get();
			break;
		}
	}
}

void ignoreTextInComas(istream& in, char coma) 
{
	cout << coma;
	int c = 0;
	char symb = 0;
	while ( (c = in.get()) != EOF ) {
		symb = (char)c;
		cout << symb;
		if (symb == '\\') {
			cout << (char)in.get();
		} else if (symb == coma) {
			break;
		}
	}
}