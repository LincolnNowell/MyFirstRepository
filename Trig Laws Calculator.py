import math


def user():
    print("Type 0 for the missing side or angle you are trying to find.")
    a = int(input("little a? "))
    b = int(input("little b? "))
    c = int(input("little c? "))
    angle_a = int(input("Angle of A?"))
    angle_b = int(input("Angle of B?"))
    angle_c = int(input("Angle of C?"))
    data(a, b, c, angle_a, angle_b, angle_c)


def data(a, b, c, angle_a, angle_b, angle_c):

    if a > 0 and b > 0 and c > 0 and angle_a == 0 and angle_b == 0 and angle_c == 0:
        degree_a(a, b, c)
        degree_b(a, b, c)
        degree_c(a, b, c)
    elif a == 0 and b > 0 and c > 0 and angle_a > 0 and angle_b == 0 and angle_c == 0:
        side_a(b, c, angle_a)
    elif a > 0 and b == 0 and c > 0 and angle_a == 0 and angle_b > 0 and angle_c == 0:
        side_b(a, c, angle_b)
    elif a > 0 and b > 0 and c == 0 and angle_a == 0 and angle_b == 0 and angle_c > 0:
        side_c(a, b, angle_c)
    elif a == 0 and b > 0 and c == 0 and angle_a > 0 and angle_b > 0 and angle_c == 0:
        sin_side_a(b, angle_a, angle_b)
    elif a > 0 and b == 0 and c == 0 and angle_a > 0 and angle_b > 0 and angle_c == 0:
        sin_side_b(a, angle_a, angle_b)
    elif a > 0 and b == 0 and c == 0 and angle_a > 0 and angle_b == 0 and angle_c > 0:
        sin_side_c(a, angle_a, angle_c)
    elif a == 0 and b == 0 and c > 0 and angle_a > 0 and angle_b == 0 and angle_c > 0:
        sin_side_a2(c, angle_c, angle_a)
    elif a == 0 and b == 0 and c > 0 and angle_a == 0 and angle_b > 0 and angle_c > 0:
        sin_side_b2(c, angle_c, angle_b)
    elif a == 0 and b == 0 and c > 0 and angle_a == 0 and angle_b > 0 and angle_c > 0:
        sin_side_c2(c, angle_c, angle_b)
    elif a > 0 and b > 0 and c == 0 and angle_a == 0 and angle_b > 0 and angle_c == 0:
        amb_sin_a(a, b, angle_b)
    elif a > 0 and b > 0 and c == 0 and angle_a > 0 and angle_b == 0 and angle_c == 0:
        amb_sin_b(a, b, angle_a)
    elif a == 0 and b > 0 and c > 0 and angle_a == 0 and angle_b > 0 and angle_c == 0:
        amb_sin_c(c, b, angle_b)
    elif a > 0 and b == 0 and c > 0 and angle_a == 0 and angle_b == 0 and angle_c > 0:
        amb_sin_a2(a, c, angle_c)
    elif a == 0 and b > 0 and c > 0 and angle_a == 0 and angle_b == 0 and angle_c > 0:
        amb_sin_b2(b, c, angle_c)
    elif a > 0 and b == 0 and c > 0 and angle_a > 0 and angle_b == 0 and angle_c == 0:
        amb_sin_c2(c, a, angle_a)
    elif angle_a and angle_b:
        angles(angle_a, angle_b, angle_c)
    else:
        print("Uh oh!\nLets start over.")
        user()


def angles(angle_a, angle_b, angle_c):
    x = list()
    y = []
    x.append(angle_a)
    x.append(angle_b)
    x.append(angle_c)
    for i in x:
        if i < 0:
            y.append(i)
            print(y)


def degree_a(a, b, c):
    t = a ** 2 - ((b ** 2) + (c ** 2))
    g = (-2 * (b * c))
    d = (t / g)
    r = math.degrees(math.acos(d))
    print("Angle A is")
    print(r)


def degree_b(a, b, c):
    t = b ** 2 - ((a ** 2) + (c ** 2))
    g = (-2 * (a * c))
    d = (t / g)
    r = math.degrees(math.acos(d))
    print("Angle B is")
    print(r)


def degree_c(a, b, c):
    t = c ** 2 - ((a ** 2) + (b ** 2))
    g = (-2 * (a * b))
    d = (t / g)
    r = math.degrees(math.acos(d))
    print("Angle C is")
    print(r)


def side_a(b, c, angle_a):
    pt1 = (b**2 + c**2) - (2 * (b * c)) * math.cos(math.radians(angle_a))
    side_a1 = math.sqrt(pt1)
    print(side_a1)


def side_b(a, c, angle_b):
    pt2 = (a**2 + c**2) - (2 * (a * c)) * math.cos(math.radians(angle_b))
    side_a2 = math.sqrt(pt2)
    print(side_a2)


def side_c(a, b, angle_c):
    pt3 = ((a**2) + (b**2)) - (2 * (a * b)) * math.cos(math.radians(angle_c))
    side_a3 = math.sqrt(pt3)
    print(side_a3)


def sin_side_a(b, angle_a, angle_b):
    side = (b / math.sin(math.radians(angle_b))) * math.sin(math.radians(angle_a))
    print(side)


def sin_side_a2(c, angle_c, angle_a):
    side = (c / math.sin(math.radians(angle_c))) * math.sin(math.radians(angle_a))
    print(side)


def sin_side_b(a, angle_a, angle_b):
    side = (a / math.sin(math.radians(angle_a))) * math.sin(math.radians(angle_b))
    print(side)


def sin_side_b2(c, angle_c, angle_b):
    side = (c / math.sin(math.radians(angle_c))) * math.sin(math.radians(angle_b))
    print(side)


def sin_side_c(a, angle_a, angle_c):
    side = (a / math.sin(math.radians(angle_a))) * math.sin(math.radians(angle_c))
    print(side)


def sin_side_c2(b, angle_c, angle_b):
    side = (b / math.sin(math.radians(angle_b))) * math.sin(math.radians(angle_c))
    print(side)


def amb_sin_a(a, b, angle_b):
    r = ((math.sin(math.radians(angle_b))) * a) / b
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_b + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


def amb_sin_b(a, b, angle_a):
    r = ((math.sin(math.radians(angle_a))) * b) / a
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_a + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


def amb_sin_c(c, b, angle_b):
    r = ((math.sin(math.radians(angle_b))) * c) / b
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_b + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


def amb_sin_a2(a, c, angle_c):
    r = ((math.sin(math.radians(angle_c))) * a) / c
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_c + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


def amb_sin_b2(b, c, angle_c):
    r = ((math.sin(math.radians(angle_c))) * b) / c
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_c + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


def amb_sin_c2(c, a, angle_a):
    r = ((math.sin(math.radians(angle_a))) * c) / a
    s = math.degrees(math.asin(r))
    d = 180 - s
    e = int(angle_a + d)
    if e <= 180:
        print("There are two possible angles.")
        print("Angle 1 is {}".format(s))
        print("Angle 2 is {}".format(d))
    else:
        print("The Angle is {}".format(s))


user()

