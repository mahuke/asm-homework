#include <iostream>
using namespace std;
void revers(int* a, int n) {
    _asm {
        mov ecx, a
        mov esi, 0
        mov edi, n
        sub edi, 1
        for1: cmp esi, edi
        jge fin
        mov eax, [ecx + 4 * esi]
        mov ebx, [ecx + 4 * edi]
        mov[ecx + 4 * esi], ebx
        mov[ecx + 4 * edi], eax
        add esi, 1
        sub edi, 1
        mov eax, 0
        jmp for1
        fin :
    }
    return;
}
int main()
{
    int* a = new int[12];
    for (int i = 0; i < 12; i++) {
        a[i] = i;
    }
    cout << endl;
    revers(a, 12);
    for (int i = 0; i < 12; i++) {
        cout << a[i] << endl;
    }
}
