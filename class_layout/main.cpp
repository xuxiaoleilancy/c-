#include <iostream>
using namespace std;

class MyBase
{
	int a;
	int b;
public:
	void CommonFunction();
	void virtual VirtualFunction();
};
class DerivedClass : public MyBase
{
	int f;
public:
	void DerivedCommonFunction();
	void virtual VirtualFunction();
	void virtual VirtualFunction2();
};
int main( int argc , char** argv )
{
    cout<<"hello"<<endl;
    return 0;
}
