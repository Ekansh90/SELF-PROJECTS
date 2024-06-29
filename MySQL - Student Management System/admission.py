import mysql.connector as d
import cleared

def admissionfn():
    db=d.connect(host="localhost",user="root",password="anypassword")
    newcursor=db.cursor()
    newcursor.execute("Create database if not exists testdatabase")
    newcursor.execute("use testdatabase")
    newcursor.execute("create TABLE if not exists student_master(adm_no int not null auto_increment ,first_name char(35) not null,last_name char(35),age bigint not null,grade bigint ,roll_no bigint , PRIMARY KEY(adm_no))") 
    db.commit()
    print("1 : New Admission")
    print("2 : View Student Details")
    print("3 : Edit Student Details")
    print("4 : Delete Student ")
    print("5 : Back ")
    
    value=int(input("Enter Your Choice : "))

#new admission
    if(value==1):
        #adm_no=int(input("Enter Admission No. : "))
        first_name=(input("Enter First Name : "))
        last_name=(input("Enter Last Name : "))
        age=(input("Enter Age : "))
        grade=int(input("Enter Class : "))
        roll_no=int(input("Enter Roll Number : "))
        query_final="""insert into student_master(first_name,last_name,age,grade,roll_no)  values(%s,%s,%s,%s,%s)"""
        var=(first_name,last_name,age,grade,roll_no)
        newcursor.execute(query_final,var)
        db.commit()
        db.close()
        print("Student Details Saved Succesfully")
        admissionfn()

#View Student details                
    elif(value==2):
        print(" 1 : All Student Details")
        print(" 2 : Student Details By Admission No. ")
        print(" 3 : Back ")

        user=int(input("Enter Your Choice"))
        if(user==1):
            db=d.connect(host="localhost",user="root",password="anypassword")
            newcursor=db.cursor()
            newcursor.execute("use testdatabase")
            query_select=("Select * from student_master")
            newcursor.execute(query_select)
            for i in newcursor:
                adm_no,first_name,last_name,age,grade,roll_no=i
                print(adm_no,first_name,last_name,age,grade,roll_no)
            admissionfn()

        elif(user==2): 
            db=d.connect(host="localhost",user="root",password="anypassword")
            newcursor=db.cursor()
            newcursor.execute("use testdatabase")
            enteradm=int(input("Enter Admission No. :"))
            vaar=(enteradm,)
            query_select_adm="select * from student_master where adm_no=(%s)"
            newcursor.execute(query_select_adm,vaar)
            rowal=newcursor.fetchall()
            for i in rowal:
                adm_no,first_name,last_name,age,grade,roll_no=i
                print(adm_no,first_name,last_name,age,grade,roll_no)
            admissionfn()

        else:
            admissionfn()

#change student details
    elif(value==3):
        db=d.connect(host="localhost",user="root",password="anypassword")
        newcursor=db.cursor()
        newcursor.execute("use testdatabase")
        check_adm=int(input("Change Student Detail -> Enter Admission No. : "))
        nam1=input("Enter New First Name :")
        nam2=input("Enter New Last Name :")
        age1=int(input("Enter New Age :"))
        grade1=int(input("Enter New Class:"))
        roll_no1=int(input("Enter New roll_no:"))
        query=('update student_master set first_name=(%s),last_name=(%s),age=(%s),grade=(%s),roll_no=(%s) where adm_no=(%s)')
        tupple=(nam1,nam2,age1,grade1,roll_no1,check_adm)
        newcursor.execute(query,tupple)
        db.commit()
        db.close()
        print(" Student Details Changed Successfully")
        admissionfn()

#delete student details
    elif(value==4):
        db=d.connect(host="localhost",user="root",password="anypassword")
        newcursor=db.cursor()
        newcursor.execute("use testdatabase")
        adm_no_del=int(input("Delete Student Details ->Enter Admission No:"))
        query_delete= ("delete from student_master where adm_no=(%s)")
        tupple_delete=(adm_no_del,)
        newcursor.execute(query_delete,tupple_delete)
        db.commit()
        db.close()
        print("Succesfully Deleted Record Of Student")
        admissionfn()
        
    elif(value==5):
        import main
        main.home()
        
        #lagclear.clear()
        #admissionfn()
        

    else:
        admissionfn()
        #return lagmain.home()

    
                
#commit add ya delete mein krte hai bas




    
               

        
