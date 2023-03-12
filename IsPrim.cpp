#include <iostream>
using namespace std;
int main()
{
    // проверяет на простоту числа. даааа. Этот ассемблер конечно та еще штучка!!!
    int res = 0;
    int n;
    cin >> n;
    _asm {
        mov eax, n
        mov ebx, 2
        for1: cdq
        idiv ebx
        mov eax, n
        cmp ebx, n
        je endll
        add ebx, 1
        cmp edx, 0
        jne for1
        endll :
        cmp ebx, n
            jne end1t
            mov res, 1
            end1t : nop
    }
    if (res == 1) {
        cout << "prim";
    }
    else {
        cout << "not prim";
    }
}

