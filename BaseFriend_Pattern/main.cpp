#include <iostream>
#include "application.h"


int main()
{
	Game app{800, 600};
	app.loop();

#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}