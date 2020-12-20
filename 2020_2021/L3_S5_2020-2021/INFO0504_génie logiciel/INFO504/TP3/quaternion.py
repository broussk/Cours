import math
import numpy
import sys

# From Numeric
array   = numpy.array
asarray = numpy.asarray
sum     = numpy.sum
Float32 = numpy.float32

# From Math
sqrt = math.sqrt
sin = math.sin
cos = math.cos
pi  = math.pi
atan2 = math.atan2

class Quaternion(object):
    """Quaternion object implementation"""

    __slots__ = ('internal')

    def _getW(self):
        return self.internal[0]
    def _setW(self, newValue):
        self.internal[0] = newValue
    _doc = """W coordinate of quaternion vector"""
    W = property(_getW, _setW, doc=_doc)

    def _getX(self):
        return self.internal[1]
    def _setX(self, newValue):
        self.internal[1] = newValue
    _doc = """X coordinate of quaternion vector"""
    X = property(_getX, _setX, doc=_doc)

    def _getY(self):
        return self.internal[2]
    def _setY(self, newValue):
        self.internal[2] = newValue
    _doc = """Y coordinate of quaternion vector"""
    Y = property(_getY, _setY, doc=_doc)

    def _getZ(self):
        return self.internal[3]
    def _setZ(self, newValue):
        self.internal[3] = newValue
    _doc = """Z coordinate of quaternion vector"""
    Z = property(_getZ, _setZ, doc=_doc)

    def _getXYZ(self):
        return self.internal[1:]
    def _setXYZ(self, newValue):
        self.internal[1:] = newValue[:]
    _doc = """XYZ coordinate of quaternion vector"""
    XYZ = property(_getXYZ, _setXYZ, doc=_doc)

    def __init__(self, elements=[1,0,0,0]):#create objet
        """
        Initializer of a 4-elements array of floats
        Default values are those for a unit multiplication quaternion
        """

        #if isinstance(elements, list):
        #    if len(elements) == 3:
        #        elements = [0] + elements
        #    elements = asarray(elements, Float32)
        #elif (isinstance(elements, float) or isinstance(elements, int)):
        #    elements = asarray([elements,0,0,0], Float32)
            
        self.internal = elements

    def __str__(self):
        """
        Get the representation of a quaternion object.
        """
        return str(self.internal)

    def __repr__(self):
        """
        Get the object id
        """
        return id(self)

    def __eq__(self, other):
        """
        Check the equality of two quaternion objects.
        """
        if isinstance(other, self.__class__):
            return repr(self) == repr(other)
        return False

    def __add__(self, other):
        """
        Return the 2 quaternion sum
        """
        if not isinstance(other, self.__class__):
            other = self.__class__(other)
        return self.__class__(self.internal + other.internal)

    def __sub__(self, other):
        """
        Return the 2 quaternion substraction
        """
        if not isinstance(other, self.__class__):
            other = self.__class__(other)
        return self.__class__(self.internal - other.internal)
    
    def __mul__(self, other):
        """ 
        Return the 2 quaternion product
        """ 
        if not isinstance(other, self.__class__):
            other = self.__class__(other)
        w1, x1, y1, z1 = self.internal
        w2, x2, y2, z2 = other.internal
        w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
        x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
        y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2
        z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2
        return self.__class__([w, x, y, z])

    def __neg__(self):
        """
        Return the opposite quaternion
        """
        return self.__class__(-self.internal)

    def conj(self):
        """
        Return the conjugate quaternion
        """
        w, x, y, z = self.internal
        return self.__class__([w, -x, -y, -z])

    def __abs__(self):
        """
        Return the quaternion norm
        """
        internal = self.internal
        return sqrt(sum(internal * internal))

    def __div__(self, other):
        """
        Return the 2 quaternion division
        """
        if not isinstance(other, self.__class__):
            other = self.__class__(other)
        return self.__class__((self * other.conj()).internal / (abs(other)**2))

    def inv(self):
        """
        Return the inverse quaternion
        """
        return self.conj() / (abs(self)**2)

    def __pow__(self, power):
        """
        Return the powered quaternion
        """
        if power == -1:
            return self.inv()
        elif power == 0:
            return self.__class__()
        elif power == 1:
            return self
        elif power > 1:
            return self * (self**(power-1))
        else:
            return (self**(abs(power))).inv()

    def norm(self):
        elements = self.internal.copy()
        length = sqrt(sum(elements * elements))
        if length != 1:
            elements = elements / length
        return self.__class__(elements)

    def copy(self):
        """
        Return a copy of the quaternion
        """
        return self.__class__(self.internal.copy())

    def XYZA(self):
        """
        Return the rotation axis and the rotation angle ([X,Y,Z],A)
        """
        w, x, y, z = self.norm().internal

        aw=acos(w)
        scale = sin(aw)
        if not scale:
            return None
        return ([x / scale, y / scale, z / scale], 2 * aw)

