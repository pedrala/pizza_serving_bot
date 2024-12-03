// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pizza_order_msgs:srv/OrderService.idl
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
#include "pizza_order_msgs/srv/detail/order_service__struct.h"
#include "pizza_order_msgs/srv/detail/order_service__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "pizza_order_msgs/msg/detail/order_detail__functions.h"
// end nested array functions include
bool pizza_order_msgs__msg__order_detail__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * pizza_order_msgs__msg__order_detail__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pizza_order_msgs__srv__order_service__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
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
    assert(strncmp("pizza_order_msgs.srv._order_service.OrderService_Request", full_classname_dest, 56) == 0);
  }
  pizza_order_msgs__srv__OrderService_Request * ros_message = _ros_message;
  {  // order_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->order_id = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // table_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "table_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->table_number = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // detail_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "detail_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->detail_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // order_details
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_details");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'order_details'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!pizza_order_msgs__msg__OrderDetail__Sequence__init(&(ros_message->order_details), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create pizza_order_msgs__msg__OrderDetail__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    pizza_order_msgs__msg__OrderDetail * dest = ros_message->order_details.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!pizza_order_msgs__msg__order_detail__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pizza_order_msgs__srv__order_service__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OrderService_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pizza_order_msgs.srv._order_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OrderService_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pizza_order_msgs__srv__OrderService_Request * ros_message = (pizza_order_msgs__srv__OrderService_Request *)raw_ros_message;
  {  // order_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->order_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
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
  {  // detail_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->detail_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detail_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // order_details
    PyObject * field = NULL;
    size_t size = ros_message->order_details.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    pizza_order_msgs__msg__OrderDetail * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->order_details.data[i]);
      PyObject * pyitem = pizza_order_msgs__msg__order_detail__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_details", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__struct.h"
// already included above
// #include "pizza_order_msgs/srv/detail/order_service__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pizza_order_msgs__srv__order_service__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
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
    assert(strncmp("pizza_order_msgs.srv._order_service.OrderService_Response", full_classname_dest, 57) == 0);
  }
  pizza_order_msgs__srv__OrderService_Response * ros_message = _ros_message;
  {  // order_result
    PyObject * field = PyObject_GetAttrString(_pymsg, "order_result");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->order_result = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pizza_order_msgs__srv__order_service__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OrderService_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pizza_order_msgs.srv._order_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OrderService_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pizza_order_msgs__srv__OrderService_Response * ros_message = (pizza_order_msgs__srv__OrderService_Response *)raw_ros_message;
  {  // order_result
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->order_result ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "order_result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
