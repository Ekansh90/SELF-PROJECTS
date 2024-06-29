import admission
import mysql.connector as a 
import cleared
import sports
import fee



def home():
    print(" ")
    print("WELCOME TO SCHOOL MANAGEMENT SYSTEM ")
    print(" ")
    print(" 1 : ADMISSION DETAILS ")
    print(" 2 : SPORTS DETAILS  ")
    print(" 3 : FEE DETAILS ")
    print(" ")
    option=int(input("Please Select One Of The Above Options:"))
    if(option==1):
        cleared.clear()
        admission.admissionfn()

    elif(option==2):
        cleared.clear()
        sports.sportfn()

    elif(option==3):
        cleared.clear()
        fee.feefn()

    else:
        cleared.clear()
        home()

home()

