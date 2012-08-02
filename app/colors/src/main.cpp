
#include "ofMain.h"
#include "testApp.h"


//========================================================================
int main( )
{

	// this is my "app" :
	testApp APP;
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	run(1024,768, OF_FULLSCREEN, &APP);	

	return 0;

  // that's all folks!
}
