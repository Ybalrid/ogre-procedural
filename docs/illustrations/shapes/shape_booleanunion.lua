s1 = Procedural.RectangleShape():realizeShape()
s2 = Procedural.RectangleShape():realizeShape()
s2:translate(0.5,0.5)
s = s1:booleanUnion(s2):getShape(0)
tests:addShape(s)