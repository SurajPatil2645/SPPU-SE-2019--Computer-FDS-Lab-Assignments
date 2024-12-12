'''Write a python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Insertion sort b) Shell sort and display top five scores.
'''
print("enter 1 for insertion sort:")
print("enter 2 for shell Sort:")
print("enter 3 for exit:")
choice=int(input("enter your choice:"))
def switch (choice):
	if choice==1:
		insertion_sort()
	
	elif choice==2:
		shell_sort()
		
	elif choice==3:
		print("you are successfully exited")
	
	else:
		print("you entered a wrong choice")


def insertion_sort():
	n=int(input('Enter num of students:'))
	l=[]
	for i in range(n):
		N=int(input('enter percentage of student: '))
		l.append(N)
	print("unsorted array is :",l)
	for i in range(1,n):
		a=l[i]
		j=i-1
	
		
		while j>=0:
			if (l[j]>l[j+1]):
				temp=l[j+1]
				l[j+1]=l[j]
				l[j]=temp
			else :
				break
			j-=1
			l[j+1]=a
	print("Sorted list using Insertion sort is:\n",l)
	print("Top five scores are : ",l[-1:-6:-1]) 



def shell_sort():
    n=int(input('Enter num of students:'))
    l=[]
    for i in range(n):
        N=int(input('enter percentage of student: '))
        l.append(N)
    print("unsorted array is :",l)
    gap=n//2
    while gap>0:
        j=gap
        while j<n:
            i=j-gap
            while i>=0:
                if l[i+gap]>l[i]:

                    break
                else:
                    l[i+gap],l[i]=l[i],l[i+gap]

                i=i-gap  
            j+=1
        gap=gap//2
    print("Sorted list using Shell sort is:\n",l)
    print("Top five scores are : ",l[-1:-6:-1]) 
	
switch(choice)
