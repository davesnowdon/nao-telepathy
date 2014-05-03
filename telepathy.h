#ifndef TELEPATHY_H
# define TELEPATHY_H

# include <iostream>
# include <alcommon/almodule.h>

namespace AL
{
  // This is a forward declaration of AL:ALBroker which
  // avoids including <alcommon/albroker.h> in this header
  class ALBroker;
}

/**
 * This class inherits AL::ALModule. This allows it to bind methods
 * and be run as a remote executable within NAOqi
 */
class Telepathy : public AL::ALModule
{
public:
  Telepathy(boost::shared_ptr<AL::ALBroker> broker,
           const std::string &name);

  virtual ~Telepathy();

  /**
   * Overloading ALModule::init().
   * This is called right after the module has been loaded
   */
  virtual void init();

  // After that you may add all your bind method.

  // Function which prints "Hello!" on standard output
  void printHello();
  // Function which prints the word given on parameters
  void printWord(const std::string &word);
  // Function which returns true
  bool returnTrue();
};
#endif // TELEPATHY_H
