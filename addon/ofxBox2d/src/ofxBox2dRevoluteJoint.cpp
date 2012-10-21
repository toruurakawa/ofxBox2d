//
//  ofxBox2dRevoluteJoint.cpp
//
//  Created by TORU URAKAWA on 2012/10/21.
//
//


#include "ofxBox2dRevoluteJoint.h"
//ofxBox2dRevoluteJoint();
//virtual ~ofxBox2dRevoluteJoint();
//void    destroy();
//
//float   getLowerAngel();
//float   getUpperAngle();
//void    setEnableLimit(bool);
//bool    isEnableLimit();
//void    setMaxMotorLimit(float);
//float   getMaxMotorLimit();
//void    setEnableMotor(bool);
//bool    isEnableMotor();


//----------------------------------------
ofxBox2dRevoluteJoint::ofxBox2dRevoluteJoint(){
    
}

//----------------------------------------
void ofxBox2dRevoluteJoint::destroy(){
    if (world == NULL || joint == NULL) return;
	world->DestroyJoint(joint);
	joint       = NULL;
}

//----------------------------------------
void ofxBox2dRevoluteJoint::setup(b2World *w, b2Body *body1, b2Body *body2, b2Vec2 anchor, float angle,
                                  float lowerLimitRadian, float upperLimitRadian, bool bEnableLimit,
                                  float motorSpeed, float maxMotorTorque, bool bEnableMotor,
                                  bool bCollideConnected){
    setWorld(w);
    
    b2RevoluteJointDef jointDef;
	jointDef.Initialize(body1, body2, anchor);
	jointDef.collideConnected	= bCollideConnected;
    jointDef.referenceAngle     = angle;
    jointDef.lowerAngle         = lowerLimitRadian;
    jointDef.upperAngle         = upperLimitRadian;
    jointDef.enableLimit        = bEnableLimit;
    jointDef.motorSpeed         = motorSpeed;
    jointDef.maxMotorTorque     = maxMotorTorque;
    jointDef.enableMotor        = bEnableMotor;
 
	joint						= (b2RevoluteJoint*)world->CreateJoint(&jointDef);

    alive = true;
}

//----------------------------------------
float ofxBox2dRevoluteJoint::getLowerLimit(){
    return (float)joint->GetLowerLimit();
}

//----------------------------------------
float ofxBox2dRevoluteJoint::getUpperLimit(){
    return (float)joint->GetUpperLimit();
}

//----------------------------------------
void ofxBox2dRevoluteJoint::setEnableLimit(bool flag){
    joint->EnableLimit(flag);
}

//----------------------------------------
bool ofxBox2dRevoluteJoint::isLimitEnabled(){
    return (float)joint->IsLimitEnabled();
}

//----------------------------------------
void ofxBox2dRevoluteJoint::setMotorSpeed(float val){
    joint->SetMotorSpeed((float32)val);
}

//----------------------------------------
float ofxBox2dRevoluteJoint::getMotorSpeed(){
    joint->GetMotorSpeed();
}

//----------------------------------------
void ofxBox2dRevoluteJoint::setMaxMotorTorque(float val){
    joint->SetMaxMotorTorque((float32)val);
}

//----------------------------------------
float ofxBox2dRevoluteJoint::getMotorTorque(){
    return (float)joint->GetMotorTorque();
}

//----------------------------------------
void ofxBox2dRevoluteJoint::setEnableMotor(bool flag){
    joint->EnableMotor(flag);
}


