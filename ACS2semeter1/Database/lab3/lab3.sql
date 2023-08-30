use university;


select * from student natural left join takes;
SELECT * FROM student NATURAL RIGHT JOIN takes;


select i.id , i.name , count(t.course_id) as number_sec from instructor i left join teaches t  on i.id = t.id group by i.id, i.name;


select s.course_id,i.name from teaches t left join instructor i on i.id = t.id left join section s on t.course_id = s.course_id and t.sec_id = s.sec_id where t.semester = "Spring" and t.year =2010;

select d.dept_name , count(i.id) as num_intructors from department d left join instructor i on d.dept_name = i.dept_name group by d.dept_name;