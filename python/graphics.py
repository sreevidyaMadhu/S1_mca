'''import turtle

t = turtle.Turtle()

for i in range(4):
    t.forward(100)   # move forward by 100 units
    t.right(90)      # turn right 90 degrees

turtle.done()
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
from tkinter import *

root = Tk()
root.title("Simple GUI")

label = Label(root, text="Hello, Tkinter!", font=("Arial", 16))
label.pack(pady=20)

root.mainloop()
import turtle
import random

t = turtle.Turtle()
t.speed(0)                   # fastest drawing speed
turtle.bgcolor("black")      # set background color

colors = ["red", "orange", "yellow", "green", "blue", "purple"]

for i in range(100):
    t.color(random.choice(colors))  # choose a random color
    t.circle(i * 2, 45)             # draw part of a circle
    t.left(60)                      # turn a bit
    t.forward(i)                    # move forward

turtle.done()



import turtle

t = turtle.Turtle()
t.speed(0)
t.color("cyan")
turtle.bgcolor("black")

for i in range(36):       # repeat 36 times
    for j in range(5):    # draw a star
        t.forward(100)
        t.right(144)
    t.right(10)           # rotate for next star

turtle.done()

import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 4*np.pi, 100)
y1 = np.sin(x)
y2 = np.cos(x)

plt.plot(x, y1, color='red', label='sin(x)')
plt.plot(x, y2, color='blue', label='cos(x)')
plt.fill_between(x, y1, y2, color='purple', alpha=0.2)
plt.title("Sine and Cosine Waves")
plt.xlabel("X values")
plt.ylabel("Y values")
plt.legend()
plt.grid(True)
plt.show()'''
import turtle
import tkinter as tk
from turtle import RawTurtle, ScrolledCanvas

# Create Tkinter window
root = tk.Tk()
root.title("Tkinter + Turtle Example")

# Create a canvas widget for Turtle
canvas = ScrolledCanvas(root)
canvas.pack(fill=tk.BOTH, expand=True)

# Create Turtle object on that canvas
t = RawTurtle(canvas)
t.color("blue")
t.pensize(2)

# Draw a pattern
for i in range(36):
    t.forward(100)
    t.right(170)

tk.Button(root, text="Exit", command=root.destroy).pack(pady=10)

root.mainloop()





