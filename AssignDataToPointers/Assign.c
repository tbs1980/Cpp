#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//http://en.wikipedia.org/wiki/Dangling_pointer

typedef struct
{
	int* integer;
} TestStructType;

void WrongInitTestStructType(TestStructType* ts)
{
	int i;
	ts = (TestStructType*)malloc(sizeof(TestStructType));
	ts->integer = (int*) malloc(10*sizeof(int));

	for(i=0;i<10;++i)
	{
		ts->integer[i] = i;
	}

	for(i=0;i<10;++i)
	{
		printf("WrongInitTestStructType %d\n",ts->integer[i]);
	}
}

void InitTestStructType(TestStructType* ts)
{
	int i;
	ts->integer = (int*) malloc(10*sizeof(int));

	for(i=0;i<10;++i)
	{
		ts->integer[i] = i;
	}

	for(i=0;i<10;++i)
	{
		printf("InitTestStructType %d\n",ts->integer[i]);
	}
}

void FreeTestStruct(TestStructType * ts)
{
	if(ts->integer != NULL) free(ts->integer);
	ts=NULL;
}

void WrongAssign(int * integer)
{
	integer=(int*)malloc(10*sizeof(int));
	int i;
	for(i=0;i<10;++i)
	{
		integer[i] = i;
	}

	for(i=0;i<10;++i)
	{
		printf("WrongAssign %d\n",integer[i]);
	}
}

void Assign(int * integer)
{
	int i;
	for(i=0;i<10;++i)
	{
		integer[i] = i;
	}

	for(i=0;i<10;++i)
	{
		printf("Assign %d\n",integer[i]);
	}

}

void TestWrongAssign(void)
{
	int* myint=NULL;
	int i;

	WrongAssign(myint);

	for( i=0;i<10;++i)
	{
		printf("TestWrongAssign %d\n",myint[i]); //will give a segfault
	}

	if(myint!=NULL) free(myint);
}

void TestAssign(void)
{
	int* myint=(int*)malloc(10*sizeof(int));
	int i;

	Assign(myint);

	for( i=0;i<10;++i)
	{
		printf("TestAssign %d\n",myint[i]);
	}

	if(myint!=NULL) free(myint);

}

void TestWrongStruct(void)
{
	int i;
	TestStructType* myts;
	WrongInitTestStructType(myts);
	for( i=0;i<10;++i)
	{
		printf("TestAssign %d\n",myts->integer[i]); //will give a segfault
	}
	FreeTestStruct(myts);
	free(myts);
}

void TestStruct(void)
{
	int i;
	TestStructType* myts=(TestStructType*)malloc(sizeof(TestStructType));
	InitTestStructType(myts);
	for( i=0;i<10;++i)
	{
		printf("TestAssign %d\n",myts->integer[i]); //will give a segfault
	}
	FreeTestStruct(myts);
	free(myts);

}

int main(void)
{
	//TestAssign();
	//TestWrongAssign();//will give a segfault
	TestStruct();
	//TestWrongStruct();//will give a segfault

	return 0;

}

