```sql
SELECT * FROM collage.mydata;

select name, grade
from mydata
where marks > 85;

create table dept(
id int primary key,
name varchar(50)
);

create table teacher(
id int primary key,
teacher varchar(50),
dept_id int ,

foreign key (dept_id)
references dept(id)

on update cascade
on delete cascade
);
 
 
INSERT INTO dept (id, name) VALUES
(101, 'Mathematics'),
(102, 'Physics'),
(103, 'Chemistry'),
(104, 'Biology'),
(105, 'Computer Science'),
(106, 'History'),
(107, 'Geography'),
(108, 'English'),
(109, 'Economics'),
(110, 'Political Science');

INSERT INTO teacher (id, teacher, dept_id) VALUES
(101, 'Alice Johnson', 101),
(102, 'Bob Smith', 102),
(103, 'Charlie Brown', 103),
(104, 'Diana White', 104),
(105, 'Eve Black', 105),
(106, 'Frank Green', 106),
(107, 'Grace Blue', 107),
(108, 'Hank Silver', 108),
(109, 'Ivy Gold', 109),
(110, 'Jack Orange', 110);

TRUNCATE TABLE teacher;
TRUNCATE TABLE dept;

drop table dept;
drop table teacher; 

update dept
set id=112
where id=102;


```

```sql
SELECT * FROM collage.mydata;

alter table mydata
add column grade varchar(5);

update mydata
set grade= "A+"
where marks >= 90;

UPDATE mydata
SET grade = 'A'
WHERE marks >= 80 and marks <90;

UPDATE mydata
SET grade = 'BAD'
WHERE marks >= 70 and marks <80;

UPDATE mydata
SET grade = 'SAD'
WHERE marks >= 60 and marks <70;

UPDATE mydata
SET grade = 'LOL'
WHERE marks < 60 ;

set sql_safe_updates=0;

SELECT * FROM collage.mydata;

INSERT INTO mydata (id, name, marks, city) VALUES
(1, 'John Doe', 85, 'New York'),
(2, 'Jane Smith', 92, 'Los Angeles'),
(3, 'Robert Brown', 78, 'Chicago'),
(4, 'Emily Davis', 88, 'Houston'),
(5, 'Michael Johnson', 95, 'Phoenix'),
(6, 'Sarah Wilson', 67, 'Philadelphia'),
(7, 'William Taylor', 74, 'San Antonio'),
(8, 'Jessica Moore', 81, 'San Diego'),
(9, 'Daniel Anderson', 90, 'Dallas'),
(10, 'Sophia Lee', 59, 'San Jose');

insert into mydata (id, name, marks,city)
values 
(11, 'Alice Green', 72, 'New York'),
(12, 'Chris White', 89, 'New York'),
(13, 'David Black', 91, 'New York'),
(14, 'Mia Clark', 84, 'New York'),
(15, 'Ella Hall', 77, 'New York'),
(16, 'James Allen', 69, 'New York'),
(17, 'Emma Young', 86, 'New York'),
(18, 'Liam Wright', 73, 'New York'),
(19, 'Olivia Hill', 82, 'New York');


select city , max(marks), min(marks) 
from mydata
group by city;

select city , max(marks), min(marks),avg(marks)
from mydata
group by city
HAVING max(marks) > 90;
 

```

```sql
//table ralted Queries

alter  table student
add column age int not null default 18;

alter table student
drop column dept_id;

alter table student
drop column dept_id;

alter table student
CHANGE COLUMN dept_id subject_id int;




```