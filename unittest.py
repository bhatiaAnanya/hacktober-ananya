import unittest
import sys
# sys.path.append('../')
# from arithmetic import Arithmetic
class Arithmetic():

	def __init__(self, a, b):
		self.a = a
		self.b = b

	def division(self):
		try:
			self.div = self.a / self.b
			return self.div
		except ZeroDivisionError:
			pass

class TestArithmetic(unittest.TestCase):

	def initial_setup(self):
		self.arith = Arithmetic(6, 4)

	def test_division(self):
		self.assertEqual(Arithmetic(6, 4).division(), 1.5)
		if (Arithmetic(6, 4).division() != 1.5):
# 		exit(1)

if (__name__ == '__main__'):
	unittest.main()
