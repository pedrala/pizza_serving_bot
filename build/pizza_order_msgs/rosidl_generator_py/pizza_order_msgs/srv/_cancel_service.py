# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pizza_order_msgs:srv/CancelService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CancelService_Request(type):
    """Metaclass of message 'CancelService_Request'."""

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
                'pizza_order_msgs.srv.CancelService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cancel_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cancel_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cancel_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cancel_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cancel_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CancelService_Request(metaclass=Metaclass_CancelService_Request):
    """Message class 'CancelService_Request'."""

    __slots__ = [
        '_order_id',
        '_table_number',
    ]

    _fields_and_field_types = {
        'order_id': 'int16',
        'table_number': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_id = kwargs.get('order_id', int())
        self.table_number = kwargs.get('table_number', int())

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CancelService_Response(type):
    """Metaclass of message 'CancelService_Response'."""

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
                'pizza_order_msgs.srv.CancelService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cancel_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cancel_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cancel_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cancel_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cancel_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CancelService_Response(metaclass=Metaclass_CancelService_Response):
    """Message class 'CancelService_Response'."""

    __slots__ = [
        '_cancel_result',
    ]

    _fields_and_field_types = {
        'cancel_result': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cancel_result = kwargs.get('cancel_result', bool())

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
        if self.cancel_result != other.cancel_result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cancel_result(self):
        """Message field 'cancel_result'."""
        return self._cancel_result

    @cancel_result.setter
    def cancel_result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cancel_result' field must be of type 'bool'"
        self._cancel_result = value


class Metaclass_CancelService(type):
    """Metaclass of service 'CancelService'."""

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
                'pizza_order_msgs.srv.CancelService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cancel_service

            from pizza_order_msgs.srv import _cancel_service
            if _cancel_service.Metaclass_CancelService_Request._TYPE_SUPPORT is None:
                _cancel_service.Metaclass_CancelService_Request.__import_type_support__()
            if _cancel_service.Metaclass_CancelService_Response._TYPE_SUPPORT is None:
                _cancel_service.Metaclass_CancelService_Response.__import_type_support__()


class CancelService(metaclass=Metaclass_CancelService):
    from pizza_order_msgs.srv._cancel_service import CancelService_Request as Request
    from pizza_order_msgs.srv._cancel_service import CancelService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
