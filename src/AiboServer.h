/*
*  AiboNode.cpp
*  Copyright (c) 2013 Ricardo Tellez
*  Created on: 04-December-2013
*  Author: Ricardo Tellez
*  email: r_tellez@ouroboros.org
*
*/

#include <ros/ros.h>
#include <urbi/uclient.hh>
#include "AiboParams.h"

namespace aibo
{

    class AiboServer
    {

      public:
      
        AiboServer(const char* IP);
        virtual ~AiboServer();
        urbi::UClient* _client;
        
        urbi::UCallbackAction onDistanceSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onSoundSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onImageSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onJointSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onAccelSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onPawSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onTouchSensor(const urbi::UMessage &msg);
        urbi::UCallbackAction onJoint(const urbi::UMessage &msg);	

        void publishState();
        
      private:

          // Paws
          bool _pawFL, _pawFR, _pawRL, _pawRR;

          // Joints
          double _jointFR1,_jointFR2,_jointFR3;
          double _jointFL1,_jointFL2,_jointFL3;
          double _jointRR1,_jointRR2,_jointRR3;
          double _jointRL1,_jointRL2,_jointRL3;
          double _tailPan, _tailTilt;
          double _headTilt, _headPan, _headNeck, _headMouth;

          // Image
          urbi::UImage _image;

          // Sound
          urbi::USound _sound;

          // Accel
          double _accelX, _accelY, _accelZ;

          // Touch
          double _touch1, _touch2, _touch3, _touch4, _touch5;

          //IRs
          double _IRChest, _IRNear, _IRFar;

          ros::NodeHandle _nh;
          
          ros::Publisher _aiboIR;
          ros::Publisher _aiboSound;
          ros::Publisher _aiboImage;
          ros::Publisher _aiboJoint;
          ros::Publisher _aiboAccel;
          ros::Publisher _aiboPaw;
          ros::Publisher _aiboTouch;
          
          void setBlendingmode();
          void startPosition();

          void publishIRsMsg();
          void publishTouchMsg();
          void publishSoundMsg();
          void publishJointMsg();
          void publishImageMsg();
          void publishPawMsg();
          void publishAccelMsg();
          
    };
}
