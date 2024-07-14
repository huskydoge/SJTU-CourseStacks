DROP TABLE IF EXISTS Course, Student, SC; -- 如果表已存在，则重新创建

CREATE TABLE Course 
  (Cno CHAR(4)  PRIMARY KEY,
  Cname CHAR(40) NOT NULL,
  Cpno CHAR(4),
  Credit SMALLINT,
  Teacher CHAR(20) NOT NULL,
  FOREIGN KEY (Cpno) REFERENCES Course(Cno)
);

CREATE TABLE Student 
  (Sno CHAR(9)  PRIMARY KEY,
  Sname CHAR(20) NOT NULL,
  Ssex CHAR(2),
  Sage SMALLINT,
  Sdept CHAR(20)
);

CREATE TABLE SC 
  (Sno CHAR(9),
   Cno CHAR(4),
   Grade SMALLINT CHECK (Grade >= 0 and Grade <= 100),
   PRIMARY KEY (Sno, Cno),
   FOREIGN KEY (Sno) REFERENCES Student(Sno),
   FOREIGN KEY (Cno) REFERENCES Course(Cno)
);

-- 插入课程数据
INSERT INTO Course (Cno, Cname, Cpno, Credit, Teacher) VALUES
('C101', '计算机科学导论', NULL, 4, '张老师'),
('C102', '数据结构', 'C101', 4, '李老师'),
('C103', '数据库原理', NULL, 3, '刘老师'),
('C104', '操作系统', NULL, 3, '王老师'),
('C105', '计算机网络', 'C104', 3, '刘老师')
;

-- -- 插入学生数据
INSERT INTO Student (Sno, Sname, Ssex, Sage, Sdept) VALUES
('S001', '王小明', '男', 20, '计算机科学与技术'),
('S002', '李华', '女', 19, '软件工程'),
('S003', '张伟', '男', 22, '信息安全'),
('S004', '刘洋', '男', 21, '数据科学与大数据技术'),
('S005', '赵敏', '女', 20, '人工智能'),
('S006', '黄峰', '男', 20, '应用数学'),
('S007', '陈柳', '女', 19, '计算机科学与技术'),
('S008', '韩梅', '女', 20, '软件工程'),
('S009', '周杰', '男', 21, '信息安全'),
('S010', '吴亦凡', '男', 22, '数据科学与大数据技术');

-- -- 插入选课数据
INSERT INTO SC (Sno, Cno, Grade) VALUES
('S001', 'C101', 85),
('S001', 'C102', 90),
('S002', 'C103', 75),
('S002', 'C102', 88),  
('S004', 'C102', 93),  
('S006', 'C102', 77),
('S003', 'C101', 88),
('S003', 'C102', 79),
('S003', 'C103', 84),
('S004', 'C104', 91),
('S004', 'C105', 87),
('S005', 'C101', 82),
('S005', 'C105', 80),
('S005', 'C103', 90),
('S007', 'C102', 92),
('S008', 'C102', 85),
('S009', 'C102', 89),
('S010', 'C102', 76);



DROP PROCEDURE IF EXISTS calculateStuNumOfCourse;

-- 创建存储过程
CREATE PROCEDURE calculateStuNumOfCourse(
    IN CourseName CHAR(40),
    OUT ZERO_SIXTY INT,
    OUT SIXTY_SEVENTY INT,
    OUT SEVENTY_EIGHTY INT,
    OUT EIGHTY_NINETY INT,
    OUT NINETY_HUNDRED INT
)
BEGIN
    DECLARE course_id CHAR(4);

    SELECT Cno INTO course_id FROM Course WHERE Cname = CourseName;

    SELECT COUNT(*) INTO ZERO_SIXTY FROM SC 
    WHERE Cno = course_id AND Grade >= 0 AND Grade <= 60;

    SELECT COUNT(*) INTO SIXTY_SEVENTY FROM SC 
    WHERE Cno = course_id AND Grade > 60 AND Grade <= 70;

    SELECT COUNT(*) INTO SEVENTY_EIGHTY FROM SC 
    WHERE Cno = course_id AND Grade > 70 AND Grade <= 80;

    SELECT COUNT(*) INTO EIGHTY_NINETY FROM SC 
    WHERE Cno = course_id AND Grade > 80 AND Grade <= 90;

    SELECT COUNT(*) INTO NINETY_HUNDRED FROM SC 
    WHERE Cno = course_id AND Grade > 90 AND Grade <= 100;
END;

-- 调用存储过程
CALL calculateStuNumOfCourse('数据结构', @ZERO_SIXTY, @SIXTY_SEVENTY, @SEVENTY_EIGHTY, @EIGHTY_NINETY, @NINETY_HUNDRED);

-- 打印结果
SELECT 
    @ZERO_SIXTY '成绩0~60人数',
    @SIXTY_SEVENTY AS '成绩60~70人数',
    @SEVENTY_EIGHTY AS '成绩70~80人数',
    @EIGHTY_NINETY AS '成绩80~90人数',
    @NINETY_HUNDRED AS '成绩90~100人数';
		
		
