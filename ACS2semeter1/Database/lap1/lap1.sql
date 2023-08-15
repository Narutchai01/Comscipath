create table themepark (
park_code varchar(10)  primary key,
park_name varchar(35) not null,
park_city varchar(50) not null,
park_country char(2) not null
);

create table employee(
emp_num numeric(4)  primary key,
emp_title varchar(4),
emp_lanme varchar(15) not null,
emp_fname varchar(15) not null,
emp_dob date not null,
emp_haire_date date not null,
emp_areacode varchar(4) not null,
emp_phone varchar(12) not null,
park_code varchar(10) not null,
foreign key(park_code) references themepark(park_code)
);

create table ticket (
ticket_no numeric(10) primary key,
ticket_price numeric(4,2) not null,
ticket_type varchar(10) not null,
park_code varchar(10) not null,
foreign key (park_code) references themepark(park_code)
);

create table attraction (
attract_no numeric(10) primary key,
park_code varchar(10) not null,
attract_name varchar(35) not null,
attract_age numeric(3) default 0,
attract_capacity numeric(3) not null
);


create table hour (
emp_num numeric(4) ,
attract_no numeric(10) ,
hour_per_attract numeric(2) not null,
hour_rate numeric(4,2) not null,
date_worked date not null,
foreign key(emp_num) references employee(emp_num),
foreign key(attract_no) references attraction(attract_no)
);

create table sales (
transaction_no numeric(10) primary key,
park_code varchar(10) not null,
sale_date date not null,
foreign key (park_code) references themepark(park_code)
);

create table salesline (
transaction_no numeric(10),
line_no numeric(2) not null,
ticket_no numeric(10) not null,
line_qty numeric(4) not null,
line_price numeric(9,2) not null,
foreign key (transaction_no) references sales(transaction_no),
foreign key (ticket_no) references ticket(ticket_no)
);

