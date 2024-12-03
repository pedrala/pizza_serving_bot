# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pizza_order_msgs:srv/GoalLoc.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GoalLoc_Request(type):
    """Metaclass of message 'GoalLoc_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pizza_order_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pizza_order_msgs.srv.GoalLoc_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__goal_loc__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__goal_loc__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__goal_loc__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__goal_loc__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__goal_loc__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoalLoc_Request(metaclass=Metaclass_GoalLoc_Request):
    """Message class 'GoalLoc_Request'."""

    __slots__ = [
        '_order_id',
        '_table_number',
        '_status',
    ]

    _fields_and_field_types = {
        'order_id': 'int16',
        'table_number': 'int16',
        'status': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_id = kwargs.get('order_id', int())
        self.table_number = kwargs.get('table_number', int())
        self.status = kwargs.get('status', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.order_id != other.order_id:
            return False
        if self.table_number != other.table_number:
            return False
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order_id(self):
        """Message field 'order_id'."""
        return self._order_id

    @order_id.setter
    def order_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_id' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'order_id' field must be an integer in [-32768, 32767]"
        self._order_id = value

    @builtins.property
    def table_number(self):
        """Message field 'table_number'."""
        return self._table_number

    @table_number.setter
    def table_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'table_number' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'table_number' field must be an integer in [-32768, 32767]"
        self._table_number = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value


# Import statements for member types

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GoalLoc_Response(type):
    """Metaclass of message 'GoalLoc_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pizza_order_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pizza_order_msgs.srv.GoalLoc_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__goal_loc__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__goal_loc__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__goal_loc__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__goal_loc__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__goal_loc__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoalLoc_Response(metaclass=Metaclass_GoalLoc_Response):
    """Message class 'GoalLoc_Response'."""

    __slots__ = [
        '_send_result',
        '_x',
        '_y',
    ]

    _fields_and_field_types = {
        'send_result': 'boolean',
        'x': 'float',
        'y': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.send_result = kwargs.get('send_result', bool())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.send_result != other.send_result:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def send_result(self):
        """Message field 'send_result'."""
        return self._send_result

    @send_result.setter
    def send_result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'send_result' field must be of type 'bool'"
        self._send_result = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value


class Metaclass_GoalLoc(type):
    """Metaclass of service 'GoalLoc'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pizza_order_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pizza_order_msgs.srv.GoalLoc')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__goal_loc

            from pizza_order_msgs.srv import _goal_loc
            if _goal_loc.Metaclass_GoalLoc_Request._TYPE_SUPPORT is None:
                _goal_loc.Metaclass_GoalLoc_Request.__import_type_support__()
            if _goal_loc.Metaclass_GoalLoc_Response._TYPE_SUPPORT is None:
                _goal_loc.Metaclass_GoalLoc_Response.__import_type_support__()


class GoalLoc(metaclass=Metaclass_GoalLoc):
    from pizza_order_msgs.srv._goal_loc import GoalLoc_Request as Request
    from pizza_order_msgs.srv._goal_loc import GoalLoc_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
