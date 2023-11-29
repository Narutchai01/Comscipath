use sakila;

-- 1
select name ,
	case 
		when name in ("English","Italian","French","German") then "latin1"
        when name in ("Japanese","Mandarin") then "utf8"
        else "Unknow"
	end character_set
from language;
    
-- 2
select sum(
	case
		when rating = "G" then 1
        else 0
	end
) G_Count ,
sum(
	case
		when rating = "PG" then 1
        else 0
	end
) PG_Count ,
sum(
	case
		when rating = "PG-13" then 1
        else 0
	end
) PG13_Count , 
sum(
	case
		when rating = "R" then 1
        else 0
	end
) R_Count ,
sum(
	case
		when rating = "NC-17" then 1
        else 0
	end
) NC17_Count
from film;

-- 3
select table_name , index_name 
from information_schema.statistics
where index_schema = "sakila" 
order by table_name;

-- 4

alter table customer add index <index_name> (<column_list>) where table_schema = "sakila"; 
