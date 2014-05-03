/*
 * Copyright (c) 2012, 2013 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>

#include <boost/shared_ptr.hpp>

#include <zmq.h>

#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>

#include "telepathy.h"

#ifdef TELEPATHY_IS_REMOTE
# define ALCALL
#else
// when not remote, we're in a dll, so export the entry point
# ifdef _WIN32
#  define ALCALL __declspec(dllexport)
# else
#  define ALCALL
# endif
#endif

extern "C"
{
  ALCALL int _createModule(boost::shared_ptr<AL::ALBroker> broker)
  {
    // init broker with the main broker instance
    // from the parent executable
    AL::ALBrokerManager::setInstance(broker->fBrokerManager.lock());
    AL::ALBrokerManager::getInstance()->addBroker(broker);
    // create module instances
    AL::ALModule::createModule<Telepathy>(broker, "Telepathy");
    return 0;
  }

  ALCALL int _closeModule(  )
  {
    return 0;
  }
};

#ifdef TELEPATHY_IS_REMOTE
int main()
{
  void *context = zmq_ctx_new ();
  void *responder = zmq_socket (context, ZMQ_REP);
  int rc = zmq_bind (responder, "tcp://*:5555");

  std::cout << "Hello, world" << std::endl;
  return 0;
}
#endif
