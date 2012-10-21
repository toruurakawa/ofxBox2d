//
//  ofxBox2dBaseJoint.h
//
//  Created by TORU URAKAWA on 2012/10/21.
//
//

#pragma once

#include "ofMain.h"
#include "Box2D.h"
//#include "ofxBox2dUtils.h"

class ofxBox2dBaseJoint {
    protected:
        b2World			*world;
        b2Body          *bodyA;
        b2Body          *bodyB;
        b2Vec2          *anchorPointA;
        b2Vec2          *anchorPointB;
        bool            alive;
    
    public:
        ofxBox2dBaseJoint();
        void            setWorld(b2World*);
        bool            isAlive();
        virtual void    destroy();
};