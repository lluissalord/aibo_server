/*
*  AiboNode.cpp
*  Copyright (c) 2013 Ricardo Tellez
*  Created on: 17-November-2013
*  Author: Ricardo Tellez
*  email: r_tellez@ouroboros.org
*
*/

#include "AiboServer.h"

#include <urbi/usyncclient.hh>
#include <urbi/uabstractclient.hh>

#include <aibo_server/IRArray.h>
#include <aibo_server/BumperArray.h>
#include <aibo_server/Accel.h>
#include <aibo_server/Sound.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/JointState.h>
#include <aibo_server/TouchArray.h>

#define NUM_MOTORS 18

namespace aibo
{

  AiboServer::AiboServer(const char* IP) :
    _nh( "~" )
  {

    _client = new urbi::UClient(IP, 54000);

    /**if (_client->error() )  //  Validation of the client creation
      ROS_ERROR ("Error connecting to the Urbi Server %s", IP);
      urbi::exit(1);
*/
    // set the topics that will publish the Aibo sensor values
    _aiboIR = _nh.advertise<aibo_server::IRArray>("/aibo/infrared", 1, false);
    _aiboSound = _nh.advertise<aibo_server::Sound>("/aibo/sound", 1, false);
    _aiboImage = _nh.advertise<sensor_msgs::Image>("/aibo/image", 1, false);
    _aiboJoint = _nh.advertise<sensor_msgs::JointState>("/aibo/joints", 1, false);
    _aiboAccel = _nh.advertise<aibo_server::Accel>("/aibo/accel", 1, false);
    _aiboPaw = _nh.advertise<aibo_server::BumperArray>("/aibo/paws", 1, false);
    _aiboTouch = _nh.advertise<aibo_server::TouchArray>("/aibo/touch", 1, false);

    // set callbacks for sensors
    
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceChest");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceNear");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceFar");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onSoundSensor),"speaker");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onImageSensor),"camera");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"neck");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"headTilt");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"headPan");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"tailPan");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"tailTilt");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"mouth");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceChest");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceNear");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onDistanceSensor),"distanceFar");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onSoundSensor),"speaker");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onImageSensor),"camera");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRF3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legRH3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLF3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH1");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH2");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"legLH3");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"neck");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"headTilt");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"headPan");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"tailPan");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"tailTilt");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onJointSensor),"mouth");
    
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelX");
    //_client->send("loop accelX << accelX.val},");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelY");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelZ");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawLF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawLH");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawRF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawRH");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"chinsensor");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorM");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorR");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"headsensor");
   
   
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelX");
    //_client->send("loop accelX << accelX.val},");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelY");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onAccelSensor),"accelZ");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawLF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawLH");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawRF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onPawSensor),"pawRH");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"chinsensor");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorF");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorM");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"backsensorR");
    //_client->setCallback (urbi::callback(*this, &AiboServer::onTouchSensor),"headsensor");
    _client->setCallback (urbi::callback(*this, &AiboServer::onJoint),"headPan");
    _client->send("loop joint << headPan.val;");
    _client->send ("motors on;");  // activates motors
    setBlendingmode();
    //startPosition();
    	std::cout << "start"<<std::flush;
	

  }

  AiboServer::~AiboServer()
  {
    delete _client;
  }
  urbi::UCallbackAction AiboServer::onJoint(const urbi::UMessage &msg) {
	printf("Got something!\n");
   double value = (double)msg.value->val;
   std::cout<< value<<std::flush;
  return urbi::URBI_CONTINUE;
}
  urbi::UCallbackAction AiboServer::onTouchSensor(const urbi::UMessage &msg) 
  {
    if (msg.type != urbi::MESSAGE_DATA)
      return urbi::URBI_CONTINUE;
    
    double value = (double)msg.value->val;
    if (msg.tag == "chinsensor")
      _touch1 = value;
    else
    {
      if (msg.tag == "backsensorF")
        _touch2 = value;
      else 
      {
        if (msg.tag == "backsensorM")
          _touch3 = value;
        else
        {
          if (msg.tag == "backsensorR")
            _touch4 = value;
          else
            _touch5 = value; // for headsensor case
        }
      }
    }

    return urbi::URBI_CONTINUE;
  }
  
  urbi::UCallbackAction AiboServer::onPawSensor(const urbi::UMessage &msg) 
  {
    if (msg.type != urbi::MESSAGE_DATA)
      return urbi::URBI_CONTINUE;

    return urbi::URBI_CONTINUE;
  }
  
  urbi::UCallbackAction AiboServer::onAccelSensor(const urbi::UMessage &msg) 
  {
    std::cout << "gikugsgs"<<std::flush;
    if (msg.type != urbi::MESSAGE_DATA)
      return urbi::URBI_CONTINUE;
	
    double value = (double)msg.value->val;
    
    if (msg.tag == "distanceChest")
      _IRChest = value;
    else
    {
      if (msg.tag == "distanceNear")
        _IRNear = value;
      else 
        _IRFar = value;
    }
    
    return urbi::URBI_CONTINUE;
  }
  
  urbi::UCallbackAction AiboServer::onJointSensor(const urbi::UMessage &msg) 
  {
    if (msg.type != urbi::MESSAGE_DATA)
      return urbi::URBI_CONTINUE;

    return urbi::URBI_CONTINUE;
  }
  
  urbi::UCallbackAction AiboServer::onImageSensor(const urbi::UMessage &msg) 
  {
    
   /* if (msg.type != urbi::MESSAGE_DATA || ((urbi::UImage)msg).imageFormat == urbi::IMAGE_UNKNOWN)
      return urbi::URBI_CONTINUE;

    urbi::UImage uimage = (urbi::UImage)msg;
    
    msg.client.printf("Image of size (%d,%d) received from server \n",_image.width, _image.height);
*/
    return urbi::URBI_CONTINUE;
  }
  
  urbi::UCallbackAction AiboServer::onSoundSensor(const urbi::UMessage &msg) 
  {
    /*
    if (msg.type != urbi::MESSAGE_DATA || urbi::USound(msg).soundFormat == urbi::SOUND_UNKNOWN)
    return urbi::URBI_CONTINUE;

    _sound = (urbi::USound)msg; */

    return urbi::URBI_CONTINUE;
  }

  urbi::UCallbackAction AiboServer::onDistanceSensor(const urbi::UMessage &msg) 
  {
    if (msg.type != urbi::MESSAGE_DATA)
      return urbi::URBI_CONTINUE;

    double value = (double)msg.value->val;
    
    if (msg.tag == "distanceChest")
      _IRChest = value;
    else
    {
      if (msg.tag == "distanceNear")
        _IRNear = value;
      else 
        _IRFar = value;
    }
    
    return urbi::URBI_CONTINUE;
  }
      


  void AiboServer::setBlendingmode()
  {
    // Stablishes the default mode of accepting conflicting assignments 
    for (int i=0; i<NUM_MOTORS; i++)
    {
      char command[100];
      sprintf (command,"blend[cancel] %s.val,",MOTORS[i]);
      _client->send(command);
      usleep (1000);
    }
  }


  void AiboServer::startPosition()
  {
    // Makes Aibo take the starting position  //////////////////////////
      // sends broadbase position to joints
    for (int i=0; i<NUM_MOTORS; i++)
    {
      char command[100];
      sprintf (command,"%s.val=%d smooth:2800,",MOTORS[i],BROADBASE_ANGLE[i]);
      _client->send(command);
      usleep (10000);
    }
    usleep(2000000);
      // sends sleeping position to joints
    for (int i=0; i<NUM_MOTORS; i++)
    {
      char command2[100];
      sprintf (command2,"%s.val=%d smooth:2800,",MOTORS[i],SLEEPING_ANGLE[i]);
      _client->send(command2);
      usleep(10000);
    }
    usleep(2000000);
      // sends stand up position to joints
    for (int i=0; i<NUM_MOTORS; i++)
    {
      char command3[100];
      sprintf (command3,"%s.val=%d smooth:2800,",MOTORS[i],CROUCHING_ANGLE[i]);
      _client->send(command3);
      usleep(10000);
    }
    usleep(2000000);
    for (int i=0; i<NUM_MOTORS; i++)
    {
      char command4[100];
      sprintf (command4,"%s.val=%d smooth:2800,",MOTORS[i],STANDUP_ANGLE[i]);
      _client->send(command4);
      usleep(10000);
    }
    usleep(2000000);
  }


  void AiboServer::publishState()
  {
    publishIRsMsg();
    publishSoundMsg();
    publishImageMsg();
    publishJointMsg();
    publishAccelMsg();
    publishPawMsg();
    publishTouchMsg();
  }


  void AiboServer::publishIRsMsg()
  {

    if (_aiboIR.getNumSubscribers() > 0)
    {
      aibo_server::IRArray msgArray;
      sensor_msgs::Range msg;
      msg.radiation_type = sensor_msgs::Range::INFRARED;
      msg.range = _IRChest;
      msgArray.IRs.push_back (msg);
      msg.range = _IRNear;
      msgArray.IRs.push_back (msg);
      msg.range = _IRFar;
      msgArray.IRs.push_back (msg);
      _aiboIR.publish(msgArray);
    }
  }

  void AiboServer::publishTouchMsg()
  {
    if (_aiboTouch.getNumSubscribers() > 0)
    {
      aibo_server::TouchArray msg;
      msg.touch.push_back(_touch1);
      msg.touch.push_back(_touch2);
      msg.touch.push_back(_touch3);
      msg.touch.push_back(_touch4);
      msg.touch.push_back(_touch5);
      _aiboTouch.publish(msg);
    }
  }

  void AiboServer::publishSoundMsg()
  {
    if (_aiboSound.getNumSubscribers() > 0)
    {
      aibo_server::Sound msg;
      _aiboSound.publish(msg);
    }
  }

  void AiboServer::publishJointMsg()
  {
    if (_aiboJoint.getNumSubscribers() > 0)
    {
      sensor_msgs::JointState msg;
      _aiboJoint.publish(msg);
    }
  }

  void AiboServer::publishImageMsg()
  {
    if (_aiboImage.getNumSubscribers() > 0)
    {
      sensor_msgs::Image msg;
      _aiboImage.publish (msg);
    }
  }

  void AiboServer::publishPawMsg()
  {
    if (_aiboPaw.getNumSubscribers() > 0)
    {
      aibo_server::BumperArray msg;
      _aiboPaw.publish(msg);
    }
  }

  void AiboServer::publishAccelMsg()
  {
    if (_aiboAccel.getNumSubscribers() > 0)
    {
      aibo_server::Accel msg;
      _aiboAccel.publish(msg);
    }
  }

	

}
