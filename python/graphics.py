'''import turtle

t = turtle.Turtle()

for i in range(4):
    t.forward(100)   # move forward by 100 units
    t.right(90)      # turn right 90 degrees

turtle.done()'''
import turtle
import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [10, 20, 25, 30]

plt.plot(x, y)
plt.title("Simple Line Graph")
plt.xlabel("X values")
plt.ylabel("Y values")
plt.show()


t = turtle.Turtle()

for i in range(3):
    t.forward(100)
    t.left(120)

turtle.done()
'''
import turtle

colors = ["red", "orange", "yellow", "green", "blue", "purple"]

t = turtle.Turtle()
t.speed(0)

for i in range(36):
    t.color(colors[i % 6])
    for j in range(6):
        t.forward(100)
        t.right(60)
    t.right(10)

turtle.done()'''






