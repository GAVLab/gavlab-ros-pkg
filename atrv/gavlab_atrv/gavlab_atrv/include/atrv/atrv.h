/*!
 * \file atrv/atrv.h
 * \author William Woodall <wjwwood@gmail.com>
 * \version 0.1
 *
 * \section LICENSE
 *
 * The BSD License
 *
 * Copyright (c) 2011 William Woodall
 *
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 *
 * \section DESCRIPTION
 *
 * This provides an interface to the ATRV in the gavlab.
 * 
 * This library depends on CMake-2.4.6 or later: http://www.cmake.org/
 * This library depends on MDC2250: https://github.com/GAVLab/mdc2250
 * 
 */

#ifndef ATRV_H
#define ATRV_H

// Standard Library Headers
#include <string>
#include <sstream>

// Boost Headers
#include <boost/function.hpp>

// MDC2250 Headers
#include "mdc2250/mdc2250.h"

namespace atrv {

/*!
 * This function type describes the prototype for the logging callbacks.
 * 
 * The function takes a std::string reference and returns nothing.  It is 
 * called from the library when a logging message occurs.  This 
 * allows the library user to hook into this and integrate it with their own 
 * logging system.  It can be set with any of the set<log level>Handler 
 * functions.
 * 
 * \see SerialListener::setInfoHandler, SerialListener::setDebugHandler, 
 * SerialListener::setWarningHandler
 */
typedef boost::function<void(const std::string&)> LoggingCallback;

/*!
 * This function type describes the prototype for the exception callback.
 * 
 * The function takes a std::exception reference and returns nothing.  It is 
 * called from the library when an exception occurs in a library thread.
 * This exposes these exceptions to the user so they can to error handling.
 * 
 * \see SerialListener::setExceptionHandler
 */
typedef boost::function<void(const std::exception&)> ExceptionCallback;

/*!
 * Represents an MDC2250 Device and provides and interface to it.
 */
class ATRV {
public:
  /*!
   * Constructs the ATRV object.
   */
  ATRV();
  virtual ~ATRV();

  /*!
   * Connects to the ATRV motor controller given a serial port.
   * 
   * \param port1 Defines the port for the first motor controller.
   * Examples: Linux - "/dev/ttyS0" Windows - "COM1"
   * \param port2 Defines the port for the second motor controller.
   * Examples: Linux - "/dev/ttyS1" Windows - "COM2"
   * 
   * \throws ConnectionFailedException connection attempt failed.
   */
  void connect(std::string port1, std::string port2);

  /*!
   * Disconnects from the ATRV.
   */
  void disconnect();

  /*!
   * Sets the function to be called when an info logging message occurs.
   * 
   * This allows you to hook into the message reporting of the library and use
   * your own logging facilities.
   * 
   * The provided function must follow this prototype:
   * <pre>
   *    void yourInfoCallback(const std::string &msg)
   * </pre>
   * Here is an example:
   * <pre>
   *    void yourInfoCallback(const std::string &msg) {
   *        std::cout << "MDC2250 Info: " << msg << std::endl;
   *    }
   * </pre>
   * And the resulting call to make it the callback:
   * <pre>
   *    Object my_object;
   *    my_object.setInfoCallback(yourInfoCallback);
   * </pre>
   * Alternatively you can use a class method as a callback using boost::bind:
   * <pre>
   *    #include <boost/bind.hpp>
   *    
   *    #include "object.h"
   *    
   *    class MyClass
   *    {
   *    public:
   *     MyClass () {
   *      my_object.setInfoHandler(
   *          boost::bind(&MyClass::handleInfo, this, _1));
   *     }
   *    
   *     void handleInfo(const std::string &msg) {
   *       std::cout << "MyClass Info: " << msg << std::endl;
   *     }
   *    
   *    private:
   *     Object object;
   *    };
   * </pre>
   * 
   * \param info_handler A function pointer to the callback to handle new 
   * Info messages.
   * 
   * \see serial::LoggingCallback
   */
  void setInfoHandler(LoggingCallback info_handler) {
    this->info = info_handler;
  }

  /*!
   * Sets the function to be called when an exception occurs internally.
   * 
   * This allows you to hook into the exceptions that occur in threads inside
   * the library.
   * 
   * \param exception_handler A function pointer to the callback to handle new 
   * interal exceptions.
   * 
   * \see mdc2250::ExceptionCallback, MDC2250::setInfoHandler
   */
  void
  setExceptionHandler (ExceptionCallback exception_handler) {
    this->handle_exc = exception_handler;
  }

private:
  // Exception callback handle
  ExceptionCallback handle_exc;
  LoggingCallback info;

  mdc2250::MDC2250 motor_controller1, motor_controller2;

};

/*!
 * Exception called when a connection to the atrv fails for some reason.
 */
class ConnectionFailedException : public std::exception {
  const std::string e_what_;
  int error_type_;
public:
  ConnectionFailedException(const std::string &e_what, int error_type = 0)
  : e_what_(e_what), error_type_(error_type) {}
  ~ConnectionFailedException() throw() {}

  int error_type() {return error_type_;}

  virtual const char * what() const throw() {
    std::stringstream ss;
    ss << "Connecting to the ATRV: " << this->e_what_;
    return ss.str().c_str();
  }
};

}

#endif
