#ifndef MLD_BODY_H_
#define MLD_BODY_H_

#include "Renderer.h"
#include "Physics.h"
#include "rice/Array.hpp"
#include "rice/Director.hpp"
#include <SFML/Window.hpp>

using namespace Rice;

class Body // : public Rice::Director
{

   public:
   const b2Body * body;
   //Platform(Object self);
   //~Body(Object self);
   Object pos();
};

template<>
Rice::Object to_ruby<vec2>(vec2 const & param);

template<>
vec2 from_ruby<vec2>(Rice::Object x);

#endif

