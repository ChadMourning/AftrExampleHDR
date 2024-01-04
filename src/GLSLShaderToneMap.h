#pragma once

#include "GLSLShaderDefaultOrthoWOGUI_GL32.h"
#include "VectorFwd.h"
#include "Mat4Fwd.h"

namespace Aftr
{
   class Model;

   class GLSLShaderToneMap : public GLSLShaderDefaultOrthoWOGUI_GL32
   {
   public:
      static GLSLShaderToneMap* New();
      static GLSLShaderToneMap* New(GLSLShaderDataShared* shdrData);
      virtual ~GLSLShaderToneMap();

      GLSLShaderToneMap& operator=(const GLSLShaderToneMap& shader);
      void bind(const Mat4& MVPMatrix, const ModelMeshSkin& skin);

      /**
      Returns a copy of this instance. This is identical to invoking the copy constructor with
      the addition that this preserves the polymorphic type. That is, if this was a subclass
      of GLSLShader with additional members and methods, this will internally create the
      shader instance as that subclass, thereby preserving polymorphic behavior, members, and
      methods.

      This is in contrast with a copy constructor in the case where one performs:
      GLSLShader* myCopy = new GLSLShader( shaderToBeCopied );
      This will always create a GLSLShader* instance, not a subclass corresponding to the exact
      type of shaderToBeCopied.
      */
      virtual GLSLShader* getCopyOfThisInstance();
   protected:
      GLSLShaderToneMap(GLSLShaderDataShared* dataShared);
      GLSLShaderToneMap(const GLSLShaderToneMap&);
   };
}

