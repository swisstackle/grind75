SELECT COALESCE(
	(SELECT salary 
		FROM Employee 
		WHERE salary <> (SELECT salary FROM Employee ORDER BY salary DESC LIMIT 1)
		ORDER BY salary DESC 
		LIMIT 1),
	null
) AS SecondHighestSalary;
