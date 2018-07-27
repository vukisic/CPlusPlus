#include<cstdio>
#include<cstdlib>
#include<cstring>
//Packing(by 1,4 or 8 bytes)
//------------------------------------------------------------------------------
//#pragma pack(1)
//#pragma pack(4)
#pragma pack(8)
//------------------------------------------------------------------------------

//Struct
//------------------------------------------------------------------------------
typedef struct STRUCT_t {
	int *pd;
	int d;
	short s;
	char c;
}STRUCT;
//------------------------------------------------------------------------------

void PrintBytes(const unsigned char* buffer)
{
	printf("\n");
	unsigned size = sizeof(STRUCT);
	unsigned int i = 0;
	while (i < size)
	{
		printf("Address: %3d : ", i);
		printf("0x%x\n", (unsigned)buffer[i]);
		++i;
	}
	printf("\n");

}

int main()
{
	STRUCT st;
	printf("Total bytes: %d\n", sizeof(STRUCT));
	memset(&st, 0xff, sizeof(STRUCT));

	//Struct
	//-----------------------------------------
	st.c = 0x11;
	st.s = 0x2233;
	st.pd = 0x00;
	st.d = 0x66778899;
	//-----------------------------------------

	PrintBytes((unsigned char*)&st);
	
	system("pause");
	return 0;
}