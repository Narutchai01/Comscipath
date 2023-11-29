-- 1
create table student (
	StudentID bigint primary key,
    FirstName varchar(69) not null,
    LastName varchar(69) not null
);

create table problem (
	ProblemID int primary key,
    Date timestamp not null,
    DueDate datetime not null,
    Difficulity varchar(69),
    Description longtext
);

create table score (
	StudentID bigint,
    ProblemID int,
    Score int,
    SubmitDate timestamp not null,
    primary key (StudentID, ProblemID),
    foreign key (StudentID) references student(StudentID),
    foreign key (ProblemID) references problem(ProblemID)
);

-- 2
insert into student values (65090500401, 'Somsak', 'Jaidee');
insert into student values (65090500402, 'Pomchorp', 'Peesud');

insert into problem
values (000001, current_timestamp(), '2023-11-30', 'easy', 'lorem lipsum fuck ypuit hard daday');
insert into problem
values (000002, current_timestamp(), '2023-12-1', 'hard', 'lorem lipsum fuck ypuit hard daday');

insert into score values (65090500401, 000001, 69, current_timestamp());
insert into score values (65090500402, 000002, 96, current_timestamp());
insert into score values (65090500401, 000002, 9, current_timestamp());
insert into score values (65090500402, 000001, 6, current_timestamp());


-- 3
DELIMITER //
CREATE PROCEDURE GetTotalScore(IN studentID bigint)
BEGIN
    select sum(score) from score s where s.studentID = studentID;
END //
DELIMITER ;


-- 4
create index scoreIDX on score(StudentID, ProblemID);

-- 5
create or replace view leaderBoard as
select studentID, firstName, lastName, sum(score) as sumScore from student join score using (studentID) 
group by studentID order by sumScore desc;

select * from leaderBoard;

-- 6
alter table problem add subjectID varchar(69) not null;
select * from problem;
update problem set subjectID = 'CSS199' where ProblemID = 1;
update problem set subjectID = 'CSS888' where ProblemID = 2;
   
select firstName, lastName, score, subjectID from student join score using (studentId) 
join problem using (problemID)
where (subjectID, score) in
(select subjectID, max(score) score from
problem join score using (problemID)
group by subjectID);