select C.first_name,C.last_name from customer as C left join rental as R on C.customer_id = R.customer_id where rental_id is null;


select C.name , count(C.category_id) from category as C join film_category as FC on C.category_id = FC.category_id group by C.category_id;

select rating from film group by rating;
(select title,rating  from film where rating = "PG" order by length(title) desc limit 3)
union
(select title,rating  from film where rating = "G" order by length(title) desc limit 3)
union
(select title,rating  from film where rating = "NC-17" order by length(title) desc limit 3)
union
(select title,rating  from film where rating = "PG-13" order by length(title) desc limit 3)
union
(select title,rating  from film where rating = "R" order by length(title) desc limit 3);


select max(length) - min(length) from film;

select concat(title," is the answer") from film order by length(title) desc limit 1;

(select max(date_format(rental_date, "%W %D %M %Y" )) as Firstday , min(date_format(rental_date, "%W %D %M %Y" )) as Lastday ,datediff(max(rental_date),min(rental_date)) as distance , staff_id as Store from rental where staff_id = 1)
union 
(select max(date_format(rental_date, "%W %D %M %Y" )) as Firstday , min(date_format(rental_date, "%W %D %M %Y" )) as Lastday ,datediff(max(rental_date),min(rental_date)) as distance , staff_id as Store from rental where staff_id = 2);

select * from film where title like "m%er";

select C.first_name, count(R.customer_id) from customer as C left join rental as R on C.customer_id = R.customer_id  group by C.customer_id order by count(R.customer_id) desc limit 10;

select store_id, count(rental_id) from rental join staff using (staff_id) group by store_id limit 1;

select title,count(I.film_id) from inventory as I Right join film as F on I.film_id = F.film_id group by title limit 1;

select C.first_name, datediff(return_date,rental_date) as Total from customer as C join rental as R on C.customer_id = R.customer_id order by Total desc limit 1;

select f.title as Title, r.rental_date as Rent , r.return_date as "Return" , concat(c.first_name , " " , 
c.last_name ) as Name, r.staff_id as Branch
from rental as r join inventory as i on r.inventory_id = i.inventory_id
join customer as c on c.customer_id = r.customer_id 
join film as f on f.film_id = i.film_id
where r.rental_id = 1; 

