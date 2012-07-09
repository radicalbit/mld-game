#include "Platform.h"
#include <iostream>

#include "rice/Class.hpp"
#include "rice/String.hpp"
#include "rice/Array.hpp"
#include "rice/Constructor.hpp"
#include "rice/Data_Type.hpp"

using namespace Rice;
using namespace std;

Platform::Platform(Object self) : Rice::Director(self)
{
   window = new sf::Window(sf::VideoMode(800, 600), "OpenGL");
   window->setVerticalSyncEnabled(true);

   renderer = new Renderer();
}

Platform::~Platform()
{
   delete renderer;
   delete window;
}

void Platform::update()
{
   sf::Event event;
   while (window->pollEvent(event))
   {
      // Close window : exit
      if (event.type == sf::Event::Closed)
         window->close();
      else if (event.type == sf::Event::KeyPressed)
      {
         getSelf().call("key_pressed", (int)event.key.code);
      }
   }

   renderer->draw();
   window->display();
}

bool Platform::isWindowOpen()
{
   return window->isOpen();
}

void Platform::addDrawCommand(Array a)
{
   if (a.size() == 16)
   {
      VALUE * carr = a.to_c_array();
      float m[16];
      for (int i = 0; i < 16; i++)
      {
         m[i] = (float)NUM2DBL(carr[i]);
      }
      renderer->addCommand(m);
   }
}

void Platform::setViewMatrix(Array a)
{
   if (a.size() == 16)
   {
      VALUE * carr = a.to_c_array();
      for (int i = 0; i < 16; i++)
      {
         renderer->viewMatrix[i] = (float)NUM2DBL(carr[i]);
      }
   }
}

   extern "C"
void Init_engine()
{
   Data_Type<Platform> rb_cPlatform =
      define_class<Platform>("Platform")
      .define_constructor(Constructor<Platform, Rice::Object>())
      .define_method("addDrawCommand", &Platform::addDrawCommand)
      .define_method("setViewMatrix", &Platform::setViewMatrix)
      .define_method("isWindowOpen", &Platform::isWindowOpen)
      .define_method("update", &Platform::update);

   /*
   Data_Type<Renderer> rb_cRenderer =
      define_class<Renderer>("Renderer")
      .define_constructor(Constructor<Renderer>())
      .define_method("update", &Platform::update);
      */
}
