# Homework 2

**Student（Sno,** **Sname,** **Ssex, Sage,** **Sdept)**

**学生（学号，姓名，性别，年龄，所在系）**

**Course (Cno,** **Cname,** **Cpno,** **Ccredit** **)**

**课程（课程号，课程名，先行课，学分）**

**SC（Sno,** **Cno, Grade）**

**选修（学号，课程号，成绩）**

用关系代数语言查询：

1. **求年龄在22岁以下的女学生；**
2. **求成绩在90分以上的学生的学号和姓名；**
3. **求选修数据库课程的学生的姓名和成绩；**
4. **查询没选005号课程的学生姓名与年龄；Important, cannot just use logic operator! Cno 1= 005**
5. **查询选修了全部课程的学生号码和姓名；**

-----

1. $\sigma_{Ssex='female' \, \and \, Sage < 22}(Student)$

2. $ \pi_{Sno}(\sigma_{Grade > 90} (SC) ) ⋈ \pi_{Sno,Sname}(Student)$
3. $\pi_{Sname,Grade}(\pi_{Sno,Grade}(\pi_{Cno}(\sigma_{Cname=数据库}(Course)) ⋈ SC) ⋈ \pi_{Sno, Sname}(Student))$

4. $\pi_{Sname,Sage}((\pi_{Sno}(Student)-\pi_{Sno}(\sigma_{Cno=005}(SC))) ⋈ \pi_{Sno,Sname,Sage}(Student))$

5. $\pi_{Sno,Sname}(Student)⋈(\pi_{Sno, Cno}(SC) ÷ \pi_{Cno}(Course))$

