class Publisher:
    def __init__(this,name):
        this.name=name 
    def display(this):
        print(f"publisher is {this.name}")
class Book(Publisher):
    def __init__(this,name,title,author):
        super().__init__(name)
        this.title=title
        this.author=author
            
    def display(this):
            print(f"Tile:{this.title}\nAuthor:{this.author}")
        #method overriding    
class Python(Book):
    def __init__(this,name,title,author,price,numofpages):
        super().__init__(name,title,author)
        this.price=price
        this.numofpages=numofpages
                
        #method overriding
    def display(this):
            print(f"price:${this.price}\nnumber of pages:{this.numofpages}")
book=Python(name="DC books",title="deception point",author="dan brown",price=200,numofpages=300)
book.display()
#Book.display(book)
#Publisher.display(book)
                
        