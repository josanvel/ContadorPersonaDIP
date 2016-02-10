
####################################   PROCEDURE   DIAS  ###########################################
######### Procedure GetBarrasDias #########
DROP Procedure PRGetGraficaDias;
delimiter //
CREATE PROCEDURE PRGetGraficaDias
		(IN Fecha_Inicio DATETIME,
		 IN Fecha_Final DATETIME) BEGIN
         
SELECT	p.Estado AS Estado, 
		COUNT(1) AS Contador
FROM Persons p 
WHERE CAST(p.FechaActual AS DATE)
		BETWEEN Fecha_Inicio AND Fecha_Final
GROUP BY p.Estado;
END //
delimiter ;
call PRGetGraficaDias('2001-01-01','2001-02-10');
call PRGetGraficaDias('2001-12-23','2001-12-23');

######### Procedure PRGetGraficaDiasEntra #########
DROP Procedure PRGetGraficaDiasEntra;
delimiter //
CREATE PROCEDURE PRGetGraficaDiasEntra
		(IN Dia_Inicio DATETIME,
		 IN Dia_Final DATETIME) BEGIN
         
SELECT 	t.mes AS mes,
        ifnull(contador, 0) as ContadorMes,
        CONCAT(t.anio,'/', t.mes)AS dia
FROM(	SELECT anio, mes
		FROM 	(SELECT YEAR(Dia_Inicio) anio ) years,
				(SELECT 1 mes UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
				UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
				UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
	)  AS t
LEFT JOIN	(	SELECT 	YEAR(p.FechaActual) AS Anio, 
						MONTH(p.FechaActual) as Mes, 
						COUNT(*) AS contador,
						p.FechaActual AS FechaActual
				FROM persons p
				WHERE Estado like "Entra"
				AND CAST(p.FechaActual AS DATE) BETWEEN Dia_Inicio AND Dia_Final
				GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
				ORDER BY Anio DESC, Mes ASC
			) AS Pers
ON t.Mes = Pers.mes
GROUP BY dia
ORDER BY t.Mes ASC, t.anio;
END //
delimiter ;
call PRGetGraficaDiasEntra('2001-01-01','2001-02-10');
call PRGetGraficaDiasEntra('2001-12-23','2001-12-23');

######### Procedure PRGetGraficaDiasSale #########
DROP Procedure PRGetGraficaDiasSale;
delimiter //
CREATE PROCEDURE PRGetGraficaDiasSale
		(IN Dia_Inicio DATETIME,
		 IN Dia_Final DATETIME) BEGIN
         
SELECT 	t.mes AS mes,
        ifnull(contador, 0) as ContadorMes,
        CONCAT(t.anio,'/', t.mes)AS dia
FROM(	SELECT anio, mes
		FROM 	(SELECT YEAR(Dia_Inicio) anio ) years,
				(SELECT 1 mes UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
				UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
				UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
	)  AS t
LEFT JOIN	(	SELECT 	YEAR(p.FechaActual) AS Anio, 
						MONTH(p.FechaActual) as Mes, 
						COUNT(*) AS contador,
						p.FechaActual AS FechaActual
				FROM persons p
				WHERE Estado like "Sale"
				AND CAST(p.FechaActual AS DATE) BETWEEN Dia_Inicio AND Dia_Final
				GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
				ORDER BY Anio DESC, Mes ASC
			) AS Pers
ON t.Mes = Pers.mes
GROUP BY dia
ORDER BY t.Mes ASC, t.anio;
END //
delimiter ;
call PRGetGraficaDiasSale('2001-01-01','2002-08-10');
call PRGetGraficaDiasSale('2001-12-23','2001-12-23');


####################################   PROCEDURE   ANIO  ###########################################
######### Procedure PRGetGraficaAnioEntra #########
DROP Procedure PRGetGraficaAnioEntra;
delimiter //
CREATE PROCEDURE PRGetGraficaAnioEntra
		(IN Anio_Query INTEGER) BEGIN
        
SELECT	tabla.mes AS mes,
        ifnull(contador, 0) as ContadorMes
FROM (	SELECT anio, mes
		FROM(SELECT Anio_Query anio) years,
			(SELECT 1 mes UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
			UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
			UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
	)	AS tabla
LEFT JOIN (	SELECT 	YEAR(p.FechaActual) AS Anio, 
					MONTH(p.FechaActual) as Mes, 
					COUNT(*) AS contador
			FROM persons p
			WHERE Estado like "Entra"
            AND YEAR(p.FechaActual)=Anio_Query
			GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
			ORDER BY Anio DESC, Mes ASC
		   ) AS Pers
ON tabla.Mes = Pers.mes
GROUP BY tabla.mes;
END //
delimiter ;
call PRGetGraficaAnioEntra(2001);

######### Procedure PRGetGraficaAnioSale #########
DROP Procedure PRGetGraficaAnioSale;
delimiter //
CREATE PROCEDURE PRGetGraficaAnioSale
		(IN Anio_Query INTEGER) BEGIN
        
SELECT	tabla.mes AS mes,
        ifnull(contador, 0) as ContadorMes
FROM (	SELECT anio, mes
		FROM(SELECT Anio_Query anio) years,
			(SELECT 1 mes UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
			UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
			UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
	)	AS tabla
LEFT JOIN (	SELECT 	YEAR(p.FechaActual) AS Anio, 
					MONTH(p.FechaActual) as Mes, 
					COUNT(*) AS contador
			FROM persons p
			WHERE Estado like "Sale"
            AND YEAR(p.FechaActual)=Anio_Query
			GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
			ORDER BY Anio DESC, Mes ASC
		   ) AS Pers
ON tabla.Mes = Pers.mes
GROUP BY tabla.mes;
END //
delimiter ;
call PRGetGraficaAnioSale(2001);

######### Procedure PRGetGraficaAnioEntraSale #########
DROP Procedure PRGetGraficaAnioEntraSale;
delimiter //
CREATE PROCEDURE PRGetGraficaAnioEntraSale
		(IN Anio INTEGER) BEGIN
        
SELECT n.Estado AS Estado,
		ifnull(contador, 0) AS ContadorMes
FROM(	SELECT Estado
		FROM(SELECT 'Entra' Estado UNION ALL SELECT 'Sale') Sate
	) AS n
LEFT JOIN(	SELECT 	p.Estado AS Estado,
					COUNT(*) AS Contador
			FROM (	SELECT 	p.FechaActual as Fecha,
							p.Estado as Estado
					FROM Persons as p
					WHERE YEAR(p.FechaActual) = Anio) as p
			GROUP BY p.Estado
		) AS Pers
ON n.Estado like Pers.Estado
GROUP BY n.Estado;
END //
delimiter ;
call PRGetGraficaAnioEntraSale(2001);


####################################   PROCEDURE   MESES  ###########################################
######### Procedure GetBarrasDias #########
DROP Procedure PRGetGraficaMesesEntra;
delimiter //
CREATE PROCEDURE PRGetGraficaMesesEntra
		(IN Mes_Inicio DATETIME,
		 IN Mes_Final DATETIME) BEGIN
         
SELECT CONCAT(YEAR(Pers.Fecha),'/', MONTH(Pers.Fecha))AS dia,
		ifnull(contador, 0) as ContadorMes
FROM(	select	YEAR(p.FechaActual) AS Anio, 
						MONTH(p.FechaActual) as Mes, 
						COUNT(*) AS contador,
                        p.FechaActual as Fecha
				from persons as p
				where YEAR(FechaActual) between YEAR(Mes_Inicio) AND YEAR (Mes_Final)
				AND Estado like "Entra"
				GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
				ORDER BY Anio ASC, Mes ASC
			) AS Pers;
END //
delimiter ;
call PRGetGraficaMesesEntra('2001-01-01', '2016-05-01');

######### Procedure GetBarrasDias #########
DROP Procedure PRGetGraficaMesesSale;
delimiter //
CREATE PROCEDURE PRGetGraficaMesesSale
		(IN Mes_Inicio DATETIME,
		 IN Mes_Final DATETIME) BEGIN
         
SELECT CONCAT(YEAR(Pers.Fecha),'/', MONTH(Pers.Fecha))AS dia,
		ifnull(contador, 0) as ContadorMes
FROM(	select	YEAR(p.FechaActual) AS Anio, 
						MONTH(p.FechaActual) as Mes, 
						COUNT(*) AS contador,
                        p.FechaActual as Fecha
				from persons as p
				where YEAR(FechaActual) between YEAR(Mes_Inicio) AND YEAR (Mes_Final)
				AND Estado like "Sale"
				GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
				ORDER BY Anio ASC, Mes ASC
			) AS Pers;
END //
delimiter ;
call PRGetGraficaMesesSale('2001-01-01', '2016-05-01');
   
######### Procedure GetBarrasDias #########
DROP Procedure PRGetGraficaMeses;
delimiter //
CREATE PROCEDURE PRGetGraficaMeses
		(IN Mes_Inicio DATETIME,
		 IN Mes_Final DATETIME) BEGIN
         
SELECT 	Pers.Estado,
		ifnull(contador, 0) as Contador       
FROM(	select	YEAR(p.FechaActual) AS Anio, 
						MONTH(p.FechaActual) as Mes, 
						COUNT(*) AS contador,
                        p.FechaActual as Fecha,
                        p.Estado
				from persons as p
				where YEAR(FechaActual) between YEAR(Mes_Inicio) AND YEAR (Mes_Final)
				GROUP BY Estado
				
			) AS Pers;
END //
delimiter ;
call PRGetGraficaDias('2001-12-23','2001-12-23');