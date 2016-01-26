CREATE DATABASE db_prueba;
use db_prueba;

CREATE TABLE Persons
(
IdPerson int PRIMARY KEY AUTO_INCREMENT,
FechaActual DATETIME NOT NULL DEFAULT NOW(),
Estado ENUM('Entra','Sale'), 
pathPersona varchar(255) NOT NULL
);

INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img1");
SELECT * FROM Persons;

DROP TABLE Persons;