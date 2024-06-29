import mysql.connector as d
import cleared

def feefn():

    db=d.connect(host='localhost',user='root',password='anypassword')

    newcursor=db.cursor()
    newcursor.execute("Create Database if not exists testdatabase")
    newcursor.execute(" use testdatabase ")
    newcursor.execute(" create Table if not exists FEE_TABLE(admno char(225),Name char(225),Classs char(225),Rollno char(225),fee char(225))")
    db.commit()

    print(" 1 : Check Fee Status With Admission  No.")
    print(" 2 : Fees Details  ")
    print(" 3 : Add Fee To Student ")
    print(" 4 : Delete Fee Status ")
    print(" 5 : Return Fee By Admission No. ")
    print(" 6 : Back ")

    choice=int(input(" Enter Your Choice : "))
    
    if(choice==1):
        #db=d.connect(host='localhost',user='root',password='anypassword')
        #newcursor.execute(" use testdatabase ")
        adm_test=input("enter admission no. of student whose fee you want to check ")
        query=("select fee from FEE_TABLE where admno=(%s)")
        tupple=(adm_test,)
        newcursor.execute(query,tupple)
        for j in newcursor:
            fee=j
            print(fee)
            
            if fee == 0:
                print("Fee hasnt been paid  ")
                #for i in newcursor:
                    #admno,Name,Classs,Rollno,fee=i
                    #print(admno,Name,Classs,Rollno,fee)
                

            else:
                print("Fee hasn't been paid ")
                #for i in newcursor:
                    #admno,Name,Classs,Rollno,fee=i
                    #print(admno,Name,Classs,Rollno,fee)

        feefn()                
            
    elif(choice==2):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" use testdatabase ")
        newcursor.execute(" create table if not exists Fee_data(id char(225),classs char(225), amount char(225)) ")

        print(" 1 : Check Fee Record Of All students ")
        print(" 2 : Check Fee Details For All Classes ")
        print(" 3 : Check Fee Details For All classes Anually ")
        print(" 4 : Back ")

        value=int(input("Enter Your Choice : "))
        if(value==1):
            query="select *from FEE_TABLE"
            newcursor.execute(query)
            for i in newcursor:
                admno,Name,Class,Rollno,fee=i
                print(admno,Name,Class,Rollno,fee)
            feefn()
                
        elif(value==2):
            db=d.connect(host='localhost',user='root',password='anypassword')
            newcursor=db.cursor()
            newcursor.execute(" use testdatabase ")
            newcursor.execute(" create table if not exists Fee_data(id char(225),classs char(225), amount char(225)) ")
            query=("select classs,amount  from Fee_data ")
            newcursor.execute(query)
            print("These are All the Amounts For All Classes")
            for i in newcursor:
                classs,amount=i
                print(classs,amount)
            feefn()

        elif(value==3):
            query=("select classs,amount *12 from Fee_data ")
            newcursor.execute(query)
            for i in newcursor:
                classs,amount=i
                print(classs,amount)
            feefn()

        else:
            feefn()

    elif(choice==3):
        print(" 1 : Add Fee To A New Student  ")
        print(" 2 : Add Fee To Exisiting Student ")
        ch=int(input("Enter Your Choice : "))
        if(ch==1):
            db=d.connect(host='localhost',user='root',password='anypassword')
            newcursor=db.cursor()
            newcursor.execute(" use testdatabase ")
            admno=input("Enter admission No. Of Student : ")
            name=input("Enter Name Of Student : ")
            classs=input("Enter Class Of Student : ")
            rollno=input("Enter Roll_no Of Student : ")
            fee=input("Enter Fee Of Student : ")
            query=("insert into  FEE_TABLE VALUES(%s,%s,%s,%s,%s)")
            var=(admno,name,classs,rollno,fee)
            newcursor.execute(query,var)
            db.commit()
            db.close()
            print(" Succesfully Added Fee ")
            feefn()

        elif(ch==2):
            new_adm=input("Enter Admission No. Of Student : ")
            fee=input("ENTER FEE : ")
            db=d.connect(host='localhost',user='root',password='anypassword')
            newcursor=db.cursor()
            newcursor.execute(" use testdatabase ")
            query=("update FEE_TABLE set fee=(%s) where admno=(%s)")
            tupple=(fee,new_adm)
            print(" Succesfully Added Fee ")
            newcursor.execute(query,tupple)
            db.commit()
            db.close()
            feefn()

    elif(choice==4):
         db=d.connect(host='localhost',user='root',password='anypassword')
         newcursor=db.cursor()
         newcursor.execute(" use testdatabase ")
         check_adm=input(" Enter Admission No. Of Student Whose Fee Details You Want To Delete : ")
         query1=("update FEE_TABLE set fee=0 where admno=(%s)")
         #query=("delete fee from FEE_TABLE where admno=(%s)")
         tuple3=(check_adm,)
         newcursor.execute(query1,tuple3)
         db.commit()
         db.close()
         print(" Changes Made Successfully ")
         feefn()

    elif(choice==5):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" use testdatabase ")
        adm_ck=input("Enter Admission No. Of Student Whose Fees You Want To Check : ")
        query=("select fee from Fee_Table where admno=(%s)")
        tup=(adm_ck,)
        newcursor.execute(query,tup)
        for i in newcursor:
            fee=i
            print(fee)
        feefn()

    elif(choice==6):
        import main
        main.home()

    else:
        feefn()

    
        
        
        
        
        
               
