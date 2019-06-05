import sys 



def main():
    line1 = sys.stdin.readline( ).strip('\n')
    line2 = sys.stdin.readline( ).strip('\n')
    line2 = line2.split(" ")
    
    for i in line2 :
        if i not in line1:
            print("False")
            return 

if __name__ == '__main__':
    main()
    


