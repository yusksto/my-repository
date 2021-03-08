#include <iostream>
#include <cstdio>
#include <cassert>

int main()
{
    FILE* cmd = _popen("cmd", "w");
    assert(cmd);
    fprintf(cmd, "ipconfig\n");
}
