//
//  ofxBox2dDistanceJoint.cpp
//
//  Created by TORU URAKAWA on 2012/10/21.
//
//

#include "ofxBox2dDistanceJoint.h"
#include "ofxBox2dUtils.h"

//----------------------------------------
ofxBox2dDistanceJoint::ofxBox2dDistanceJoint(){
    
}

//----------------------------------------
ofxBox2dDistanceJoint::~ofxBox2dDistanceJoint(){
    destroy();
}

void ofxBox2dDistanceJoint::destroy(){
	if (!alive) return;
	world->DestroyJoint(joint);
	joint       = NULL;
    jointDef    = NULL;
	alive       = false;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setup(b2World *w, b2Body *body1, b2Body *body2, b2Vec2 anchor1, b2Vec2 anchor2,
                                  float _length, float frequencyHZ, float dampingRatio, bool bCollideConnected){
    length                      = _length;
    freqHz                      = frequencyHZ;
    damping                     = dampingRatio;
    
    setWorld(w);
    
	b2DistanceJointDef jointDef;
	jointDef.Initialize(body1, body2, anchor1, anchor2);
	jointDef.collideConnected	= bCollideConnected;
    jointDef.length             = length;
	jointDef.frequencyHz		= freqHz;
	jointDef.dampingRatio		= damping;
    
	joint						= (b2DistanceJoint*)world->CreateJoint(&jointDef);
    
    alive = true;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setup(b2World *w, b2Body *body1, b2Body *body2, b2Vec2 anchor1, b2Vec2 anchor2,
                                  float frequencyHZ, float dampingRatio, bool bCollideConnected){
    freqHz                      = frequencyHZ;
    damping                     = dampingRatio;
    
    setWorld(w);
    
	b2DistanceJointDef jointDef;
	jointDef.Initialize(body1, body2, anchor1, anchor2);
	jointDef.collideConnected	= bCollideConnected;
    jointDef.length             = length;
	jointDef.frequencyHz		= freqHz;
	jointDef.dampingRatio		= damping;
    
    length                      = (float)jointDef.length;
    
	joint						= (b2DistanceJoint*)world->CreateJoint(&jointDef);
    
    alive = true;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setup(b2World *w, b2Body *body1, b2Body *body2,
                                  float _length, float frequencyHZ, float dampingRatio, bool bCollideConnected){
    length                      = _length;
    freqHz                      = frequencyHZ;
    damping                     = dampingRatio;
    
    setWorld(w);
    
	b2DistanceJointDef jointDef;
	jointDef.Initialize(body1, body2, body1->GetWorldCenter(), body2->GetWorldCenter());
	jointDef.collideConnected	= bCollideConnected;
    jointDef.length             = length;
	jointDef.frequencyHz		= freqHz;
	jointDef.dampingRatio		= damping;
    
	joint						= (b2DistanceJoint*)world->CreateJoint(&jointDef);
    
    alive = true;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setup(b2World *w, b2Body *body1, b2Body *body2,
                                  float frequencyHZ, float dampingRatio, bool bCollideConnected){
    freqHz                      = frequencyHZ;
    damping                     = dampingRatio;
    
    setWorld(w);
    
	b2DistanceJointDef jointDef;
	jointDef.Initialize(body1, body2, body1->GetWorldCenter(), body2->GetWorldCenter());
	jointDef.collideConnected	= bCollideConnected;
    jointDef.length             = length;
	jointDef.frequencyHz		= freqHz;
	jointDef.dampingRatio		= damping;
    
    length                      = (float)jointDef.length;
    
	joint						= (b2DistanceJoint*)world->CreateJoint(&jointDef);
}


//----------------------------------------
void ofxBox2dDistanceJoint::setLength(float val){
    length  =   val;
    joint->SetLength((float32)b2dNum(length));
}

//----------------------------------------
float ofxBox2dDistanceJoint::getLength(){
    return length;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setFreq(float val){
    freqHz  =   val;
    joint->SetFrequency((float32)freqHz);
}

//----------------------------------------
float ofxBox2dDistanceJoint::getFreq(){
    return freqHz;
}

//----------------------------------------
void ofxBox2dDistanceJoint::setDampingRatio(float val){
    damping =   val;
    joint->SetDampingRatio((float32)damping);
}

//----------------------------------------
float ofxBox2dDistanceJoint::getDampingRatio(){
    return damping;
}




