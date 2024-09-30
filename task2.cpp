#include<iostream>
using namespace std;

int main()
{
	int array1[10] = { 0x12345678, 0x12345678, 0x12345678, 0x12345678, 0x12345678 };


	__asm
	{

		mov esi, 0
			mov cx, 5
		l1:

		mov eax, array1[esi]
			mov ebx, array1[esi]
			mov edx, eax
			mov edx, array1[esi]
			and eax, 0x0000f00f
			and ebx, 0x00000ff0
			and edx,0xffff0000

			rol ax, 8
			ror al,4
			ror ah,4
			ror bx, 8
			ror bl, 4
			ror bh, 4
			or eax, ebx
			or edx,eax
			mov[array1 + esi], edx
			add esi, 4
			loop l1


	}
	for (int i = 0; i < 5; i++)
	{
		cout << "result" << (hex) << array1[i] << endl;
	}
}