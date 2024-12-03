# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pizza_order_msgs:msg/OrderDetail.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrderDetail(type):
    """Metaclass of message 'OrderDetail'."""

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
                'pizza_order_msgs.msg.OrderDetail')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__order_detail
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__order_detail
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__order_detail
            cls._TYPE_SUPPORT = module.type_support_msg__msg__order_detail
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__order_detail

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class OrderDetail(metaclass=Metaclass_OrderDetail):
    """Message class 'OrderDetail'."""

    __slots__ = [
        '_detail_id',
        '_item_id',
        '_item_name',
        '_quantity',
        '_price',
    ]

    _fields_and_field_types = {
        'detail_id': 'int32',
        'item_id': 'int8',
        'item_name': 'string',
        'quantity': 'int8',
        'price': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.detail_id = kwargs.get('detail_id', int())
        self.item_id = kwargs.get('item_id', int())
        self.item_name = kwargs.get('item_name', str())
        self.quantity = kwargs.get('quantity', int())
        self.price = kwargs.get('price', float())

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
        if self.detail_id != other.detail_id:
            return False
        if self.item_id != other.item_id:
            return False
        if self.item_name != other.item_name:
            return False
        if self.quantity != other.quantity:
            return False
        if self.price != other.price:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
            assert value >= -2147483648 and value < 2147483648, \
                "The 'detail_id' field must be an integer in [-2147483648, 2147483647]"
        self._detail_id = value

    @builtins.property
    def item_id(self):
        """Message field 'item_id'."""
        return self._item_id

    @item_id.setter
    def item_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'item_id' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'item_id' field must be an integer in [-128, 127]"
        self._item_id = value

    @builtins.property
    def item_name(self):
        """Message field 'item_name'."""
        return self._item_name

    @item_name.setter
    def item_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'item_name' field must be of type 'str'"
        self._item_name = value

    @builtins.property
    def quantity(self):
        """Message field 'quantity'."""
        return self._quantity

    @quantity.setter
    def quantity(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'quantity' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'quantity' field must be an integer in [-128, 127]"
        self._quantity = value

    @builtins.property
    def price(self):
        """Message field 'price'."""
        return self._price

    @price.setter
    def price(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'price' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'price' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._price = value
