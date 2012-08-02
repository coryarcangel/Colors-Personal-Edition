#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofAux.h"

//#include "ofSampleSound.h"
//#include "ofSampleSoundSystem.h"
#include "qtVideoPlayer.h"
#include "qtVideoGrabber.h"


class testApp : public ofSimpleApp{
	
	public:
		
		testApp();
		virtual void idle();
		virtual void init();
		virtual void draw();
		virtual void keyDown  (char c);
		virtual void mouseMove( float x, float y );
		virtual void mouseDrag( float x, float y, int button  );
		virtual void mouseDown( float x, float y, int button );
		virtual void mouseUp  ( float x, float y, int button );
		
		
		ofImgTex	 	* IT;
		unsigned char 	* myBuffer;
		
		ofImgTex	 	* IT2;
		unsigned char 	* myBuffer2;		
		
	//	ofTTFfont		* myFont;
	//	ofSampleSound   * SOUND;
	//	ofSampleSoundSystem * SOUND_MANAGER;
		qtVideoPlayer   * QTPLAYER;
		qtVideoGrabber  * QTGRABBER;
		
		float inc;
		
		float mousePos;
		
		//<CORY>
		int colors_horz_counter;
		//</CORY>
		
};

#endif	// 