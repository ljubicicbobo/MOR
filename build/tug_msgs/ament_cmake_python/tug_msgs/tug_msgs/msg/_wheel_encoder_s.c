// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tug_msgs:msg/WheelEncoder.idl
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
#include "tug_msgs/msg/detail/wheel_encoder__struct.h"
#include "tug_msgs/msg/detail/wheel_encoder__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tug_msgs__msg__wheel_encoder__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("tug_msgs.msg._wheel_encoder.WheelEncoder", full_classname_dest, 40) == 0);
  }
  tug_msgs__msg__WheelEncoder * ros_message = _ros_message;
  {  // left_counter
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_counter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_counter = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // right_counter
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_counter");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_counter = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tug_msgs__msg__wheel_encoder__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of WheelEncoder */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tug_msgs.msg._wheel_encoder");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "WheelEncoder");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tug_msgs__msg__WheelEncoder * ros_message = (tug_msgs__msg__WheelEncoder *)raw_ros_message;
  {  // left_counter
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->left_counter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_counter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_counter
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->right_counter);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_counter", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
