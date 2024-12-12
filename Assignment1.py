#SURAJ VITTHAL PATIL
#SC148
'''In second year computer engineering class, group A student’s play
Cricket, group B students play badminton and group C students play football. Write
a Python
Program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use
SET built-in functions)'''

cricket=[]
badminton=[]
football=[]
c=int(input("enter No. students playing cricket:"))
for i in range (0,c):
    cric=int(input("enter roll no. of students playing cricket:"))
    cricket.append(cric)
print("roll no. of students playing cricket is:",cricket)
print()

b=int(input("enter no. of students playing badminton:"))
for i in range (0,b):
    bad=int(input("enter roll no. of students playing badminton:"))
    badminton.append(bad)
print("roll no. of students playing badminton is:",badminton)
print()

f=int(input("enter no. of students playing football:"))
for i in range (0,f):
    fb=int(input("enter roll no. of students playing football:"))
    football.append(fb)
print("roll no. of students playing football is :",football)
print()

cric_bad=[]
for i in cricket:
    if i in badminton:
        cric_bad.append(i)
print("roll no. of students playing both cricket and badminton is:",cric_bad)
print("no. of students playing both cricket and badminton is:",len(cric_bad))
print()
cric_union_bad=cricket
for i in badminton:
    if i not in cricket:
        cric_union_bad.append(i)
    else:
        cric_union_bad.remove(i)
print("roll no. of students playing either cricket or badminton but not both:",cric_union_bad)
print("no. of students playing either cricket or badminton but not both",len(cric_union_bad))
print()
fb_only=[]
for i in football:
    if i not in cricket and i not in badminton:
        fb_only.append(i)
print("roll no. of students who play neither cricket nor badminton is",fb_only)
print("no. of students who play neither cricket nor badminton is:",len(fb_only))
print()
cric_and_fb=cricket
for i in football:
    if i not in cricket:
        cric_and_fb.append(i)

for i in badminton:
    if i in cric_and_fb:
        cric_and_fb.remove(i)
print("roll no. of students who play cricket and football but not badminton is:",cric_and_fb)
print("no. of students who play cricket and football but not badminton is:",len(cric_and_fb))