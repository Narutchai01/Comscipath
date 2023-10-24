use university;
use sakila;

-- 1
select title from course where dept_name = "Comp. Sci." and credits = 3;

-- 2
select t.ID from takes t join teaches te using (course_id) where te.ID = 22222;

-- 3
select max(salary) "Highest Salary" from instructor;

-- 4
select name from instructor where salary = (select max(salary) from instructor);

-- 5
select sec_id , count(sec_id) enroll from takes 
where semester = "Autumn" and year = "2017" group by sec_id;

-- 6
select sum(sec) "All Enroll" from (select count(sec_id) sec from takes 
where semester = "Autumn" and year = "2017" group by sec_id)as enroll;

-- 7
select count(sec_id) enroll from takes where semester = "Autumn" 
and year = 2017 group by sec_id order by enroll desc limit 1 ;

-- 8
alter table course drop constraint course_chk_1;
alter table course add constraint course_chk_1 check (credits >= 0);

insert into course (course_id , title , dept_name , credits )
values ('CS-001' , 'Weekly Seminar' , 'Comp. Sci.' , 0);

-- 9
alter table section drop constraint section_chk_1;
alter table section add constraint section_chk_1 check 
(semester in ('Fall', 'Winter', 'Spring', 'Summer' , 'Autumn'));

insert into section (course_id , sec_id , semester , year)
values ('CS-001' , '1' , 'Autumn' , 2017 );

-- 10
insert into takes (ID , course_id , sec_id , semester , year ) values 
("00128" , "CS-001" , "1" , "Autumn" , 2017),
("12345" , "CS-001" , "1" , "Autumn" , 2017),
("54321" , "CS-001" , "1" , "Autumn" , 2017),
("76543" , "CS-001" , "1" , "Autumn" , 2017);

-- 11
delete from takes 
where ID = '23121' and course_id = 'CS-001';

-- 12
delete from course where course_id = 'CS-001';

-- 13
delete from takes
where course_id in
(select s.course_id from section s join course c using (course_id) where title like '%database%');


 