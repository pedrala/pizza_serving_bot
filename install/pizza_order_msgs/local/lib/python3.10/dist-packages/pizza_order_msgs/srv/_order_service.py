# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pizza_order_msgs:srv/OrderService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrderService_Request(type):
    """Metaclass of message 'OrderService_Request'."""

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
                'pizza_order_msgs.srv.OrderService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order_service__request

            from pizza_order_msgs.msg import OrderDetail
            if OrderDetail.__class__._TYPE_SUPPORT is None:
                OrderDetail.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrderService_Request(metaclass=Metaclass_OrderService_Request):
    """Message class 'OrderService_Request'."""

    __slots__ = [
        '_order_id',
        '_table_number',
        '_detail_id',
        '_order_details',
    ]

    _fields_and_field_types = {
        'order_id': 'int8',
        'table_number': 'int8',
        'detail_id': 'int8',
        'order_details': 'sequence<pizza_order_msgs/OrderDetail>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['pizza_order_msgs', 'msg'], 'OrderDetail')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_id = kwargs.get('order_id', int())
        self.table_number = kwargs.get('table_number', int())
        self.detail_id = kwargs.get('detail_id', int())
        self.order_details = kwargs.get('order_details', [])

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
        if self.detail_id != other.detail_id:
            return False
        if self.order_details != other.order_details:
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
            assert value >= -128 and value < 128, \
                "The 'order_id' field must be an integer in [-128, 127]"
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
            assert value >= -128 and value < 128, \
                "The 'table_number' field must be an integer in [-128, 127]"
        self._table_number = value

    @builtins.property
    def detail_id(self):
        """Message field 'detail_id'."""
        return self._detail_id

    @detail_id.setter
    def detail_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'detail_id' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'detail_id' field must be an integer in [-128, 127]"
        self._detail_id = value

    @builtins.property
    def order_details(self):
        """Message field 'order_details'."""
        return self._order_details

    @order_details.setter
    def order_details(self, value):
        if __debug__:
            from pizza_order_msgs.msg import OrderDetail
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, OrderDetail) for v in value) and
                 True), \
                "The 'order_details' field must be a set or sequence and each value of type 'OrderDetail'"
        self._order_details = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_OrderService_Response(type):
    """Metaclass of message 'OrderService_Response'."""

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
                'pizza_order_msgs.srv.OrderService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrderService_Response(metaclass=Metaclass_OrderService_Response):
    """Message class 'OrderService_Response'."""

    __slots__ = [
        '_order_result',
    ]

    _fields_and_field_types = {
        'order_result': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order_result = kwargs.get('order_result', bool())

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
        if self.order_result != other.order_result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order_result(self):
        """Message field 'order_result'."""
        return self._order_result

    @order_result.setter
    def order_result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'order_result' field must be of type 'bool'"
        self._order_result = value


class Metaclass_OrderService(type):
    """Metaclass of service 'OrderService'."""

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
                'pizza_order_msgs.srv.OrderService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__order_service

            from pizza_order_msgs.srv import _order_service
            if _order_service.Metaclass_OrderService_Request._TYPE_SUPPORT is None:
                _order_service.Metaclass_OrderService_Request.__import_type_support__()
            if _order_service.Metaclass_OrderService_Response._TYPE_SUPPORT is None:
                _order_service.Metaclass_OrderService_Response.__import_type_support__()


class OrderService(metaclass=Metaclass_OrderService):
    from pizza_order_msgs.srv._order_service import OrderService_Request as Request
    from pizza_order_msgs.srv._order_service import OrderService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
