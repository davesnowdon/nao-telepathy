#include <iostream>
#include <alcommon/albroker.h>

#include "telepathy.h"

Telepathy::Telepathy(boost::shared_ptr<AL::ALBroker> broker,
                   const std::string& name)
  : AL::ALModule(broker, name)
{
  // Describe the module here. This will appear on the webpage
  setModuleDescription("My own custom module.");

  /**
   * Define callable methods with their descriptions:
   * This makes the method available to other cpp modules
   * and to python.
   * The name given will be the one visible from outside the module.
   * This method has no parameters or return value to describe
   * functionName(<method_name>, <class_name>, <method_description>);
   * BIND_METHOD(<method_reference>);
   */
  functionName("printHello", getName(), "Print hello to the world");
  BIND_METHOD(Telepathy::printHello);

  /**
   * addParam(<attribut_name>, <attribut_descrption>);
   * This enables to document the parameters of the method.
   * It is not compulsory to write this line.
   */
  functionName("printWord", getName(), "Print a given word.");
  addParam("word", "The word to be print.");
  BIND_METHOD(Telepathy::printWord);

  /**
   * setReturn(<return_name>, <return_description>);
   * This enables to document the return of the method.
   * It is not compulsory to write this line.
   */
  functionName("returnTrue", getName(), "Just return true");
  setReturn("boolean", "return true");
  BIND_METHOD(Telepathy::returnTrue);

  // If you had other methods, you could bind them here...
  /**
   * Bound methods can only take const ref arguments of basic types,
   * or AL::ALValue or return basic types or an AL::ALValue.
   */
}

Telepathy::~Telepathy()
{
}

void Telepathy::init()
{
  /**
   * Init is called just after construction.
   * Do something or not
   */
  std::cout << returnTrue() << std::endl;
}


void Telepathy::printHello()
{
  std::cout << "Hello!" << std::endl;
}

void Telepathy::printWord(const std::string &word)
{
  std::cout << word << std::endl;
}

bool Telepathy::returnTrue()
{
  return true;
}
