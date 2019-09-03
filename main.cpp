#include "App.h"
#include <time.h>


int main(int argc, char** argv)
{
	srand(time(0));
	App app;
	return app.onExecute();
}