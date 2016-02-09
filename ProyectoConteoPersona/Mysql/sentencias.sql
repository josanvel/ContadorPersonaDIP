#####Query para mostrar cuabtas personas ENTRA en una fecha especifica
select p.Estado, COUNT(1) AS Contador,   CAST(FechaActual AS DATE) as Fecha
from Persons p  where Estado LIKE "Entra" and FechaActual BETWEEN '2016-01-01'AND'2016-01-28'
GROUP BY p.Estado, FechaActual ;

#####Query para mostrar cuabtas personas SALE en una fecha especifica
select Estado, COUNT(*) AS Contador,   CAST(FechaActual AS DATE) as Fecha
from Persons 
where FechaActual BETWEEN '2016-01-01'AND'2016-01-28'
GROUP BY Fecha ;

SELECT p.Estado, COUNT(1) AS Contador, 
	CAST(FechaActual AS DATE) AS Fecha
FROM Persons p  
WHERE p.FechaActual
	BETWEEN '2001-01-01' AND '2016-01-28'
GROUP BY p.Estado, Fecha ;

SELECT p.FechaActual as Fecha,
		p.Estado as Estado
FROM Persons as p
WHERE YEAR(p.FechaActual) = 2001;

SELECT p.Estado AS Estado,
		COUNT(*) AS Contador
FROM (SELECT p.FechaActual as Fecha,
		p.Estado as Estado
FROM Persons as p
WHERE YEAR(p.FechaActual) = 2001) as p
GROUP BY p.Estado;


SELECT p.Estado, COUNT(1) AS Contador 
FROM Persons p  
WHERE p.Estado like "Entra"
GROUP BY p.Estado;

SELECT COUNT(1)  
FROM Persons p   
WHERE YEAR(p.FechaActual) = 2001  
GROUP BY MONTH(p.FechaActual);


SELECT YEAR(per.Fecha) as Anio,
		COUNT(1)
FROM (	SELECT p.FechaActual as Fecha,
		p.Estado as Estado
		FROM Persons as p
		WHERE YEAR(p.FechaActual) = 2001)  as per
GROUP BY EXTRACT(MONTH FROM per.Fecha);


SELECT Month(per.Fecha) as Mes, count(per.Estado) as ContadorMes
FROM (	SELECT p.FechaActual as Fecha,
		p.Estado as Estado
		FROM Persons as p
		WHERE p.Estado like "Sale"
        AND YEAR(p.FechaActual) = 2001
	) as per
GROUP BY Month(per.Fecha);


select * From persons;


SELECT p.Estado, COUNT(1) AS Contador FROM Persons p GROUP BY p.Estado;


select P.IdPerson, IFNULL(A.Contador, 0) 
FROM 
		(SELECT persons.IdPerson
		FROM persons) P
LEFT JOIN 
		(select IdPerson, count(*) as Contador
		FROM persons 
		group by Estado) A
ON P.IdPerson = A.IdPerson;



select *,IFNULL(A.ContadorMes, 0) 
FROM (select * from persons WHERE Estado like "Sale") as P
LEFT JOIN 
		(SELECT per.IdPerson as IdPersona,
				Month(per.Fecha) as Mes,
                count(per.Estado) as ContadorMes
		FROM (	SELECT p.IdPerson as IdPerson,
						p.FechaActual as Fecha,
						p.Estado as Estado
				FROM Persons as p
				WHERE #p.Estado like "Sale" AND
				YEAR(p.FechaActual) = 2001
			) as per
		WHERE per.Estado like "Sale"
		GROUP BY Month(per.Fecha)
        ) A
ON P.IdPerson = A.IdPersona
WHERE Estado like "Sale"
GROUP BY A.Mes;


SELECT * FROM persons;

SELECT YEAR(FechaActual) as year_val, 
		MONTH(FechaActual) as month_val,
        IFNULL(COUNT(*), null) as total
FROM persons
WHERE Estado like "Sale"
GROUP BY YEAR(FechaActual), MONTH(FechaActual);

SELECT DATE_FORMAT(FechaActual, '%Y') as 'year',
DATE_FORMAT(FechaActual, '%m') as 'month',
IFNULL(COUNT(IdPerson), null) as total
FROM persons
WHERE Estado like "Sale"
GROUP BY DATE_FORMAT(FechaActual, '%Y%m');

SELECT COUNT(*) num, SUBSTR(ts, 1, 7) month
FROM persons
JOIN (SELECT Estado, (FechaActual) ts FROM persons
      GROUP BY YEAR(FechaActual),Month(FechaActual)) mm
ON persons.FechaActual = mm.ts
WHERE mm.Estado like "Sale"
GROUP BY SUBSTR(ts, 1, 7),
mm.Estado like "Sale";


SELECT y, m, count(*)
FROM (
		SELECT y, m
		FROM
			(SELECT YEAR("2002-01-01") y UNION ALL SELECT YEAR("2002-01-01")-1) years,
			(SELECT 1 m UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
			UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
			UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months) ym
		LEFT JOIN persons
		ON ym.y = YEAR(FROM_UNIXTIME(persons.FechaActual))
		AND ym.m = MONTH(FROM_UNIXTIME(persons.FechaActual))
		WHERE (y=YEAR("2001-01-01") AND m<=MONTH("2001-01-01"))
		OR (y<YEAR(CURDATE()) AND m>MONTH(CURDATE())
	)
GROUP BY y, m;

SELECT YEAR(FechaActual) as year_val, 
		MONTH(FechaActual) as month_val,
        IFNULL(COUNT(*), null) as total,
        persons.Estado 
FROM 	(
			SELECT y, m
			FROM
				(select YEAR("2001-01-01") y) years,
				(SELECT 1 m UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
				UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
				UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
		) ym
LEFT JOIN persons
	ON ym.y = YEAR((persons.FechaActual))  
    AND ym.m = MONTH((persons.FechaActual))
WHERE  persons.Estado like "Sale"
GROUP BY y, m;





SELECT YEAR(`FechaActual`) AS Year, MONTH(`FechaActual`) as Month, COUNT(*) AS Count
FROM persons
WHERE Estado like "Sale"
GROUP BY YEAR(`FechaActual`), MONTHNAME(`FechaActual`)
ORDER BY Year DESC, Month DESC;

Select * from persons;

#####################    Contador SAle Por Año   #####################
SELECT	tabla.mes AS mes,
        ifnull(contador, 0) as ContadorMes # contador, Anio, Mes
FROM (
	SELECT anio, mes
			FROM
				(select 2001 anio) years,
				(SELECT 1 mes UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4
				UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8
				UNION ALL SELECT 9 UNION ALL SELECT 10 UNION ALL SELECT 11 UNION ALL SELECT 12) months
	) AS tabla
LEFT JOIN (
	SELECT 	YEAR(p.FechaActual) AS Anio, 
			MONTH(p.FechaActual) as Mes, 
            COUNT(*) AS contador
	FROM persons p
	WHERE Estado like "Entra"
	GROUP BY YEAR(p.FechaActual), MONTHNAME(p.FechaActual)
	ORDER BY Anio DESC, Mes ASC
) AS Pers
ON tabla.Mes = Pers.mes
GROUP BY tabla.mes;
