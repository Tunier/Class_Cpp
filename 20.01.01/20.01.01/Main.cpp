#include "Headers.h"
#include "Stage.h"

int main(void)
{
	cout << "Main()" << endl;
		
	Stage s;
	
	s.Initialize();

	s.Progress();
	s.Render();

	return 0;
}