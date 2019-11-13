print("string")

print("quotes: 'abc'")
print('quotes: "abc"')

#s = "string"
#s[1] = "s"

print("first" + "second")
print("num: " + str(1234))

print("n: %s, m: %s" % ("abc", 0.5))

s = "abc"
s = s[:1] + "d" + s[2:]
print(s)


# Multi-line string
s = '''
if 1 < 2:
    print("1 < 2")
    if 2 < 3:
        print("2 < 3")
elif 2 > 3:
    print("1 >= 2")
elif 3 > 4:
    pass
else:
    pass
'''
# May be used as muti-line comment

print(s)
