#include <iostream>
#include <stdlib.h>
int system(const char *string);
using namespace std;
int main()
{
cout<<"当前会话为:";
cout.flush();
system("echo $XDG_SESSION_TYPE");
return 0;
}
