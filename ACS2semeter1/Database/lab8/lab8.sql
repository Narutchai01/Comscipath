use sakila;

-- 1
alter table rental 
add constraint -- input_name
foreign key (customer_id)
references customer(customer_id)
on delete restrict;

-- 2
create index index_pay on payment (customer_id,amount,payment_date);