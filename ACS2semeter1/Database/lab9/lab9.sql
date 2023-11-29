use sakila;

-- 1

create view customer_view as
select * from customer;

update customer_view set email = "*****";

select * from customer_view;

-- 2

create view category_sale as
select name Category, monthname(rental_date) Month , 
year(rental_date) Year , sum(payment.amount) Total_Amount
from category join film_category using (category_id) 
join film using (film_id) join inventory using (film_id) 
join rental using (inventory_id) join payment using (rental_id)
group by category_id ,  name, monthname(rental_date), year(rental_date) ;

select * from category_sale;

-- 3

create view month_film as
select film_id , title Title , name  Category, 
count(distinct film_actor.actor_id) total_actor , 
sum(inventory_id) total_copies, count(rental.rental_id) total_rent
from film join film_actor using(film_id)
join inventory using (film_id) join rental using (inventory_id) 
join film_category using (film_id) join category using (category_id)
group by film_id , title , category.name order by film_id;

select * from month_film;

