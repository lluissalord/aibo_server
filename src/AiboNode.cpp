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
#include <urbi/uclient.hh>
#include <pthread.h>
#include <stdio.h>
urbi::UCallbackAction onJoint(const urbi::UMessage &msg);
//void *urbiExecute(void*)
//{
   	//std::cout << "urbiEXECUTE"<<std::flush;
	//urbi::execute();
   	//std::cout << "urbiEXECUTE22222"<<std::flush;
	//return NULL;
//}

int main(int argc, char** argv)
{

  ros::init(argc, argv, "aibo_server");
  aibo::AiboServer pepe (argv[1]);

  ROS_INFO ("Aibo Server Started");
  ros::Rate r(5);
  //pthread_t t1;
  //if(pthread_create(&t1, NULL, &urbiExecute,NULL)) {

	//fprintf(stderr, "Error creating thread\n");
	//return 1;
	//}

  //while (ros::ok())
  //{
  	//r.sleep();	
  	//ros::spinOnce();	
  	//pepe.publishState();
  //}
  //if(pthread_join(t1, NULL)) {

	//fprintf(stderr, "Error joining thread\n");
	//return 2;

	//}
  std::cout << "inicioClient"<<std::flush;
  urbi::UClient* client = new urbi::UClient("192.168.0.125", 54000);
  std::cout << "clientcreado"<<std::flush;
  
  client->setCallback(&onJoint, "joint");
  client->send("loop joint << headPan.val;");
  
  std::cout << "llegaExecute"<<std::flush;
  urbi::execute();
 
		
  ROS_INFO("Finished main loop");
  
  return(0);
}

urbi::UCallbackAction onJoint(const urbi::UMessage &msg) {
	printf("Got something!\n");
   double value = (double)msg.value->val;
   std::cout<< value<<std::flush;
  return urbi::URBI_CONTINUE;
}
