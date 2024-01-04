#include "GLSLShaderToneMap.h"
#include "ManagerShader.h"
#include "ManagerEnvironmentConfiguration.h"
#include "GLSLUniform.h"
#include "GLSLAttribute.h"
#include "Model.h"
#include "GLView.h"
#include "Camera.h"
using namespace Aftr;


GLSLShaderToneMap* GLSLShaderToneMap::New()
{
   std::string vert = ManagerEnvironmentConfiguration::getSMM() + "shaders/defaultOrthoMGLGUI_GL32.vert";
   std::string frag = ManagerEnvironmentConfiguration::getSMM() + "shaders/GLSLShaderToneMap.frag";

   GLSLShaderDataShared* shdrData = ManagerShader::loadShaderDataShared(vert, frag);
   if (shdrData == nullptr)
      return nullptr;

   GLSLShaderToneMap* shdr = new GLSLShaderToneMap(shdrData);
   return shdr;
}

GLSLShaderToneMap* GLSLShaderToneMap::New(GLSLShaderDataShared* shdrData)
{
   GLSLShaderToneMap* shdr = new GLSLShaderToneMap(shdrData);
   return shdr;
}

GLSLShaderToneMap::GLSLShaderToneMap(GLSLShaderDataShared* dataShared) : GLSLShaderDefaultOrthoWOGUI_GL32(dataShared)
{
}

GLSLShaderToneMap::GLSLShaderToneMap(const GLSLShaderToneMap& toCopy) : GLSLShaderDefaultOrthoWOGUI_GL32(toCopy.dataShared)
{
   *this = toCopy;
}

GLSLShaderToneMap::~GLSLShaderToneMap()
{
   //Parent destructor deletes all uniforms and attributes
}

void GLSLShaderToneMap::bind(const Mat4& MVPMatrix, const ModelMeshSkin& skin)
{
   GLSLShader::bind(); //Must Bind this shader program handle to GL before updating any uniforms

   //update the shader. We must assume it has at least all the uniforms of the Default Shader         
   const std::vector< GLSLUniform* >* uniforms = this->getUniforms();
   //uniforms->at( 0 )->setValues( modelMatrix.getPtr() );
   //uniforms->at( 1 )->setValues( normalMatrix.getPtr() );
   uniforms->at(0)->setValues(skin.getMultiTextureSet()[0].getTexMatrixWithRotScaleAndTrans().getPtr());
   //Mat4 MVPMat = cam.getCameraProjectionMatrix() * cam.getCameraViewMatrix() * modelMatrix;
   uniforms->at(1)->setValues(MVPMatrix.getPtr());
   //uniforms->at( 2 ) //2 is  sampler2D TexUnit0, this is already set to the active texture bound to TEXTURE0

   //Now we populate the Material Properties taken from this skin and send them to the corresponding uniforms in the shader
   uniforms->at(3)->setValues(&(skin.getAmbient().r));
   uniforms->at(4)->setValues(&(skin.getDiffuse().r));
   uniforms->at(5)->setValues(&(skin.getSpecular().r));
   uniforms->at(6)->set(skin.getSpecularCoefficient());
}

GLSLShaderToneMap& Aftr::GLSLShaderToneMap::operator =(const GLSLShaderToneMap& shader)
{
   if (this != &shader)
   {
      //copy all of parent info in base shader, then copy local members in this subclass instance
      GLSLShader::operator=(shader);

      //Now copy local members from this subclassed instance
      //this->mySubclassedLocalVariable = shader.mySubclassedLocalVariable
   }
   return *this;
}

GLSLShader* GLSLShaderToneMap::getCopyOfThisInstance()
{
   GLSLShaderToneMap* copy = new GLSLShaderToneMap(*this);
   return copy;
}
