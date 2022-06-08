
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *  The basis of this file has been automatically generated
 *  by the TeMoto action package generator. Modify this file
 *  as you wish but please note:
 *
 *    WE HIGHLIY RECOMMEND TO REFER TO THE TeMoto ACTION
 *    IMPLEMENTATION TUTORIAL IF YOU ARE UNFAMILIAR WITH
 *    THE PROCESS OF CREATING CUSTOM TeMoto ACTION PACKAGES
 *    
 *  because there are plenty of components that should not be
 *  modified or which do not make sence at the first glance.
 *
 *  See TeMoto documentation & tutorials at: 
 *    https://temoto-telerobotics.github.io
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <class_loader/class_loader.hpp>
#include "ta_sync_test_1/temoto_action.h"
#include <chrono>
#include <thread>

/* 
 * ACTION IMPLEMENTATION of TaSyncTest1 
 */
class TaSyncTest1 : public TemotoAction
{
public:

/*
 * Function that gets invoked only once (when the action is initialized) throughout the action's lifecycle
 */
void initializeTemotoAction()
{

  TEMOTO_INFO_STREAM("Action initialized");
}

/*
 * Function that gets invoked when the action is executed (REQUIRED)
 */
void executeTemotoAction()
{
  getInputParameters();
  
  TEMOTO_INFO_STREAM("Got input string: " << in_param_my_string);
  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  out_param_my_string = "Greetings from " + getUmrfNodeConst().getName();

  setOutputParameters();
}

// Destructor
~TaSyncTest1()
{
  TEMOTO_INFO("Action instance destructed");
}

// Loads in the input parameters
void getInputParameters()
{
  in_param_my_string = GET_PARAMETER("my_string", std::string);
}

// Sets the output parameters which can be passed to other actions
void setOutputParameters()
{
  SET_PARAMETER("my_string", "string", out_param_my_string);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Class members
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Declaration of input parameters
std::string in_param_my_string;

// Declaration of output parameters
std::string out_param_my_string;


}; // TaSyncTest1 class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaSyncTest1, ActionBase);
