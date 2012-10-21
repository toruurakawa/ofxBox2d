//
//  ofxBox2dRevoluteJoint.h
//
//  Created by TORU URAKAWA on 2012/10/21.
//
//

#pragma once
#include "ofxBox2dBaseJoint.h"

class ofxBox2dRevoluteJoint : public ofxBox2dBaseJoint {
    protected:
        b2RevoluteJoint     *joint;
    
    public:
        ofxBox2dRevoluteJoint();
        void    destroy();
    
        void    setup(b2World*, b2Body *body1, b2Body *body2, b2Vec2 anchor, float angle,
                      float lowerLimitRadian, float upperLimitRadian, bool bEnableLimit,
                      float motorSpeed, float maxMotorTorque, bool bEnableMotor, bool bCollideConnected);
      
        float   getLowerLimit();
        float   getUpperLimit();
        void    setEnableLimit(bool);
        bool    isLimitEnabled();
        void    setMotorSpeed(float);
        float   getMotorSpeed();
        void    setMaxMotorTorque(float);
        float   getMotorTorque();
        void    setEnableMotor(bool);
        bool    isMotorEnabled();
};