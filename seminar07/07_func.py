# Returned value

def func(a):
	if a > 0:
		return -a

print(func(-2))

# Functions arguments

def func(a, b=0, c=1):
	return (a, b, c)

print(func(c=3, b=2, a=-1))


def func(x, *args, a=0, **kwargs):
	return (x, args, a, kwargs)

print(func(1))
print(func(1, 2, 3, a=4, b=5, c=6))


def func():
	return "func"

f = func

print(f())


# Default argument value

def func(x=[1, 2]):
	print(x)
	x[0] -= 1
	x[1] += 1

func()
func()
func()

y = [-1, -2]
func(y)
print(y)

func()


# Nested functions and lambda

def get_func(x):
	def add_x(y):
		return x + y
	return add_x
	#return lambda y: x + y

a = [1, 2]
f = get_func(a)
a[0] = -1

print(f([3, 4]))
