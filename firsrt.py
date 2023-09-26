CSE = ["alex","blair","cassey","drew","erin","francis","glen","hunter","ira","jade"]
Cricket = ["alex","cassey","drew","hunter"]
Badminton = ["cassey","drew","jade"]
Football = ["drew","glen","jade"]
#Students who play both cricket and badminton
print("cricket and badminton:")
CandB = []
for i in range(0,len(Cricket)):
    for j in range(0,len(Badminton)):
        if(Cricket[i]==Badminton[j]):
            CandB.append(Cricket[i])
CandB = set(CandB)
            
print(CandB)

#Students Who play either cricket or badminton but not both
print("cricket or badminton")
CorB = []
for i in range(0,len(Cricket)):
    for j in range(0,len(Badminton)):
        if(Cricket[i]!=Badminton[j]):
            CorB.append(Cricket[i])
            CorB.append(Badminton[j])
CorB = set(CorB)
print(set(CorB))

#Cricket and Football but not Badminton
print("Cricket and Football but not Badminton")
CandFnB =[]
for i in range(0,len(Cricket)):
    for j in range(0,len(Football)):
        if(Cricket[i]==Football[j]):
            CandFnB.append(Cricket[i])
for i in range(0,len(Badminton)):
    for j in range(0,len(CandFnB)):
        if(Badminton[i]==CandFnB[j]):
            CandFnB.remove(Badminton[i])
print(CandFnB)

#students play neither cricket nor badminton
print("Student plays neither cricket nor badminton")
CnB = []
for student in CSE:
    if student not in CorB:
        CnB.append(student)
print(set(CnB))



