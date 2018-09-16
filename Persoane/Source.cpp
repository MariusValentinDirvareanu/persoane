#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<long, string> Persoana;
	map<long, string>::iterator it;
	cout << "Hello person" << '\n';
	Persoana[1] = "Marius";
	Persoana[2] = "Ionela";
	for(it=Persoana.begin();it!=Persoana.end();++it)
	{
		cout << it->second << endl;
	}
	system("PAUSE");
	return 0;
}