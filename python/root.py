print("enter the coefficients a,b and c of the quadratic equation ax^2+bx+c=0")
a=int(input("a="))
b=int(input("b="))
c=int(input("c="))
d=b**2-4*a*c
if d>0:     
    r1=(-b+d**0.5)/(2*a)
    r2=(-b-d**0.5)/(2*a)
    print("The roots are real and different")
    print("r1=",r1)
    print("r2=",r2)
elif d==0:
    r=-b/2*a
    print("real root",r)
else:
    print("no real roots")

    
     