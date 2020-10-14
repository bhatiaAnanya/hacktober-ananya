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

if (__name__ == '__main__'):
	arith = Arithmetic(3, 5)
	print(f"Div:{arith.division()}")
		
