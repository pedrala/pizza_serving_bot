// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pizza_order_msgs:msg/CallManager.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "pizza_order_msgs/msg/detail/call_manager__struct.h"
#include "pizza_order_msgs/msg/detail/call_manager__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pizza_order_msgs__msg__call_manager__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("pizza_order_msgs.msg._call_manager.CallManager", full_classname_dest, 46) == 0);
  }
  pizza_order_msgs__msg__CallManager * ros_message = _ros_message;
  {  // table_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "table_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->table_number = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pizza_order_msgs__msg__call_manager__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CallManager */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pizza_order_msgs.msg._call_manager");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CallManager");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pizza_order_msgs__msg__CallManager * ros_message = (pizza_order_msgs__msg__CallManager *)raw_ros_message;
  {  // table_number
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->table_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "table_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
