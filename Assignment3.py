'''Write a python program for magic square. A magic square is an n * n
Matrix of the integers 1 to n2 such that the sum of each row, column, and diagonal
is the same.
'''

mat_size=int(input("enter no. of matrix size:"))
matrix=[]

for i in range (mat_size):
    rows=[]
    for j in range (mat_size):
        ele=int(input("enter elements:"))
        rows.append(ele)
    matrix.append(rows)
print(matrix)

for i in range(mat_size):
	for j in range (mat_size):
		print(matrix[i][j],end=" ")
	print()

sum1=0
for i in range (mat_size):
	sum1=sum1+matrix[i][i]
print("sum of first diagonal is:",sum1)

sum2=0
for i in range (mat_size):
	sum2=sum2+matrix[i][mat_size-1-i]
print("sum of second diagonal is:",sum2)

if sum1==sum2:
	for i in range (mat_size):
		rows_sum=0
		for j in range (mat_size):
			rows_sum=rows_sum+matrix[i][j]
		print("sum of",i,"row is:",rows_sum)
	
	for i in range (mat_size):
		column_sum=0
		for j in range (mat_size):
			column_sum=column_sum+matrix[j][i]
		print("sum of",i,"column is:",column_sum)
	if rows_sum==column_sum:
		print("given matrix is a magic square matrix")
	else:
		print("given matrix is not a magic square matrix")

else:
	print("the sum of both diagonals are not same;")
	print("so the given matrix is not a magic square matrix")
