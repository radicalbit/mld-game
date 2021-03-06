#ifndef _PHYSICS__H_
#define _PHYSICS__H_
//
//  Physics.h
//  Button
//
//  Created by Axis Sivitz on 12/11/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#include <Box2D/Box2D.h>
#include "GLES-Render.h"
#include "BContactListener.h"
#include "rice/Class.hpp"
#include "rice/Director.hpp"

using namespace Rice;

//#import <vector>

typedef b2Vec2 vec2;

#define VECZERO vec2(0,0)
#define VECNULL vec2(-928484,-2929383)

#define RAD_2_DEG(x) (x * 180.0) / M_PI
#define DEG_2_RAD(x) (x * M_PI) / 180.0

#define ANGLE(vec) (atan2(vec.x,-vec.y))

vec2 midpoint(vec2 one, vec2 two);

using namespace std;

class Physics : public Rice::Director
{
private:

public:
   b2Filter defaultFilter;
   GLESDebugDraw * m_debugDraw;
   BContactListener * m_contactListener;

   b2World * boxworld;

   Physics(Object self);
   ~Physics();
   void initDebugDrawing();
   void debugDraw();
   Object addWall(vec2 pos, vec2 extens);
   Object addBoundaries(float left, float right, float bottom, float top);
   //b2Body * castRay(vec2 from, vec2 to);
   b2Body * addParticle(vec2 pos);
   b2Body * addSensor(vec2 pos, vec2 extens);
   Object addGrenade(vec2 pos, float size);
   Object addPlayer(vec2 pos, float size);
   b2Body * addEmptyBody(vec2 pos);
   b2Body * addDummy(vec2 pos, vec2 extens);
   void remove(b2Body * obj);
   void tick(double time);
   vec2 worldBottomRight();
};

bool isVecZero(vec2 inVec);
float dotProduct(vec2 vec1, vec2 vec2);
vec2 rotate(vec2 inVec, float angle);
vec2 randomOffset();
vec2 lerp(vec2 one, vec2 two, float interp);
vec2 centerPoint(vec2 inPoint);

#endif
