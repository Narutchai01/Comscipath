use sakila;

select sum(amount) from payment where amount > 10.99;

select payment_id, payment_date, amount from payment where amount != 0.99;

select * from address where address2 != null ;

select title,length from film where length < 60 or length> 100;

select distinct rental_duration from film;

select * from film where length between 60 and 100;

select city from city where city like 'g%' or '%z%';

select actor_id ,first_name,last_name from actor where last_name = 'Williams' or last_name = 'Davis';

select *,rental_duration*rental_rate as rental_price from film order by rental_price desc;
