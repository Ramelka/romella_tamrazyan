-- DROP DATABASE Library;
CREATE DATABASE Library;
USE Library;
 
 CREATE TABLE Authors (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Authors_Name VARCHAR(20),
    Authors_Surname VARCHAR(60)
 );
 
 CREATE TABLE Publisher (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    `Name` VARCHAR(30)
 );
 
 CREATE TABLE Books (
    Books_Id INT AUTO_INCREMENT PRIMARY KEY,
    Title VARCHAR(200),
    Pub_Date DATE,
    Authors_Id INT,
    Publisher_Id INT,
    CONSTRAINT FK_books_authors FOREIGN KEY(Authors_Id ) REFERENCES Authors(Id),
    CONSTRAINT FK_books_publisher FOREIGN KEY (Publisher_Id) REFERENCES Publisher(Id)
 );
 
 CREATE TABLE Subscribers (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    `Name` VARCHAR(30),
    Surname VARCHAR(50),
    Birthdate DATE,
    Address VARCHAR(255)
 );
 
 CREATE TABLE Book_Subscriber (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Subscriber_Id INT,
    Book_Id INT,
    Taken_Date DATE,
    Returned_Date DATE,
    Deadline DATE,
    CONSTRAINT FK_books_subscribers_Subscribers FOREIGN KEY(Subscriber_Id) REFERENCES Subscribers(Id),
    CONSTRAINT FK_books_Subscribers FOREIGN KEY(Book_Id) REFERENCES Books(Books_Id)
 );
 
 CREATE TABLE Book_inventory (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Book_Id INT,
    Subscriber_Id INT,
    `Condition` VARCHAR(50),
    `Status` VARCHAR(50),
    CONSTRAINT FK_inventory_book FOREIGN KEY (Book_Id) REFERENCES Books(Books_Id),
    CONSTRAINT FK_inventory_subscriber FOREIGN KEY(Subscriber_Id) REFERENCES Book_Subscriber(Id)
);
 
INSERT INTO Authors (Authors_Name, Authors_Surname)
VALUES 
    ('Lewis', 'Carrol'),
    ('Jane', 'Austen'),
    ('Jules', 'Verne'),
    ('Ernest', 'Hemingway'),
    ('William', 'Shakespeare'),
    ('Robin', 'Sharma');
    
-- select *
-- from Authors
-- where Authors_Name LIKE 'wi%';
 
INSERT INTO Publisher (`Name`)
VALUES
    ('Le Temps'),
    ('Create Space'),
    ('Dover Publications'),
    ('Amazon Classics');
    
INSERT INTO Books (Title, Pub_Date, Authors_Id, Publisher_Id) 
values 
    ('As you like it', '1998-06-18', 5, 3),
    ('Around the World in Eighty Days', '2017-11-21', 3, 4),
    ('Pride and Prejudice', '1871-11-04', 2, 1),
    ('The leader who had no title', '2010-03-07', 6, 2),
    ('Winners take nothing', '1922-07-06', 4, 2),
    ('Alice in Wonderland', '1801-04-16', 1, 1);
    
INSERT INTO Subscribers (`Name`, Surname, Birthdate, Address)
VALUES
	('James', 'Willson', '1998-06-17', 'London'),
	('Tom', 'Smith', '1997-12-18', 'Manchester'),
	('Nancy', 'Lewis', '1997-04-1', 'Wells'),
	('Jessica', 'Walker', '1990-06-27', 'Liverpool'),
	('Liza', 'Owen', '1979-06-15', 'Linkoln'),
	('Steven', 'Holmes', '2008-06-07', 'Bristol'),
	('Sandra', 'Chapman', '2001-03-7', 'Oxford');
 
INSERT INTO Book_Subscriber (Subscriber_Id, Book_Id, Taken_Date, Returned_Date, Deadline )
VALUES
	(1 , 1, '2022-04-18', '2022-05-22', '2022-04-18'),
	(2 , 2, '2022-04-18', '2022-04-21', '2022-05-18'),
	(3 , 3, '2022-04-18', '2022-04-27', '2022-05-18'),
	(4 , 4, '2022-04-18', '2022-04-22', '2022-05-18'),
	(5 , 5, '2022-04-18', '2022-04-22', '2022-05-18'),
	(6 , 4, '2022-04-18', '2022-05-22', '2022-04-18'),
	(7 , 4, '2022-04-18', NULL, '2022-05-18');

INSERT INTO Book_inventory (Book_Id, Subscriber_Id, `Condition`, `Status`)
VALUES 
	(2, 4, 'perfect', 'available'),
	(6, 2, 'torn', 'not available'),
	(3, 5, 'torn', 'not available'),
	(1, 5, 'shabby', 'on repair'),
	(1, 3, 'torn', 'on repair'),
	(2, 1, 'perfect', 'not available'),
	(6, 5, 'shabby', 'on repair'),
	(4, 1, 'perfect', 'not available'),
	(3, 5, 'shabby', 'on repair'),
	(2, 1, 'perfect', 'available'),
	(4, 4, 'torn', 'on repair'),
	(5, 3, 'shabby', 'available'),
	(5, 5, 'perfect', 'available');

select * from Book_inventory;

ALTER TABLE Book_inventory 
DROP CONSTRAINT FK_inventory_subscriber;
ALTER TABLE Book_inventory 
DROP COLUMN Subscriber_Id;
 
 -- select * from Book_inventory;
 
ALTER TABLE Book_Subscriber
ADD COLUMN book_inventory_id INT ;
ALTER TABLE Book_Subscriber 
ADD FOREIGN KEY (book_inventory_id) REFERENCES Book_inventory(Id);
 
-- select * from Book_Subscriber;

-- Adding users column for Book_Subscriber table
CREATE TABLE Users (
	Id INT AUTO_INCREMENT PRIMARY KEY,
	User_Name VARCHAR(100),
    User_Surname VARCHAR(100)
);

INSERT INTO Users (User_Name,User_Surname)
VALUES
	('Rozy', 'Brain'),
	('John', 'Klark'),
	('Jenifer', 'James'),
	('Nick', 'Smith') ;
    
-- Adding Users_Id column for Book_Subscriber and reference to Id(Users table)
ALTER TABLE Book_Subscriber
ADD COLUMN User_id INT;

ALTER TABLE Book_Subscriber 
ADD FOREIGN KEY (User_id) REFERENCES Users(Id);

INSERT INTO Book_Subscriber(User_id)
VALUES 
	('1'),
	('3'),
	('1'),
	('2'),
	('4');

-- select * from Book_Subscriber;

-- View 1
CREATE VIEW Book_List AS
SELECT s.`Name`, s.Surname, b.Title, u.User_Name, u.User_Surname
FROM Subscribers s, Books b, Users u, Book_Subscriber bs
WHERE bs.Subscriber_Id = s.Id AND
	  bs.Book_Id = b.Books_Id AND
      bs.User_id = u.Id;
      
-- select * from Book_List;

-- View 2
CREATE VIEW Books_On_Repair AS
SELECT a.Title
FROM Books a, Book_inventory b
WHERE b.`Status` = 'on repair' AND
	  b.Book_Id = a.Books_Id;

-- select * from Books_On_Repair;

-- Query 1
SELECT Books_On_Repair.Title, COUNT(*) FROM Books_On_Repair
GROUP BY Title;
	  
-- Query 2
SELECT s.`Name`, s.Surname, bs.Taken_Date, bs.Returned_Date, bs.Deadline
FROM Subscribers s, Book_Subscriber bs
WHERE bs.Subscriber_Id = s.Id AND
	  bs.Deadline < curdate() AND
      bs.Returned_Date IS NULL;