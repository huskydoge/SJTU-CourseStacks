# 第四章 结构化查询语言SQL 作业



## Create Table

```SQL
CREATE TABLE Course 
  (Cno CHAR(4)  PRIMARY KEY,
  Cname CHAR(40) NOT NULL,
  Cpno CHAR(4),
  Credit SMALLINT,
  Teacher CHAR(20) NOT NULL,
  FOREIGN KEY (Cpno) REFERENCES Course(Cno)
);
```

```sql
CREATE TABLE Student 
  (Sno CHAR(9)  PRIMARY KEY,
  Sname CHAR(20) NOT NULL,
  Ssex CHAR(2),
  Sage SMALLINT,
  Sdept CHAR(20)
);
```

```sql
CREATE TABLE SC 
  (Sno CHAR(9),
   Cno CHAR(4),
   Grade SMALLINT CHECK (Grade >= 0 and Grade <= 100),
   PRIMARY KEY (Sno, Cno),
   FOREIGN KEY (Sno) REFERENCES Student(Sno),
   FOREIGN KEY (Cno) REFERENCES Course(Cno)
);
```

数据如下：

```sql
-- 插入课程数据
INSERT INTO Course (Cno, Cname, Cpno, Credit, Teacher) VALUES
('C101', '计算机科学导论', NULL, 4, '张老师'),
('C102', '数据结构', 'C101', 4, '李老师'),
('C103', '数据库原理', NULL, 3, '刘老师'),
('C104', '操作系统', NULL, 3, '王老师'),
('C105', '计算机网络', 'C104', 3, '刘老师');

-- 插入学生数据
INSERT INTO Student (Sno, Sname, Ssex, Sage, Sdept) VALUES
('S001', '王小明', '男', 20, '计算机科学与技术'),
('S002', '李华', '女', 19, '软件工程'),
('S003', '张伟', '男', 22, '信息安全'),
('S004', '刘洋', '男', 21, '数据科学与大数据技术'),
('S005', '赵敏', '女', 20, '人工智能')
('S006', '黄峰', '男', 20, '应用数学')
;

-- 插入选课数据
INSERT INTO SC (Sno, Cno, Grade) VALUES
('S001', 'C101', 85),
('S001', 'C102', 90),
('S002', 'C103', 75),
('S003', 'C101', 88),
('S003', 'C102', 79),
('S003', 'C103', 84),
('S004', 'C104', 91),
('S004', 'C105', 87),
('S005', 'C101', 82),
('S005', 'C105', 80)
('S005', 'C103', 90);

```

1. **找出平均成绩最高的学生的学号**

   ```sql
   SELECT Sno 
   FROM SC 
   GROUP BY Sno 
   ORDER BY AVG(GRADE) DESC 
   LIMIT 1;
   ```

   ![Screenshot 2024-03-22 at 20.05.20](https://p.ipic.vip/q9yvlq.png)

2. **将没有选课的学生从学生表中删除**

   ```sql
   DELETE 
   FROM Student
   WHERE Sno NOT IN 
   	(SELECT DISTINCT Sno 
   	 FROM SC);
   ```

   ![Screenshot 2024-03-22 at 20.13.15](https://p.ipic.vip/8rm8ot.png)

![Screenshot 2024-03-22 at 20.13.38](../Library/Application%20Support/typora-user-images/Screenshot%202024-03-22%20at%2020.14.42.png)

​		S006号同学因为没有选课，所以在学生表中被删除了。

3. **查询出选修至少两门课程的学生学号**

   ```sql
   SELECT Sno
   FROM SC
   GROUP BY Sno
   HAVING COUNT(CNO) >= 2;
   ```

   ![Screenshot 2024-03-22 at 20.18.13](https://p.ipic.vip/9601pj.png)

4. **查询选择了刘老师所有课程的学生学号**

   ```sql
   SELECT Sno
   FROM Student
   WHERE NOT EXISTS(
   	SELECT * 
   	FROM Course
   	WHERE Teacher = "刘老师" AND NOT EXISTS(
   			SELECT * 
   			FROM SC
   			WHERE Course.Cno = Cno AND Student.Sno = Sno)
       );
   ```

   ![Screenshot 2024-03-22 at 20.28.01](https://p.ipic.vip/b5imsn.png)

5. **按平均成绩的降序给出所有课程都及格的学生及其平均成绩**

   方便起见，我们规定合格成绩为80分。

   ```sql
   SELECT Sno, AVG(Grade)
   FROM SC
   GROUP BY Sno
   HAVING MIN(Grade) >= 80
   ORDER BY AVG(Grade) DESC;
   ```

   ![Screenshot 2024-03-22 at 20.43.14](https://p.ipic.vip/2g93n4.png)

6. **定义一个平均成绩大于85分的学生成绩视图（学号和平均成绩）**

   ```sql
   CREATE VIEW AVG_GRADE_GT_85
   	AS
   	SELECT Sno, AVG(Grade)
   	FROM SC
   	GROUP BY Sno
   	HAVING AVG(Grade) > 85;
   ```

   ![Screenshot 2024-03-22 at 20.46.24](https://p.ipic.vip/llfz9i.png)

7. **表S中男同学的每一年龄组（超过50人）有多少人？要求查询结果按人数升序排列，人数相同按年龄降序排列。**

   ```sql
   SELECT Sage, COUNT(Sno)
   FROM Student
   GROUP BY Sage
   ORDER BY COUNT(Sno) ASC, Sage DESC
   ;
   ```

   ![Screenshot 2024-03-22 at 20.54.49](https://p.ipic.vip/nh12zf.png)
