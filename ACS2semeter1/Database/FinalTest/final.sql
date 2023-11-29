-- 1 
select title,rating , length from film where length > (select avg(length) from film );


-- 2
-- ทำไม่ได้
select title,rating , length from film where length > (select avg(length) from film where rating = (select rating from film where rating = 'G'));



-- 10 
select first_name,last_name,job_title,salary from employees as em join jobs as j using(job_id)  order by salary desc ;

select job_title,max(salary) from employees as em  left join jobs as j on em.job_id = j.job_id group by em.job_id;


