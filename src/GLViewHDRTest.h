#pragma once

#include "GLView.h"

namespace Aftr
{
   class Camera;
   class WOLight;

/**
   \class GLViewHDRTest
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewHDRTest : public GLView
{
public:
   static GLViewHDRTest* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewHDRTest();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createHDRTestWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );

protected:
   GLViewHDRTest( const std::vector< std::string >& args );
   virtual void onCreate();   
   WOLight* light1 = nullptr;
   WOLight* light2 = nullptr;
   WOLight* light3 = nullptr;
   WOLight* light4 = nullptr;
};

/** \} */

} //namespace Aftr
