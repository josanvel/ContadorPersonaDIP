CREATE DATABASE db_prueba;
use db_prueba;

CREATE TABLE Persons(
IdPerson int PRIMARY KEY AUTO_INCREMENT,
FechaActual DATETIME NOT NULL DEFAULT NOW(),
Estado ENUM('Entra','Sale'), 
pathPersona varchar(255) NOT NULL
);

INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen1.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen2.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen3.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen4.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen5.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen6.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen7.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen8.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen9.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen10.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen11.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen12.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen13.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen14.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen15.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen16.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen17.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen18.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen19.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen20.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen21.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen22.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen23.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen24.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen25.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen26.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen27.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen28.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen29.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen30.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen31.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen32.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen33.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen34.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen35.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen36.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen37.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen38.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen39.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen40.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen41.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen42.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen43.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen44.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen45.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen46.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen47.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen48.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen49.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen50.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen51.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen52.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen53.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen54.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen55.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen56.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen57.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen58.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen59.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen60.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen61.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen62.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen63.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen64.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Sale","C:/opencv/img/imagen65.jpg");
INSERT INTO Persons (Estado, pathPersona) VALUES("Entra","C:/opencv/img/imagen66.jpg");



UPDATE Persons SET FechaActual='2015-1-23 09:14:10' WHERE IdPerson=1;
UPDATE Persons SET FechaActual='2015-1-23 09:14:10' WHERE IdPerson=2;
UPDATE Persons SET FechaActual='2015-2-23 09:14:10' WHERE IdPerson=3;
UPDATE Persons SET FechaActual='2015-2-23 09:14:10' WHERE IdPerson=4;
UPDATE Persons SET FechaActual='2015-2-23 09:14:10' WHERE IdPerson=5;
UPDATE Persons SET FechaActual='2015-3-23 09:14:10' WHERE IdPerson=6;
UPDATE Persons SET FechaActual='2015-3-23 09:14:10' WHERE IdPerson=7;
UPDATE Persons SET FechaActual='2015-4-23 09:14:10' WHERE IdPerson=8;
UPDATE Persons SET FechaActual='2015-4-23 09:14:10' WHERE IdPerson=9;
UPDATE Persons SET FechaActual='2015-5-23 09:14:10' WHERE IdPerson=10;
UPDATE Persons SET FechaActual='2015-5-23 09:14:10' WHERE IdPerson=11;
UPDATE Persons SET FechaActual='2015-5-23 09:14:10' WHERE IdPerson=12;
UPDATE Persons SET FechaActual='2015-5-23 09:14:10' WHERE IdPerson=13;
UPDATE Persons SET FechaActual='2014-1-23 09:14:10' WHERE IdPerson=14;
UPDATE Persons SET FechaActual='2014-1-23 09:14:10' WHERE IdPerson=15;
UPDATE Persons SET FechaActual='2014-1-23 09:14:10' WHERE IdPerson=16;
UPDATE Persons SET FechaActual='2014-1-23 09:14:10' WHERE IdPerson=17;
UPDATE Persons SET FechaActual='2014-1-23 09:14:10' WHERE IdPerson=18;
UPDATE Persons SET FechaActual='2014-2-23 09:14:10' WHERE IdPerson=19;
UPDATE Persons SET FechaActual='2014-2-23 09:14:10' WHERE IdPerson=20;
UPDATE Persons SET FechaActual='2014-2-23 09:14:10' WHERE IdPerson=21;
UPDATE Persons SET FechaActual='2014-2-23 09:14:10' WHERE IdPerson=22;
UPDATE Persons SET FechaActual='2014-3-23 09:14:10' WHERE IdPerson=23;
UPDATE Persons SET FechaActual='2014-3-23 09:14:10' WHERE IdPerson=24;
UPDATE Persons SET FechaActual='2014-4-23 09:14:10' WHERE IdPerson=25;
UPDATE Persons SET FechaActual='2015-6-23 09:14:10' WHERE IdPerson=26;
UPDATE Persons SET FechaActual='2015-6-23 09:14:10' WHERE IdPerson=27;
UPDATE Persons SET FechaActual='2015-7-23 09:14:10' WHERE IdPerson=28;
UPDATE Persons SET FechaActual='2015-7-23 09:14:10' WHERE IdPerson=29;
UPDATE Persons SET FechaActual='2015-7-23 09:14:10' WHERE IdPerson=30;
UPDATE Persons SET FechaActual='2015-8-23 09:14:10' WHERE IdPerson=31;
UPDATE Persons SET FechaActual='2015-9-23 09:14:10' WHERE IdPerson=32;
UPDATE Persons SET FechaActual='2015-9-23 09:14:10' WHERE IdPerson=33;
UPDATE Persons SET FechaActual='2015-10-23 09:14:10' WHERE IdPerson=34;
UPDATE Persons SET FechaActual='2015-10-23 09:14:10' WHERE IdPerson=35;
UPDATE Persons SET FechaActual='2015-10-23 09:14:10' WHERE IdPerson=36;
UPDATE Persons SET FechaActual='2015-11-23 09:14:10' WHERE IdPerson=37;
UPDATE Persons SET FechaActual='2015-11-23 09:14:10' WHERE IdPerson=38;
UPDATE Persons SET FechaActual='2015-11-23 09:14:10' WHERE IdPerson=39;
UPDATE Persons SET FechaActual='2015-12-23 09:14:10' WHERE IdPerson=40;
UPDATE Persons SET FechaActual='2015-12-23 09:14:10' WHERE IdPerson=41;
UPDATE Persons SET FechaActual='2015-12-23 09:14:10' WHERE IdPerson=42;
UPDATE Persons SET FechaActual='2015-12-23 09:14:10' WHERE IdPerson=43;
UPDATE Persons SET FechaActual='2015-12-23 09:14:10' WHERE IdPerson=44;
UPDATE Persons SET FechaActual='2014-5-23 09:14:10' WHERE IdPerson=45;
UPDATE Persons SET FechaActual='2014-5-23 09:14:10' WHERE IdPerson=46;
UPDATE Persons SET FechaActual='2014-5-23 09:14:10' WHERE IdPerson=47;
UPDATE Persons SET FechaActual='2014-5-23 09:14:10' WHERE IdPerson=48;
UPDATE Persons SET FechaActual='2014-6-23 09:14:10' WHERE IdPerson=49;
UPDATE Persons SET FechaActual='2014-6-23 09:14:10' WHERE IdPerson=50;
UPDATE Persons SET FechaActual='2014-6-23 09:14:10' WHERE IdPerson=51;
UPDATE Persons SET FechaActual='2014-6-23 09:14:10' WHERE IdPerson=52;
UPDATE Persons SET FechaActual='2014-7-23 09:14:10' WHERE IdPerson=53;
UPDATE Persons SET FechaActual='2014-7-23 09:14:10' WHERE IdPerson=54;
UPDATE Persons SET FechaActual='2014-8-23 09:14:10' WHERE IdPerson=55;
UPDATE Persons SET FechaActual='2014-8-23 09:14:10' WHERE IdPerson=56;
UPDATE Persons SET FechaActual='2014-8-23 09:14:10' WHERE IdPerson=57;
UPDATE Persons SET FechaActual='2014-9-23 09:14:10' WHERE IdPerson=58;
UPDATE Persons SET FechaActual='2014-9-23 09:14:10' WHERE IdPerson=59;
UPDATE Persons SET FechaActual='2014-10-23 09:14:10' WHERE IdPerson=60;
UPDATE Persons SET FechaActual='2014-10-23 09:14:10' WHERE IdPerson=61;
UPDATE Persons SET FechaActual='2014-11-23 09:14:10' WHERE IdPerson=62;
UPDATE Persons SET FechaActual='2014-12-23 09:14:10' WHERE IdPerson=63;
UPDATE Persons SET FechaActual='2014-12-23 09:14:10' WHERE IdPerson=64;
UPDATE Persons SET FechaActual='2014-12-23 09:14:10' WHERE IdPerson=65;
UPDATE Persons SET FechaActual='2014-12-23 09:14:10' WHERE IdPerson=66;




UPDATE Persons SET Estado='Sale' WHERE IdPerson=1;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=2;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=3;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=4;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=5;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=6;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=7;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=8;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=9;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=10;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=11;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=12;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=13;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=14;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=15;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=16;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=17;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=18;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=19;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=20;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=21;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=22;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=23;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=24;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=25;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=26;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=27;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=28;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=29;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=30;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=31;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=32;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=33;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=34;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=35;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=36;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=37;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=38;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=39;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=40;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=41;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=42;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=43;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=44;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=45;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=46;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=47;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=48;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=49;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=50;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=51;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=52;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=53;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=54;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=55;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=56;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=57;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=58;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=59;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=60;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=61;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=62;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=63;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=64;
UPDATE Persons SET Estado='Entra' WHERE IdPerson=65;
UPDATE Persons SET Estado='Sale' WHERE IdPerson=66;
