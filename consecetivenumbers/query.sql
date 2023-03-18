SELECT num AS 'ConsecutiveNums'
FROM(
	SELECT num,
	CASE
		WHEN num = LAG(num) OVER (ORDER BY id) AND num = LAG(num, 2) OVER (ORDER BY id) THEN num
		END AS ConsecutiveNums
		FROM Logs
	) t
WHERE ConsecutiveNums IS NOT NULL;
