'''Write a python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort b) Bubble sort and display top five scores.
'''
print("enter 1 for Bubble Sort:")
print("enter 2 for selection Sort:")
print("enter 3 for exit:")
choice=int(input("enter your choice:"))
def switch (choice):
	if choice==1:
		bubble_sort()
	
	if choice==2:
		selection_sort()
		
	if choice==3:
		print("you are successfully exited")

def bubble_sort():
	percent=[]
	n=int(input("Enter how many students:-"))

	for i in range(n):
		m=float(input("percentage of Student:-"))
		percent.append(m)
	
	print("original list:",percent)

	for i in range(n-1):
		for j in range(n-1):
			if percent[j]>percent[j+1]:
				percent[j],percent[j+1]=percent[j+1],percent[j]
			
	print ("sorted list:",percent)	
	print ("Bubble sorting ^ ")
	print("top 5 highest scores are:",percent[-1:-6:-1])


def selection_sort():
	per=[]
	a=int (input ("Enter No. of student in another list :"))

	for x in range (a):
		b=float(input("enter Percentage of student:"))
		per.append(b)
	
	print("Unsorted list:",per)
	
	for ind in range(a):
		min_index = ind
		for j in range(ind + 1, a):
			if per[j] < per[min_index]:
				min_index = j
		(per[ind], per[min_index]) = (per[min_index], per[ind])
	print("sorted list:",per)
	print ("selection sorting ^")
	
	print("top 5 highest scores are:",per[-1:-6:-1])
		
switch(choice)
