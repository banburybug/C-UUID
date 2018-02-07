#pragma comment(lib, "rpcrt4.lib")  // UuidCreate - Minimum supported OS Win 2000
#include <windows.h>
#include <iostream>
#include <objbase.h>
//#include <uuid/uuid.h>


using namespace std;

int main()
{

	//Creating UUIDS
	UUID uuid;
	UuidCreate(&uuid);
	char *str;
	UuidToStringA(&uuid, (RPC_CSTR*)&str);
	cout << str << endl;
	RpcStringFreeA((RPC_CSTR*)&str);


	//Windows creating GUIDS
	//Printing out GUID
	GUID guid;
	CoCreateGuid(&guid);

	
	char szGuid[40] = { 0 };
	CoCreateGuid(&guid);
	sprintf(szGuid, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", 
		guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

	printf("%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);



	//Windows creating GUID and storing it as bytes
	GUID newId;
	CoCreateGuid(&newId);

	const unsigned char bytes[16] =
	{
		(newId.Data1 >> 24) & 0xFF,
		(newId.Data1 >> 16) & 0xFF,
		(newId.Data1 >> 8) & 0xFF,
		(newId.Data1) & 0xff,

		(newId.Data2 >> 8) & 0xFF,
		(newId.Data2) & 0xff,

		(newId.Data3 >> 8) & 0xFF,
		(newId.Data3) & 0xFF,

		newId.Data4[0],
		newId.Data4[1],
		newId.Data4[2],
		newId.Data4[3],
		newId.Data4[4],
		newId.Data4[5],
		newId.Data4[6],
		newId.Data4[7]
	};


	//Linux creating UUID
	//uuid_t id;
	//uuid_generate(id);

	//char *string = new char[100];
	//uuid_unparse(id, string);

	//std::cout << string << std::endl;

	return 0;
}