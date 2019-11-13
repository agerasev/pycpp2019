# List

a = [
	1,
	2.0,
	[3, 4],
]
print(a)

print(a[2])
a.append(4)
b = a + [4, 5]


# Dictionary

b = {
	"a": 1,
	2: "b",
	3.0: "f"
}
print(b["a"])
b["b"] = 2.0
print(b.get("b", 0))

print(b)


# Set

c = {1, 2, 2, 3, 3, (3, 4), (3, 4)}
print(c)

c = set("asbduiwfhiadubwduyadwbbauywadshdasjdjiaosjdawbdnuiawdnauindsjdnuakhdnkuwd")
print(c)


# Tuple

d = (1, 2.0, [4, 5])
d[2][1] = 3.0
print(d)

h = ((3 + 4)*2, (4,), ())
print(h)
e, f, g = h
print(h[0])
print(f[0])
print(g)


# List and tuple slicing

z = [1, 2, 3, 4]
print(z[1:3])
print(z[1:])
print(z[:3])
print(z[:])

y = z[:]
y[0] = -1
print(z)
print(y)

x = [1, 2, 3, 4, 5, 6]
print(x[::3])

print(x[len(x) - 1])
print(x[-1])
