#include <iostream>
#include <map>
#include <string>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <Windows.h>

using namespace std;

void showSQLError(unsigned int handleType,const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if(SQL_SUCCESS== SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
	{
		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << '\n';
	}
}

int main()
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHAndle = NULL;
	SQLRETURN retCode = 0;
	char SQLQuery[] = "SELECT * FROM people";

	do
	{
		if(SQL_SUCCESS!= SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
		{
			break;
		}

		if(SQL_SUCCESS!= SQLSetEnvAttr(SQLEnvHandle,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,0))
		{
			break;
		}

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
		{
			break;
		}

		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		{
			break;
		}

	} while (FALSE);

	map<long, string> Persoana;
	map<long, string>::iterator it;
	cout << "Hello person" << '\n';
	Persoana[1] = "Marius";
	Persoana[2] = "Ionela";
	Persoana.insert(make_pair(3, "Sandu"));
	for(it=Persoana.begin();it!=Persoana.end();++it)
	{
		cout << it->second << endl;
	}
	system("PAUSE");
	return 0;
}