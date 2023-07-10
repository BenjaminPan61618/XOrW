#include <iostream>
#include <stdlib.h>
#include <string>
char *getenv(const char *name);
int system(const char *string);
using namespace std;
int main()
{
string ret;
ret = getenv("XDG_SESSION_TYPE");
cout <<"Session Type:"<<ret<<endl;
return 0;
}
