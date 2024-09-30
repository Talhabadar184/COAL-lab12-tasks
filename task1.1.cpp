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

			and eax, 0xff000000
			and ebx, 0x000000ff
			and edx, 0x00ffff00
			ror eax, 24
			ror ebx, 8
			or eax, ebx
			ror edx, 8
			ror dh, 4
			ror dl, 4
			rol edx, 8
			or eax, edx

			mov[array1 + esi], eax
			add esi, 4
			loop l1
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "answer:  " << (hex) << array1[i] << endl;
	}
}