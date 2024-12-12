'''Write a Python program to store marks scored in subject “Fundamental of Data  Structure” by N 
students in the class. Write functions to compute following: 
a. The average score of class 
a. Highest score and lowest score of class 
b. Count of students who were absent for the test 
c. Display mark with highest frequency''' 

marks = []
n = int(input("Enter number of students: "))
print("Enter -1 for absent students.")
for i in range(n):
    m = int(input("Enter marks: "))
    marks.append(m)
print("Marks of students is:", marks)

absent = []
for i in marks:
    if i == -1:
        absent.append(i)
print("No. of absent students:", len(absent))

b = len(marks) - len(absent)
avg = []
for i in marks:
    if i >= 0:
        avg.append(i)
print("No. of students present:", len(avg))
print("Average result of class:", sum(avg) / b)

max_marks = avg[0]
for i in avg:
    if i > max_marks:
        max_marks = i
print("Maximum marks is:", max_marks)

lown = avg[0]
for i in avg:
    if i < lown:
        lown = i
print("Lowest marks is:", lown)

freq = 0
high_freq = 0
m = 0
for i in marks:
    freq = 0
    for j in marks:
        if j != -1:
            if i != -1:
                if i == j:
                    freq += 1
    if freq >= high_freq:
        high_freq = freq
        m = i
print("No. of highest frequency is:", high_freq)
print("Marks of highest frequency is:", m)
