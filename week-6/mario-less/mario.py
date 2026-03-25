def main():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0:
                piramid(height)
                break
        except ValueError:
            pass

def piramid(n):
    for i in range(n):
        for j in range(i+1):
            print("#", end="")
        print()
main()