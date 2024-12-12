'''Write a python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
Quick Sort and display top five scores.
'''
def quick_sort(l,h):
	if(l<h):
		pivot=partition(l,h)
		quick_sort(l,pivot-1)
		quick_sort(pivot+1,h)
	
		
def partition(l,h):
	pivot=a[l]
	i=l
	j=h
	while (i<j):
		while (i<=h and a[i]<=pivot):
			i+=1
		while (j>=l and a[j]>pivot):
			j-=1
		if (i<j):
			a[i],a[j]=a[j],a[i]
	a[l],a[j]=a[j],a[l]
	return j
	

print("Quick Sorting.....")
n=int(input("enter the no. of student:"))
a=[]
for i in range(n):
	N=int(input("enter the percentage of students:"))
	a.append(N)
print("unsorted array is :",a)

quick_sort(0,n-1)
print("sorted array is :",a)
print("top five highest scores are :",a[-1:-6:-1])
