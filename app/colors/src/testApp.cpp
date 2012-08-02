#include "testApp.h"

//---------------------------------------------------------------
testApp::testApp()
{

}

//---------------------------------------------------------------
void testApp::init(){
	
	ofSeedRandom();	
	
	//QUICKTIME VIDEO
	QTPLAYER = new qtVideoPlayer("../../../colorsall.mov");
	myBuffer = new unsigned char[QTPLAYER->w * QTPLAYER->h * 4];
	IT = new ofImgTex(ofNextPow2(QTPLAYER->w), 1, GL_RGBA);	
	//IT = new ofImgTex(ofNextPow2(QTPLAYER->w), ofNextPow2(QTPLAYER->h), GL_RGBA);	
	
	//OTHER
	inc  = 1.0;
		
	GLint sync = 1;
	CGLSetParameter(CGLGetCurrentContext(), kCGLCPSwapInterval, &sync);
	
	//<CORY>
	//mousePos = 20;
	colors_horz_counter = ((QTPLAYER->h)/2);
	
	printf("movieduration %f \n", QTPLAYER->getMovieDurationAPI());
	printf("movietime %f \n" , QTPLAYER->getMovieTimeAPI());	
	printf("movietimescale %f \n", QTPLAYER->getMovieTimeScaleAPI());	
	printf("movieheight %i \n", QTPLAYER->h);	
	
	//Only works on OSX, couldt get glutSetCursor(GLUT_CURSOR_NONE) in Fullscreen more to work, 
	//possibly a bug with GLUT, all other SetCursors works though, GLUT_CURSOR_NONE
	//works with non fullscreen though......
	//http://www.idevgames.com/forum/archive/index.php/t-1321.html
#ifdef TARGET_OSX
	CGDisplayHideCursor(0);
#endif
	glutSetCursor(GLUT_CURSOR_NONE);
	
	//</CORY>
}

//---------------------------------------------------------------
void testApp::idle(){
	
	
	
	ofSetBgColor(0.0, 0.0, 0.0, 1.0);
	
	//UPDATE VIDEO
	QTPLAYER->grabFrame();
	QTPLAYER->fillBufferWithVideoData(myBuffer);
	
	
	
	unsigned char * pointerTo;
	pointerTo =  myBuffer;
	
	pointerTo += QTPLAYER->w * 4 * colors_horz_counter;
	IT->loadImageData(pointerTo, QTPLAYER->w , 1, GL_RGBA);
	
	
	
	//IT->loadImageData(pointerTo, QTPLAYER->w , QTPLAYER->h, GL_RGBA);

	if (QTPLAYER->getMoviePct() == 1)
	{
		QTPLAYER->setMoviePct(0);
		colors_horz_counter = colors_horz_counter + 1;
		//Start over
		if (colors_horz_counter == (QTPLAYER->h-1)){colors_horz_counter =1;}
		printf("looped %i \n", colors_horz_counter);
	}

	
		//glutSetCursor(GLUT_CURSOR_NONE);
	
}



//---------------------------------------------------------------
void testApp::draw(){
	
	ofSetupScreen();	

	glColor4f(1.0, 1.0, 1.0, 1.0);
	int w , h;
	ofGetWindowSize(&w,&h);
	IT->renderTexture(0, h, w, -h);
	
	
}

//---------------------------------------------------------------
void testApp::keyDown  (char c){
	
}

//---------------------------------------------------------------
void testApp::mouseMove( float x, float y ){

}

//---------------------------------------------------------------
void testApp::mouseDrag( float x, float y, int button){

}

//---------------------------------------------------------------
void testApp::mouseDown( float x, float y, int button ){
	
}

//---------------------------------------------------------------
void testApp::mouseUp  ( float x, float y, int button ){

}