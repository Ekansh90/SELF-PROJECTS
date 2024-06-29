import mysql.connector as d
import cleared

def sportfn():

    db=d.connect(host='localhost',user='root',password='anypassword')

    newcursor=db.cursor()
    newcursor.execute("Create Database if not exists testdatabase")
    newcursor.execute(" use testdatabase ")
    newcursor.execute(" create Table if not exists SPORTS(admno char(225),Name char(225),Classs char(225),Rollno char(225),Sport_Name char(225))")
    db.commit()             


    print(" 1 : Sports In School ")
    print(" 2 : Add / Edit Student's Sport ")
    print(" 3 : Return Student Details By Sport ")
    print(" 4 : Return Sport By Admission No. ")
    print(" 5 : All Student's Details With Sports ")
    print(" 6 : Back ")

    inp=int(input(" Enter Your Choice : "))
    if(inp==1):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" Use testdatabase ")
        newcursor.execute("create table if not exists ALL_SPORTS(SRNO char(225), Sport char(225))")
        
        rowCount = newcursor.execute("SELECT COUNT(*) FROM ALL_SPORTS ;")
        if rowCount == 0 :
            # query to populate table if sports table is empty 
            newcursor.execute(""" insert  into all_sports(SRNO, Sport) 
                              values (1, 'Football'),
                              (2, 'Basketball'),
                              (3, 'Tennis'),
                              (4, 'Baseball'),
                              (5, 'Badminton'); """)
        else :
            query=("select * from ALL_SPORTS " )
            newcursor.execute(query)
            for i in newcursor:
                SRNO,Sport=i
                print(SRNO,Sport)
            sportfn()

    elif(inp==2):
        print(" 1 : Add New Student's Entry With Sport ")
        print(" 2 : Change Student's Entry With Sport ")
        usage=int(input(" Enter Your Choice : "))
        if(usage==1):
              db=d.connect(host='localhost',user='root',password='anypassword')
              newcursor=db.cursor()
              newcursor.execute(" use testdatabase ")
              admno=(input("Enter Admission No. : "))
              name=(input("Enter Name : "))
              classs=(input("Enter Class : "))
              rollno=(input("Enter Roll Number : "))
              sport=(input("Enter Sport Taken By Student : "))
              query=("insert into SPORTS values(%s,%s,%s,%s,%s)")
              tupple1=(admno,name,classs,rollno,sport)
              newcursor.execute(query,tupple1)
              db.commit()
              db.close()
              print("Succesfully inserted new values")
              #cleared.clear()
              sportfn()
       

        elif(usage==2):
            print(" 1 : Delete Student Record with Sports ")
            print(" 2 : Edit Existing Student's Sports Record ")
            print(" 3 : Back ")
            minecput=int(input(" Enter Your Choice : " ))
            if(minecput==1) : 
                db=d.connect(host='localhost',user='root',password='anypassword')
                newcursor=db.cursor()
                newcursor.execute("use testdatabase ")
                del_sport=input(" Enter Sport_Name of Student whose Details You Want To Delete : ")
                query1=("delete from SPORTS where Sport_Name=(%s)")
                tupple1=(del_sport,)
                newcursor.execute(query1,tupple1)
                db.commit()
                db.cursor()
                db.close()
                print("Successfully Deleted Given Values")
                sportfn()

            elif(minecput==2) :
                db=d.connect(host='localhost',user='root',password='anypassword')
                newcursor=db.cursor()
                newcursor.execute(" use testdatabase ")
                new_adm=int(input(" Enter Admission No. Of Student Whose Sport You Want To Alter : "))
                new_sportname=input(" Enter  New Sport_Name ")
                query1=(" update SPORTS set Sport_Name=(%s) where admno=(%s)")
                tupple1=(new_sportname,new_adm)
                newcursor.execute(query1,tupple1)
                db.commit()
                db.close()
                print("Successfully Updated Sports ")
                #cleared.clear()
                sportfn()
            else:
                sportfn()

    elif(inp==3):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" use testdatabase ")
        ent_sport=input(" Enter Sport_Name of Student Whose Details You Want To See : ")
        query1=("select * from SPORTS where Sport_Name=(%s)")
        tupple2=(ent_sport,)
        newcursor.execute(query1,tupple2)
        for i in newcursor:
            admno,Name,Classs,Rollno,Sport_Name=i
            print(admno,Name,Classs,Rollno,Sport_Name)
        # cleared.clear()
        sportfn()
       

    elif(inp==4):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" use testdatabase ")
        ent_adm=input(" Enter Admission No. Of Student Whose Sport_Name You Want To Check : ")
        query=("select Sport_Name from SPORTS where admno=(%s)")
        var=(ent_adm,)
        newcursor.execute(query,var)
        for i in newcursor:
            Sport_Name=i
            print(Sport_Name)
        # cleared.clear()
        sportfn()

    elif(inp==5):
        db=d.connect(host='localhost',user='root',password='anypassword')
        newcursor=db.cursor()
        newcursor.execute(" use testdatabase ")
        queri=("select *from SPORTS ")
        newcursor.execute(queri)
        for i in newcursor:
            admno,Name,Classs,Rollno,Sport_Name=i
            print(admno,Name,Classs,Rollno,Sport_Name)
        # cleared.clear()
        sportfn()

    elif(inp==6):
        import main
        main.home()

    else:
        sportfn()
        
        
                             

                        
                            
                             
                             

                             


                             
                         

                         

                         

              
            
        
        
        
